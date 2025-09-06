#pragma once

#include <string>
#include <iostream>

template <typename T>
class Iterator {
public:
    virtual ~Iterator() {;}
    Iterator() {;}
    virtual bool IsDone() = 0;
    virtual T & operator * () = 0;
    virtual void operator ++ () = 0;
};

class Vertex {
    int number;
public:
    int weight;
    std::string label;
    Vertex(int number){
        this->number = number;
    };
    Vertex(int number, int weight){
        this->number = number;
        this->weight = weight;
    };
    Vertex(int number, int weight, std::string label){
        this->number = number;
        this->weight = weight;
        this->label = label;
    };

    int getNumber() const{
        return number;
    };
};

class Edge {
protected:
    Vertex* v0;
    Vertex* v1;
public:
    int weight;
    std::string label;

    Edge (Vertex *v0, Vertex* v1){
        this->v0 = v0;
        this->v1 = v1;
    };
    Edge (Vertex *v0, Vertex* v1, int weight){
        this->v0 = v0;
        this->v1 = v1;
        this->weight = weight;
    };
    Edge (Vertex *v0, Vertex* v1, int weight, std::string label){
        this->v0 = v0;
        this->v1 = v1;
        this->weight = weight;
        this->label = label;
    };

    Vertex* GetV0 (){return v0;};
    Vertex* GetV1 (){return v1;};
    Vertex* Mate (Vertex *v){
        if(v == v0){
            return v1;
        }else if(v==v1){
            return v0;
        }else{
            return nullptr;
        }
    };
};

class GraphAsMatrix
{
private:
    std::vector<Vertex *> vertices;
    std::vector< std::vector<Edge *> > adjacencyMatrix; // macierz sasiedztwa
    bool isDirected; // skierowany czy nie
    int numberOfVertices; // wierzcholki
    int numberOfEdges; // krawedzie

    class AllVerticesIter: public virtual Iterator<Vertex>{
    private:
        GraphAsMatrix& owner;
        int current;
     public:
        AllVerticesIter(GraphAsMatrix &owner) : owner(owner){
            this->current = 0;
        };
        bool IsDone(){
            if(current == owner.numberOfVertices){
                return true;
            }else{
                return false;
            }
        };
        Vertex & operator*(){
            return *(owner.SelectVertex(current));
        };
        void operator++(){
            current++;
        };
    };
    class AllEdgesIter: public Iterator<Edge>{
    private:
        GraphAsMatrix & owner;
        int row;
        int col;
        int offset;
     public:
        void next(){
            if(owner.isDirected){
                col++;
                for (int i = row; i < owner.numberOfVertices; i++) {
                    for (; col < owner.numberOfVertices; col++) {
                       //std::cout << "i: " << i << " j:" << col << std::endl;
                        if (owner.IsEdge(i, col)) {
                            row = i;
                           //std::cout << "Git" << row << col << std::endl;
                            return;
                        }
                    }
                    col = 0;
                }
               // std::cout << "End\n";
                this->row = owner.numberOfVertices;
                this->col = owner.numberOfVertices;
            }else{
                col++;
                for (int i = row; i < owner.numberOfVertices; i++) {
                    for (; col < owner.numberOfVertices; col++) {
                        //std::cout << "i: " << i << " j:" << col << std::endl;
                        if (owner.IsEdge(i, col)) {
                            row = i;
                            //std::cout << "Git" << row << col << std::endl;
                            return;
                        }
                    }
                    offset++;
                    col = offset;
                }
                //std::cout << "End\n";
                this->row = owner.numberOfVertices;
                this->col = owner.numberOfVertices;
            }
        };
        AllEdgesIter(GraphAsMatrix& owner):owner(owner){
            row = 0;
            col = 0;
            offset = 0;
            for(int i = row; i < owner.numberOfVertices; ++i){
                for(int j = col; j < owner.numberOfVertices; ++j){
                    if(owner.adjacencyMatrix[i][j] != nullptr){
                        this->row = i;
                        this->col = j;
                        return;
                    }
                }
                offset++;
            }
            this->row = owner.numberOfVertices;
            this->col = owner.numberOfVertices;
        };
        bool IsDone(){
            if((row == owner.numberOfVertices) && (col == owner.numberOfVertices)) {
                return true;
            }else{
                return false;
            }
        };
        Edge& operator*(){
            //std::cout<< "\ttutaj: " << row << " tutaj:" << col << std::endl;
            return *(owner.adjacencyMatrix[row][col]);
        };
        void operator++(){next();}
    };
    class EmanEdgesIter: public Iterator<Edge>
     {
     private:
         GraphAsMatrix & owner;
         int row;
         int col;
     public:
         void next(){
             for(int i = col+1; i < owner.numberOfVertices; ++i){
                 if(owner.adjacencyMatrix[row][i] != nullptr){
                     col = i;
                     return;
                 }
             }
             col = owner.numberOfVertices;
         };
         EmanEdgesIter(GraphAsMatrix &owner,int v):owner(owner){
             this->row = v;
             this->col = 0;
             for(int i = col; i < owner.numberOfVertices; ++i){
                 if(owner.adjacencyMatrix[row][i] != nullptr){
                     col = i;
                     return;
                 }
             }
             col = owner.numberOfVertices;
         };
         bool IsDone(){
             if(col == owner.numberOfVertices){
                return true;
             }else{
                 return false;
             }
         };
         Edge & operator*(){
            return *owner.adjacencyMatrix[row][col];
         };
         void  operator++(){next();}
    };
    class InciEdgesIter: public Iterator<Edge>
    {
    private:
         GraphAsMatrix & owner;
         int row;
         int col;
    public:
        void next(){
            for(int i = row+1; i < owner.numberOfVertices; ++i){
                if(owner.adjacencyMatrix[i][col] != nullptr){
                    row = i;
                    return;
                }
            }
            row = owner.numberOfVertices;
        };
        InciEdgesIter(GraphAsMatrix &owner,int v):owner(owner){
            this->col = v;
            this->row = 0;
            for(int i = row; i < owner.numberOfVertices; ++i){
                if(owner.adjacencyMatrix[i][col] != nullptr){
                    row = i;
                    return;
                }
            }
            row = owner.numberOfVertices;
        };
        bool IsDone(){
            if(row == owner.numberOfVertices){
                return true;
            }else{
                return false;
            }
        };
        Edge & operator*(){
            return *owner.adjacencyMatrix[row][col];
        };
        void  operator++(){next();}
    };

    //metoda pomocnicza
    void DFS1(Vertex* v, std::vector<bool>& visitedArray){
        std::cout << "Wierzchołek nr. " << v->getNumber() << std::endl;
        visitedArray[v->getNumber()] = true;

        Iterator<Edge>& it = this->EmanatingEdgesIter(v->getNumber());
        Iterator<Edge>& it2 = this->IncidentEdgesIter(v->getNumber());

        while(!it.IsDone()){
            int num = (*it).GetV1()->getNumber();
            int num2 = (*it).GetV0()->getNumber();
            //std::cout << num << " " << num2 << std::endl;
            if(visitedArray[num] == false){
                DFS1((*it).GetV1(),visitedArray);
            }
            if(visitedArray[num2] == false){
                DFS1((*it).GetV0(),visitedArray);
            }
            ++it;
        }
        while(!it2.IsDone()){
            int num = (*it2).GetV1()->getNumber();
            int num2 = (*it2).GetV0()->getNumber();
            //std::cout << num << " " << num2 << std::endl;
            if(visitedArray[num] == false){
                DFS1((*it2).GetV1(),visitedArray);
            }
            if(visitedArray[num2] == false){
                DFS1((*it2).GetV0(),visitedArray);
            }
            ++it2;
        }
    }

public:
    std::string name;

    GraphAsMatrix (int numberOFVerticies, bool isDirected){
        if(isDirected){
            this->name = "Directed";
        }else{
            this->name = "NotDirected";
        }
        this->numberOfVertices = numberOFVerticies;
        this->isDirected = isDirected;
        this->numberOfEdges = 0;
        this->vertices = *(new std::vector<Vertex *>(numberOFVerticies, nullptr));
        for(int i = 0; i < numberOFVerticies; i++){
            vertices[i] = new Vertex(i);
        }
        this->adjacencyMatrix = *(new std::vector<std::vector<Edge *> >());
        for(int i = 0 ; i < numberOFVerticies; i++){
            std::vector<Edge *> tmp(numberOFVerticies, nullptr);
            adjacencyMatrix.push_back(tmp);
        }
    };

    //metoda głowna
    void DFS(Vertex* v){
        std::vector<bool> vec(numberOfVertices, false);
        DFS1(v,vec);
        for(int i = 0; i < numberOfVertices; i++){
            if(!vec[i]){
                DFS1(this->SelectVertex(i),vec);
            }
        }
    }

    int NumberOfVertices(){
        return this->numberOfVertices;
    };

    bool IsDirected(){
        return this->isDirected;
    };

    int NumberOfEdges(){
        return this->numberOfEdges;
    };

    bool IsEdge(int u, int v){
        if(adjacencyMatrix[u][v] != nullptr){
            return true;
        }
        return false;
    };

    int getNumberOfEdges(){
        return numberOfEdges;
    }

    void MakeNull(){
        this->numberOfEdges = 0;
        for(int i = 0; i < numberOfVertices; i++){
            Vertex tmp(i);
            this->vertices.push_back(&tmp);
        }
        for(int i = 0 ; i < this->numberOfVertices; i++){
            std::vector<Edge *> tmp(this->numberOfVertices, nullptr);
            this->adjacencyMatrix.push_back(tmp);
        }
    };

    Edge * SelectEdge (int u, int v){
        if(u >= numberOfVertices || v >= numberOfVertices){
            std::cerr << "Out of range of verticies in selectedge\n";
            return nullptr;
        }

        if(adjacencyMatrix[u][v] != nullptr){
            return adjacencyMatrix[u][v];
        }else{
            return nullptr;
        }

    };

    Vertex * SelectVertex(int v){
        if(v >= numberOfVertices){
            std::cerr << "Out of range of verticies in selectedge\n";
            return nullptr;
        }
        return vertices[v];
    };

    void AddEdge (int u, int v){
        if(u >= numberOfVertices || v >= numberOfVertices){
            std::cerr << "Out of range of verticies in add\n";
            return;
        }
        Vertex* v0 = SelectVertex(u);
        Vertex* v1 = SelectVertex(v);
        if(adjacencyMatrix[u][v] != nullptr){
            return;
        }
        if(isDirected){ // directed
            adjacencyMatrix[u][v] = new Edge(v0, v1);
            numberOfEdges++;
        }else{ // not directed
            Edge* buf = new Edge(v0,v1);
            adjacencyMatrix[u][v] = buf;
            adjacencyMatrix[v][u] = buf;
            numberOfEdges++;
        }
        }

    Iterator<Vertex> & VerticesIter(){
        return *(new AllVerticesIter(*this));
    };

    Iterator<Edge> & EdgesIter(){
        return *(new AllEdgesIter(*this));
    };

    Iterator<Edge> & EmanatingEdgesIter(int v){
        return *(new EmanEdgesIter(*this,v));
    };

    Iterator<Edge> & IncidentEdgesIter(int v){
        return *(new InciEdgesIter(*this,v));
    };

    ~GraphAsMatrix(){
        for(int i = 0; i<numberOfVertices;i++){
            for(int j = 0; j < numberOfVertices; j++){
                if(adjacencyMatrix[i][j] != nullptr) {
                    delete adjacencyMatrix[i][j];
                }
            }
        }
    }

};

