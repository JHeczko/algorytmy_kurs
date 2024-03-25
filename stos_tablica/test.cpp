#include "stack.cpp"
#include <iostream>

using namespace std;
using namespace stackArray;

// Empty()
// Push(5)
// Top_Elem()
// Empty()
// Pop()
// Empty()
// Push(2)
// Push(3)
// TopElem()
// Makenull()
// Empty()

int main(){
    Stack stack(20);
    cout << "Is empty?:" << stack.empty()<< endl;
    stack.push(5);
    cout << "Top element:" << stack.top_element()<< endl;
    cout << "Is empty?:" << stack.empty()<< endl;
    stack.pop();
    cout << "Is empty?:" << stack.empty() << endl;
    stack.push(2);
    stack.push(3);
    cout << "Top element:" << stack.top_element() << endl;
    stack.make_null();
    cout <<"Is empty?:" << stack.empty()<< endl;
}