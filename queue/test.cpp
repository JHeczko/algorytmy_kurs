#include <iostream>
#include "queueCykliczna.cpp"

using namespace queueCykliczna;
using namespace std;

int main(){
    QueueCykl kolejka(4);
    
    cout <<"Is empty:"<< kolejka.isEmpty() << endl;
    
    for(int i = 0; i<10; i++){
        cout << "ENQUEU: "<< kolejka.enqueue(i) << endl;
    }
    
    cout <<"Is empty:"<< kolejka.isEmpty() << endl;
    cout << "Front element: " << kolejka.front() << endl;
    for(int i = 0; i<10; i++){
        cout << "DEQUEUE:"<<kolejka.dequeue() << endl;
        cout << "TEST1) Front element: " << kolejka.front() << endl;
    }
    
    cout <<"Is empty:"<< kolejka.isEmpty() << endl;
    
    for(int i = 0; i<10; i++){
        cout << "ENQUEU: "<< kolejka.enqueue(i+20) << endl;
        cout << "TEST2) Front element: " << kolejka.front() << endl;
    }

    kolejka.makenull();

    cout << "Is null after clear?: " << kolejka.isEmpty() << endl;

}