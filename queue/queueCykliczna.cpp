#include <iostream>

namespace queueCykliczna{
    using type_el = int;
    class QueueCykl{
        private:
            int REAR;
            int FRONT;
            type_el* tab;
            int size;
        public:
            QueueCykl(int sizevar){
                if(size > 0){
                    tab = new type_el[size];
                    size = sizevar;
                    this->REAR = sizevar-2;
                    this->FRONT = sizevar-1;
                }
            }
            ~QueueCykl(){
                delete[] tab;
            }

            void makenull(){
                REAR = size - 2;
                FRONT = size - 1;
            }
            type_el front(){
                return tab[FRONT];
            }
            bool enqueue(type_el x){
                if(((REAR+2)%size) == FRONT){
                    return false;
                }
                REAR = (REAR+1)%size;
               // std::cout << REAR << std::endl;
                tab[REAR] = x;
                return true;
            }
            bool dequeue(){
                if(isEmpty()){
                    return false;
                }
                //std::cout << FRONT << std::endl;
                FRONT = (FRONT+1)%size;
                return true;
            }
            bool isEmpty(){
                if((REAR+1)%size == FRONT){
                    return true;
                }
                return false;
            }

    };
}
// 1. MAKENULL(Q) – czyni kolejkę pustą
// 2. FRONT(Q) – zwraca pierwszy element kolejki
// 3. ENQUEUE(x,Q) – wstaw x do kolejki
// 4. DEQUEUE(Q) – usuwa pierwszy element z kolejki
// 5. EMPTY(Q) – zwraca true gdy kolejka jest pusta,
// w przeciwnym wypadku zwraca false