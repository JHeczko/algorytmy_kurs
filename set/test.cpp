#include <iostream>
#include "set.cpp"

using namespace std;
using namespace set_namespace;
using namespace Visitators;

int main(){
    SetAsArray A(10);
    SetAsArray B(10);

    A.Insert(0);
    A.Insert(2);
    A.Insert(4);
    A.Insert(6);
    A.Insert(8);

    B.Insert(1);
    B.Insert(3);
    B.Insert(5);
    B.Insert(7);
    B.Insert(9);

    SetAsArray C = A + B;
    SetAsArray D = A - B;

    cout << "A:\n";
    A.wypisz();

    cout << "B:\n";
    B.wypisz();
    cout << "\n";

    cout << "+:\n";
    C.wypisz();

    cout << "-:\n";
    D.wypisz();

    cout << "==:\n";
    cout << "D==A: " << (D==A) << " C==B: " << (C==B)  << std::endl;
    cout << "<=:\n";
    cout << "D<=A: " << (D<=A) << " B<=C: " << (B<=C) << endl;

    A.Insert(1);

    cout << "Test po A instert 1:\n";
    cout << "D==A: "<< (D==A) << " D<=A: " << (D<=A) << endl;

    AddingVisitor v_a;

    A.accept(v_a);
    cout << "Suma A: " << v_a.getSum() << endl;

    SetAsArray E = A*B;

    AddingVisitor v_e;

    E.accept(v_e);
    cout << "Suma E: " << v_e.getSum() << endl;
    E.Withdraw(1);
    v_e.reset();
    E.accept(v_e);
    cout << "Suma E: " << v_e.getSum() << endl;

    OddVisitor oddB;
    OddVisitor oddA;

    A.accept(oddA);
    B.accept(oddB);

    cout << "Odd Visit A: " << oddA.getIndex() << "\nOdd Visit B: " << oddB.getIndex() << endl;

    A.Withdraw(1);
    A.Insert(5);
    //A.Withdraw(5);

    cout << "Odd Visit A: " << oddA.getIndex() << "\nOdd Visit B: " << oddB.getIndex() << endl;

    oddA.reset();

    A.accept(oddA);

    cout << "Odd Visit A: " << oddA.getIndex();

    cout << "\nA:\n";
    A.wypisz();
    cout << "B:\n";
    B.wypisz();

    Iterator<int>& itA = A.NewIterator();
    Iterator<int>& itB = B.NewIterator();

    cout << "A:\n";
    while(!itA.IsDone()){
        cout << *itA << " ";
        ++itA;
    }
    cout << "\nB:\n";
    while(!itB.IsDone()){
        cout << *itB << " ";
        ++itB;
    }


}