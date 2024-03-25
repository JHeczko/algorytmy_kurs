#include "lista.cpp"
#include <stdio.h>
#include <iostream>

using namespace lista;
using namespace std;



void print(List l)
{
	position i=First(l);
	while (i!=END(l))
	{
		printf ("  %d,", Retrieve(i,l));
		i=Next(i,l);
	}
	 printf("\n");

}

int main(){
    List l;
    l.last=-1;
    cout << Insert(100,First(l),l) << endl;
    print(l);
    for (int i=0; i<6;i++){
        cout << Insert(i,First(l),l) << endl;
    }
    print(l);
    cout << Insert (20,Previous(END(l),l) ,l) << endl;
    print(l);
    cout << "Delte" << Delete( Locate(20,l),l) << endl;
    print(l);
    cout << "Dup" << Duplicate(l) << endl;
    print(l);
    cout <<"Purge" <<Purge(l) << endl;
    print(l);
}