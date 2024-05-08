#include "graph.cpp"
#include "partition.cpp"
#include <random>

class Labirynt{
private:
    GraphAsMatrix* graphBase;
    GraphAsMatrix* labirynt;
    int wiersze;
    int kolumny;

    int randomInt(int max){
        srand(time(0));

        int random_number = rand()%max;
        return random_number;
    }

    GraphAsMatrix* kruskalAlgorithm(GraphAsMatrix& graph){
        // Kopia tego grafu na gorze
        GraphAsMatrix* g = (new GraphAsMatrix(graph.NumberOfVertices(), graph.IsDirected()));


        Iterator<Edge>& itEdge = graph.EdgesIter();
        std::vector<Edge> kolejka;
        while(!itEdge.IsDone()){
            kolejka.push_back((*itEdge));
            ++itEdge;
        }
        int max = kolejka.size();


        //stworzenie jednoelementowych zbiorów dla alg Kruskala
        Partition partition(graph.NumberOfVertices());


        while(kolejka.size() != 0 && partition.size() > 1){
            int randonNumber = randomInt(max);
            Edge& e = kolejka.at(randonNumber);
            max--;
            //std::cout << (kolejka.begin()+randonNumber)->GetV0()->getNumber() << std::endl;

            Vertex* v0 = e.GetV0();
            Vertex* v1 = e.GetV1();
            SetAsArray s = partition.findSet(v0);
            SetAsArray t = partition.findSet(v1);
            //std::cout << "Iteracja" << v0->getNumber() << " " << v1->getNumber() <<" " << randonNumber << std::endl;
            if(!(s==t)){
                partition.join(s,t);
                g->AddEdge(v0->getNumber(), v1->getNumber());
            }
            kolejka.erase(kolejka.begin()+randonNumber);
            //std::cout << kolejka.size() << " " << partition.size() << std::endl;
        }
        return g;
    }
public:
    Labirynt(int wiersze, int kolumny){
        graphBase = new GraphAsMatrix(wiersze*kolumny, false);
        labirynt = nullptr;
        this->kolumny = kolumny;
        this->wiersze = wiersze;
        for(int i = 0; i < kolumny; i++){
            for(int j = 0; j < wiersze; j++){
                //generowanie pionowych kresek w siatce
                if(kolumny*(j+1)+i < kolumny*wiersze){
                    graphBase->AddEdge(kolumny*j+i, kolumny*(j+1)+i);
                }
                if(i != kolumny-1){
                    graphBase->AddEdge(kolumny*j+i, (kolumny*j+i)+1);
                }
            }
        }
    }

    void generateRandomLabirynt(){
        labirynt = kruskalAlgorithm(*graphBase);
    }

    void visualizeLab(){
        for (int y = 0; y < wiersze; ++y) {
            if(y == 0) {
                for (int x = 0; x < kolumny-1; ++x) {
                    std::cout << "+---"; // rysuj górne krawędzie komórek
                }
                std::cout << "+   "; //tutaj wyjscie/wejscie
                std::cout << "+" << std::endl;
            }else{// logika generowania
                for (int x = 0; x < kolumny; ++x) {
                    if(labirynt->IsEdge((y*kolumny)+x,((y-1)*kolumny)+x)){
                        std::cout << "+   ";
                    }else {
                        std::cout << "+---";
                    }
                }
                std::cout << "+" << std::endl;
            }

            for (int x = 0; x < kolumny; ++x) {
                if(x == 0) {
                    std::cout << "|   "; // rysuj boczne ściany komórek
                }else{// logika generowania
                    if( labirynt->IsEdge((y*kolumny)+x,(y*kolumny)+(x-1) ) ){
                        std::cout << "    ";
                    }else {
                        std::cout << "|   ";
                    }
                }
            }
            std::cout << "|" << std::endl;
        }

        // Rysowanie dolnej krawędzi kratki
        std::cout << "+   "; // tutaj wyjscie/wejscie
        for (int x = 1; x < kolumny; ++x) {
            std::cout << "+---"; // rysuj górne krawędzie komórek
        }
        std::cout << "+" << std::endl;
    }

    void printEdgesBase(){
        Iterator<Edge>& it = graphBase->EdgesIter();
        std::cout << "Base\n";
        while(!it.IsDone()){
            std::cout << (*it).GetV0()->getNumber() << " i " << (*it).GetV1()->getNumber() << std::endl;
            ++it;
        }
    }

    void printEdgesLab(){
        Iterator<Edge>& it = labirynt->EdgesIter();
        std::cout << "Labirynt\n";
        while(!it.IsDone()){
            std::cout << (*it).GetV0()->getNumber() << " i " << (*it).GetV1()->getNumber() << std::endl;
            ++it;
        }
    }

    ~Labirynt(){
        delete graphBase;
        if(labirynt != nullptr){
            delete labirynt;
        }
    }
};
