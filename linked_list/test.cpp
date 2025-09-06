#include "linked_list.cpp"

using namespace linkedListNamespace;
using namespace std;

int main(){
    linkedList list;

    list.insert(5,list.first());

    cout << list.retrieve(list.locate(5)) << endl;

    list.insert(2,list.first());

    list.print();

    list.insert(1, list.next(list.first()));

    list.print();

    list.insert(100, list.end());

    list.print();

    list.remove(list.previous(list.locate(100)));

    cout << list.remove(list.previous(list.end()));

    list.print();

    list.clear();

    list.print();
    

}