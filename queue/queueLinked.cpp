#include "list.cpp"
#include <iostream>

using namespace linkedListNamespace;

namespace queue{
    class Queue{
        private:
            linkedList lista;

        public:
            Queue(){};
            ~Queue(){};
            cell* front(){
                return lista.first();
            }
            void Enqueue(type_el el){
                std::cout << lista.insert(el,lista.end());
            }
            void Dequeue(){
                lista.remove(front());
            }
    };
};