#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#include <iostream>
#include "graph.cpp"

using namespace std;

void rozpinajaceTest(GraphAsMatrix& graph) {
    if(graph.IsDirected()){
        cout << ANSI_COLOR_GREEN <<"\nSkierowany\n" << ANSI_COLOR_RESET;
        cout << "-------------------------\n\n";
    }else{
        cout << ANSI_COLOR_GREEN <<"\nNieskierowany\n" << ANSI_COLOR_RESET;
        cout << "-------------------------\n\n";
    }
    graph.MakeNull();
    graph.AddEdge(0, 1);
    graph.AddEdge(1, 2);
    graph.AddEdge(2, 3);
    graph.AddEdge(3, 4);
    graph.AddEdge(3, 7);
    graph.AddEdge(4, 5);
    graph.AddEdge(5, 9);
    graph.AddEdge(9, 9);
    graph.AddEdge(6, 8);
    graph.AddEdge(8, 6);
    graph.AddEdge(0, 8);

    graph.AddEdge(3, 9);
    graph.AddEdge(5, 7);
    graph.AddEdge(9, 8);

    GraphAsMatrix rozpinajacyGraph = graph.DFS_Spanning_Tree(graph.SelectVertex(0));
    Iterator<Edge>& it = rozpinajacyGraph.EdgesIter();

    cout << "Krawędzie drzewa rozpinajacego graf:\n";


    while(!it.IsDone()){
        cout << (*it).GetV0()->getNumber() << " i " << (*it).GetV1()->getNumber() << endl;
        ++it;
    }
}

void spojnoscTest(GraphAsMatrix& graph){
    if(graph.IsDirected()){
        cout << ANSI_COLOR_GREEN <<"\nSkierowany\n" << ANSI_COLOR_RESET;
        cout << "-------------------------\n\n";
    }else{
        cout << ANSI_COLOR_GREEN <<"\nNieskierowany\n" << ANSI_COLOR_RESET;
        cout << "-------------------------\n\n";
    }

    graph.MakeNull();
    graph.AddEdge(0,1);
    graph.AddEdge(1,2);
    graph.AddEdge(2,3);
    graph.AddEdge(3,4);
    graph.AddEdge(3,7);
    graph.AddEdge(4,5);
    graph.AddEdge(5,9);
    graph.AddEdge(9,9);
    graph.AddEdge(6,8);
    graph.AddEdge(8,6);
    graph.AddEdge(0,8);

    graph.AddEdge(9,0);
    graph.AddEdge(6,0);
    graph.AddEdge(7,0);

    cout << graph.isConnected() << endl;
}

void dfsVisitatorTest(GraphAsMatrix& graph){
    if(graph.IsDirected()){
        cout << ANSI_COLOR_GREEN <<"\nSkierowany\n" << ANSI_COLOR_RESET;
        cout << "-------------------------\n\n";
    }else{
        cout << ANSI_COLOR_GREEN <<"\nNieskierowany\n" << ANSI_COLOR_RESET;
        cout << "-------------------------\n\n";
    }
    CountingVisitator visitator;
    graph.DFSCount(graph.SelectVertex(0), visitator);
    cout << "Visitator count: " << visitator.getCount() << endl;
    visitator.reset();
}

void dfsTest(GraphAsMatrix& graph){

    if(graph.IsDirected()){
        cout << ANSI_COLOR_GREEN <<"\nSkierowany\n" << ANSI_COLOR_RESET;
        cout << "-------------------------\n\n";
    }else{
        cout << ANSI_COLOR_GREEN <<"\nNieskierowany\n" << ANSI_COLOR_RESET;
        cout << "-------------------------\n\n";
    }
    graph.MakeNull();
    graph.AddEdge(0,1);
    graph.AddEdge(1,2);
    graph.AddEdge(2,3);
    graph.AddEdge(3,4);
    graph.AddEdge(3,7);
    graph.AddEdge(4,5);
    graph.AddEdge(5,9);
    graph.AddEdge(9,9);
    graph.AddEdge(6,8);
    graph.AddEdge(8,6);
    graph.AddEdge(0,8);
    graph.DFS(graph.SelectVertex(0));
}

void testIteratory(GraphAsMatrix& graph){
    if(graph.IsDirected()){
        cout << ANSI_COLOR_GREEN <<"\nSkierowany\n" << ANSI_COLOR_RESET;
        cout << "-------------------------\n\n";
    }else{
        cout << ANSI_COLOR_GREEN <<"\nNieskierowany\n" << ANSI_COLOR_RESET;
        cout << "-------------------------\n\n";
    }

    cout << "Wierczholki: \n" << ANSI_COLOR_RESET;
    Iterator<Vertex>& it1 = graph.VerticesIter();
    while(!it1.IsDone()){
        cout << "Numer: " << (*it1).getNumber() << " oraz waga: " << (*it1).weight << endl;
        ++it1;
    }
    cout << endl;

    graph.AddEdge(3,5);
    graph.AddEdge(8,3);
    graph.AddEdge(5,2);


    cout << "Krawędzie:\n" << ANSI_COLOR_RESET;
    Iterator<Edge>& it2 = graph.EdgesIter();
    while(!it2.IsDone()){
        cout << (*it2).GetV0()->getNumber() << " i " << (*it2).GetV1()->getNumber() << endl;
        ++it2;
    }

    cout <<"Krawędzie wychadzace z 3:\n" << ANSI_COLOR_RESET;
    Iterator<Edge>& it3 = graph.EmanatingEdgesIter(3);
    while(!it3.IsDone()){
        cout << (*it3).GetV0()->getNumber() << " i " << (*it3).GetV1()->getNumber() << endl;
        ++it3;
    }

    cout << "Krawędzie wchodzace do 2:\n" << ANSI_COLOR_RESET;
    Iterator<Edge>& it4 = graph.IncidentEdgesIter(2);
    while(!it4.IsDone()){
        cout << (*it4).GetV0()->getNumber() << " i " << (*it4).GetV1()->getNumber() << endl;
        ++it4;
    }
}

void testKrawedzie(vector<Edge *>& array){
    for(Edge* e : array){
        cout << "----------------------------\n";
        cout << "Test dla krawędzi o numerach(" << e->GetV0()->getNumber() << "," << e->GetV1()->getNumber() <<")\n";
        cout << "V0: " << e->GetV0()->getNumber() << "\nV1: " << e->GetV1()->getNumber() << endl;
        Vertex* mateV0 = e->Mate(e->GetV0());
        Vertex* mateV1 = e->Mate(e->GetV1());
        cout << "Mate dla V0: " << mateV0->getNumber() << "\nMate dla V1: " << mateV1->getNumber() << endl;
        e->weight = mateV1->getNumber()+mateV0->getNumber();
        cout << "Waga krawędzi e: " << e->weight << endl;
    }
    cout << "----------------------------\n";
}

void testGrafOgol(GraphAsMatrix& graph){
    if(graph.IsDirected()){
        cout << ANSI_COLOR_GREEN <<"\nSkierowany\n" << ANSI_COLOR_RESET;
        cout << "-------------------------\n\n";
    }else{
        cout << ANSI_COLOR_GREEN <<"\nNieskierowany\n" << ANSI_COLOR_RESET;
        cout << "-------------------------\n\n";
    }
    cout << "Ilośc wierzchołków: " << graph.NumberOfVertices() << endl;
    cout << "Ilosc krawedzi: " << graph.NumberOfEdges() << endl;

    Vertex* v = graph.SelectVertex(2);
    int id = v->getNumber();
    cout << "Unikalny numer: " << id << endl;

    v->weight = id*id;
    cout << "Waga: " << v->weight << endl;

    graph.AddEdge(1,2);
    graph.AddEdge(1,2);
    graph.AddEdge(2,3);
    graph.AddEdge(3,4);
    graph.AddEdge(9,9);

    cout << "Ilosc wierzchołkow: " << graph.NumberOfVertices() << endl;
    cout << "Ilosc krawedzi: " << graph.NumberOfEdges() << endl;
    cout << "Czy istnieje (1,1): " << graph.IsEdge(1,1) << endl;
    cout << "Czy istnieje (1,2): " << graph.IsEdge(1,2) << endl;
    cout << "Czy istnieje (2,1): " << graph.IsEdge(2,1) << endl;
    cout << "Czy istnieje (3,4): " << graph.IsEdge(3,4) << endl;

    vector<Edge*> krawedzie = {graph.SelectEdge(1,2),graph.SelectEdge(2,3),graph.SelectEdge(3,4),graph.SelectEdge(9,9)};
    graph.SelectEdge(1,2);
    testKrawedzie(krawedzie);
}

int main(void){
    GraphAsMatrix notDirectedGraph(10,false);
    GraphAsMatrix directedGraph(10,true);


    cout << ANSI_COLOR_BLUE<< "\nTesty dla grafów ogół\n" << ANSI_COLOR_RESET;
    cout << ANSI_COLOR_GREEN<< "============================\n\n" << ANSI_COLOR_RESET;
    testGrafOgol(notDirectedGraph);
    testGrafOgol(directedGraph);


    cout << ANSI_COLOR_MAGENTA<< "\nTesty dla iteratorów\n" << ANSI_COLOR_RESET;
    cout << ANSI_COLOR_GREEN<< "============================\n\n" << ANSI_COLOR_RESET;
    testIteratory(notDirectedGraph);
    testIteratory(directedGraph);


    cout << ANSI_COLOR_CYAN<< "\nTesty dla DFS\n" << ANSI_COLOR_RESET;
    cout << ANSI_COLOR_GREEN<< "============================\n\n" << ANSI_COLOR_RESET;
    dfsTest(notDirectedGraph);
    dfsTest(directedGraph);


    cout << ANSI_COLOR_RED<< "\nTesty dla Visitator DFS\n" << ANSI_COLOR_RESET;
    cout << ANSI_COLOR_GREEN<< "============================\n\n" << ANSI_COLOR_RESET;
    dfsVisitatorTest(notDirectedGraph);
    dfsVisitatorTest(directedGraph);


    cout << ANSI_COLOR_CYAN << "\nTesty dla sprawdzania skierowan\n" << ANSI_COLOR_RESET;
    cout << ANSI_COLOR_GREEN << "============================\n\n" << ANSI_COLOR_RESET;
    spojnoscTest(notDirectedGraph);
    spojnoscTest(directedGraph);


    cout << ANSI_COLOR_MAGENTA << "\nTesty dla sprawdzania skierowan\n" << ANSI_COLOR_RESET;
    cout << ANSI_COLOR_GREEN << "============================\n\n" << ANSI_COLOR_RESET;
    rozpinajaceTest(notDirectedGraph);
    rozpinajaceTest(directedGraph);

}

