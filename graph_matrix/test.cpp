/*Utwórz graf skierowany złożony z 10 wierzchołków Wypisz, ile jest wierzchołków
Wypisz, ile jest krawędzi
v= SelectVertex(2);
Wypisz unikalny Numer v
Nadaj v wagę unikalnyNumer*UniklanyNumer; Wypisz wagę v
AddEdge(1,2); AddEdge(1,2); AddEdge(2,3); AddEdge(3,4); AddEdge(9,9);
Wypisz, ile jest wierzchołków Wypisz, ile jest krawędzi
Wypisz, czy istnieje krawędź (1,1) Wypisz, czy istnieje krawędź (1,2) Wypisz, czy istnieje krawędź (2,1)
 */


#include <iostream>
#include "graph.cpp"

using namespace std;

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

int main(void){
    GraphAsMatrix notDirectedGraph(10,true);
    GraphAsMatrix directedGraph(10,false);

    cout << "\nTesty dla skierowanego\n";
    cout << "============================\n\n";

    cout << "Ilośc wierzchołków: " << notDirectedGraph.NumberOfVertices() << endl;
    cout << "Ilosc krawedzi: " << notDirectedGraph.NumberOfEdges() << endl;

    Vertex* v = notDirectedGraph.SelectVertex(2);
    int id = v->getNumber();
    cout << "Unikalny numer: " << id << endl;

    v->weight = id*id;
    cout << "Waga: " << v->weight << endl;

    notDirectedGraph.AddEdge(1,2);
    notDirectedGraph.AddEdge(1,2);
    notDirectedGraph.AddEdge(2,3);
    notDirectedGraph.AddEdge(3,4);
    notDirectedGraph.AddEdge(9,9);

    cout << "Ilosc wierzchołkow: " << notDirectedGraph.NumberOfVertices() << endl;
    cout << "Ilosc krawedzi: " << notDirectedGraph.NumberOfEdges() << endl;
    cout << "Czy istnieje (1,1): " << notDirectedGraph.IsEdge(1,1) << endl;
    cout << "Czy istnieje (1,2): " << notDirectedGraph.IsEdge(1,2) << endl;
    cout << "Czy istnieje (2,1): " << notDirectedGraph.IsEdge(2,1) << endl;

    vector<Edge*> krawedzie = {notDirectedGraph.SelectEdge(1,2),notDirectedGraph.SelectEdge(2,3),notDirectedGraph.SelectEdge(3,4),notDirectedGraph.SelectEdge(9,9)};
    notDirectedGraph.SelectEdge(1,2);
    testKrawedzie(krawedzie);


    cout << "\nTesty dla nieskierowanego\n";
    cout << "============================\n\n";

    cout << "Ilośc wierzchołków: " << directedGraph.NumberOfVertices() << endl;
    cout << "Ilosc krawedzi: " << directedGraph.NumberOfEdges() << endl;

    Vertex* v_skierowane = directedGraph.SelectVertex(2);
    int id_skierowane = v_skierowane->getNumber();
    cout << "Unikalny numer: " << id_skierowane << endl;

    v_skierowane->weight = id_skierowane*id_skierowane;
    cout << "Waga: " << v_skierowane->weight << endl;

    directedGraph.AddEdge(1,2);
    directedGraph.AddEdge(1,2);
    directedGraph.AddEdge(2,3);
    directedGraph.AddEdge(3,4);
    directedGraph.AddEdge(9,9);

    cout << "Ilosc wierzchołkow: " << directedGraph.NumberOfVertices() << endl;
    cout << "Ilosc krawedzi: " << directedGraph.NumberOfEdges() << endl;
    cout << "Czy istnieje (1,1): " << directedGraph.IsEdge(1,1) << endl;
    cout << "Czy istnieje (1,2): " << directedGraph.IsEdge(1,2) << endl;
    cout << "Czy istnieje (2,1): " << directedGraph.IsEdge(2,1) << endl;

    vector<Edge*> krawedzie1 = {directedGraph.SelectEdge(1,2),directedGraph.SelectEdge(2,3),directedGraph.SelectEdge(3,4),directedGraph.SelectEdge(9,9)};
    directedGraph.SelectEdge(1,2);
    testKrawedzie(krawedzie1);
}