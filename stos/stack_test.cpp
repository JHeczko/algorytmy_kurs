#include "stack.cpp"

using namespace std;
using namespace stack;

int main(){
    Stack stack;
    stack.push(2);
    cout << stack.top() << endl;
    stack.pop();
    cout << stack.top() << endl;
}