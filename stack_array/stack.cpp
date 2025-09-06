using el_type = int;
// 3. POP- sprawdzamy, czy stos nie jest pusty. Jeśli nie jest, usuwamy element ze szczytu stosu uaktualniając pole TOP.
// 4. Top_elem – sprawdzamy, czy stos nie jest pusty. Jeśli nie jest pusty, zwracamy wartość ze szczytu stosu
// 5. Makenull - ustawia TOP na -1
#include <iostream>

namespace stackArray{

    class Stack{
        private:
            el_type size;
            el_type* arr;
            el_type top;
        public:
            Stack(el_type n){
                this->size = n;
                this->arr = new el_type[n];
                this->top = -1;
            }
            void push(el_type el){
                if(top+1 != size){
                    arr[top+1] = el;
                    top++;
                }
                else{
                    std::cout << "Push error\n";
                }
            }
            bool empty(){
                if(top == -1){
                    return true;
                }
                else{
                    return false;
                }
            }
            void pop(){
                if(top == -1){
                    std::cout << "Pop error\n";
                } else{
                    arr[top+1] = 0;
                    top--;
                }
            }

            el_type top_element(){
                if(top != -1){
                    return arr[top];
                }
                else{
                    std::cout << "Top_element doesnt exitst //Stack is empty\n";
                }
            }

            void make_null(){
                top = -1;
            }



    };
}