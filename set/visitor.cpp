#include <iostream>

/*
Utwórz zbiory A,B,C i D (zbiór uniwersalny rozmiar 10) Do zbioru A wstaw elementy parzyste
Do zbioru B wstaw elementy nieparzyste
C=A+B
D=C-B
A.Wypisz();
B.Wypisz();
C.Wypisz();
D.Wypisz();
sprawdź, czy:
"D==A" "D<=A"
"C==B"
"B<=C"
Do zbioru A wstaw elementy wartość 1 sprawdź, czy:
"D==A"
"D<=A"
Do zbioru A wstaw elementy wartość 5 Utwórz wizytatora dla zbioru A: v_A A.Accept(v_A)
Wypisz sumę policzoną przez v_A
E=A *B
Utwórz wizytatora dla zbioru E: v_E
E.Accept(v_E)
Wypisz sumę policzoną przez v_E
Usuń wartość 1 z E i ponownie oblicz sumę
    elementów zbioru E korzystając z wizytatora
Sprawdzenie czy w zbiorze B jest liczba nieparzysta (korzystając z wizytatora)
Sprawdzenie czy w zbiorze A jest liczba nieparzysta (korzystając z wizytatora)
Usuń wartość 1 z A
Usuń wartość 5 z A
Sprawdzenie czy w zbiorze A jest liczba nieparzysta (korzystając z wizytatora)
Proszę na potrzeby sprawdzenia, czy działa IsDone(),
 wypisać na której komórce funkcja Accept() zakończyła przeglądanie
*/

namespace Visitators{

    template <typename T> class Visitor{
    public:
        virtual void Visit (T& element) = 0;
        virtual bool isDone() const{
            return false;
        }
    };

    class AddingVisitor : public Visitor<int> {
    private:
        int sum = 0;
        bool done = false;
    public:
        void reset(){
            sum = 0;
        }
        int getSum(){
            return sum;
        }
        void Visit(int& element) {
            sum += element;
        }
        bool isDone() const {
            return done;
        }
    };

    class OddVisitor : public Visitor<int>{
    private:
        int index = -1;
        bool odd = false;
    public:
        int reset(){
            index = -1;
            odd = false;
        }
        int getIndex(){
            return index;
        }
        void Visit(int& element) {
            if(element % 2){
               odd = true;
               index = element;
            }
        }
        bool isDone() const {
            return odd;
        }
    };;

}
