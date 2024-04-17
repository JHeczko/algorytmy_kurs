#pragma once

#include <string>
#include <iostream>

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
/* class AllVerticesIter: public Iterator<Vertex>
 {
     GraphAsMatrix & owner;
     int current;
     public:
     AllVerticesIter(GraphAsMatrix &owner)
     bool IsDone();
     Vertex & operator*();
     void  operator++();
};
 class AllEdgesIter: public Iterator<Edge>
 {
     GraphAsMatrix & owner;
     int row;
     int col;
     public:
     void next()
     AllEdgesIter(GraphAsMatrix &owner);
     bool IsDone();
     Edge & operator*();
     void  operator++(){next();}
};
class EmanEdgesIter: public Iterator<Edge>
 {
     GraphAsMatrix & owner;
     int row;
     int col;
     public:
     void next()
     EmanEdgesIter(GraphAsMatrix &owner,int v);
     bool IsDone();
     Edge & operator*();
     void  operator++(){next();}
};
class InciEdgesIter: public Iterator<Edge>
 {
     GraphAsMatrix & owner;
     int row;
     int col;
     public:
std::vector<Vertex *> vertices;
std::vector< std::vector<Edge *> > adjacencyMatrix;
bool isDirected;
int numberOfVertices;
int numberOfEdges=0;
1
void next()
     InciEdgesIter(GraphAsMatrix &owner,int v);
     bool IsDone();
     Edge & operator*();
     void  operator++(){next();}
};*/
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
            adjacencyMatrix[u][v] = new Edge(v0, v1);
            adjacencyMatrix[v][u] = new Edge(v1, v0);
            numberOfEdges++;
        }
        }
    /*  Iterator<Vertex> & VerticesIter();
        Iterator<Edge> & EdgesIter();
        Iterator<Edge> & EmanatingEdgesIter(int v);
        Iterator<Edge> & IncidentEdgesIter(int v);
    */
};

