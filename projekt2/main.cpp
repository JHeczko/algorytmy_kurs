#include "graph.cpp"
#include "kolejka.cpp"
#include "set.cpp"
#include "partition.cpp"

using namespace bh;
using namespace std;
using namespace set_namespace;


GraphAsMatrix& kruskalAlgorithm(GraphAsMatrix& graph){
    // Kopia tego grafu na gorze
    GraphAsMatrix& g = *(new GraphAsMatrix(graph.NumberOfVertices(), graph.IsDirected()));

    // TODO mechanika losowania
    Iterator<Edge>& itEdge = graph.EdgesIter();
    vector<Edge> kolejka;
    while(!itEdge.IsDone()){
        kolejka.push_back((*itEdge));
        ++itEdge;
    }

    //stworzenie jednoelementowych zbiorów dla alg Kruskala
    Partition partition(graph.NumberOfVertices());


    while(kolejka.size() != 0 && partition.size() > 1){
        Edge& e = kolejka.at(kolejka.size()-1);
        kolejka.pop_back();
        Vertex* v0 = e.GetV0();
        Vertex* v1 = e.GetV1();
        SetAsArray s = partition.findSet(v0);
        SetAsArray t = partition.findSet(v1);
        if(!(s==t)){
            partition.join(s,t);
            g.AddEdge(v0->getNumber(), v1->getNumber());
        }
    }
    return g;
}


int main(void){
//    Partition part(10);
//    part.Wypisz();
//    Vertex* v0 = new Vertex(7);
//    Vertex* v1 = new Vertex(5);
//    Vertex* v2 = new Vertex(8);
//    SetAsArray& t = part.findSet(v0);
//    SetAsArray& s = part.findSet(v1);
//    t.wypisz();
//    s.wypisz();
//    if(!(s==t)){
//        part.join(t,s);
//    }
//    part.Wypisz();
//
//    SetAsArray f = part.findSet(v0);
//    SetAsArray g = part.findSet(v2);
//
//    part.join(f,g);
//
//    part.Wypisz();


    GraphAsMatrix g(12,false);
    g.AddEdge(0,1);
    g.AddEdge(1,2);
    g.AddEdge(2,3);
    g.AddEdge(3,4);
    g.AddEdge(4,5);
    g.AddEdge(6,7);
    g.AddEdge(6,8);
    g.AddEdge(5,8);
    g.AddEdge(8,9);
    g.AddEdge(1,10);
    g.AddEdge(10,11);
    g.AddEdge(10,11);
    g.AddEdge(7,5);
    g.AddEdge(8,7);
    g.AddEdge(3,8);
    g.AddEdge(1,8);
    g.AddEdge(2,3);

    GraphAsMatrix& newGraph = kruskalAlgorithm(g);

    cout << "Krawędzie:\n" << newGraph.getNumberOfEdges() << endl;
    Iterator<Edge>& it2 = newGraph.EdgesIter();
    while(!it2.IsDone()){
        cout << (*it2).GetV0()->getNumber() << " i " << (*it2).GetV1()->getNumber() << endl;
        ++it2;
    }
}