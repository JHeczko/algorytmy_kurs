#include <iostream>
#include "kolejka.cpp"
#include <unistd.h>

using namespace std;
using namespace bh;

int main(){
    BinaryHeap<int>* random = new BinaryHeap<int>(2, "Random");
    BinaryHeap<int>* notRandom = new BinaryHeap<int>(2, "NotRandom");

    cout <<random->IsEmpty() << endl;

    for(int i = 0; i < 10; i++){
        random->Enqueue(rand()%20);
    }
    random->wypisz();
    random->DequeueMin();
    random->wypisz();

    cout << random->IsEmpty() << endl;

    for(int i = 0; i < 10; i++){
        notRandom->Enqueue(i);
    }
    notRandom->wypisz();
    notRandom->DequeueMin();
    notRandom->wypisz();
}