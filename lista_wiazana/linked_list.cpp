#include <iostream>

using type_el = int;

namespace linkedListNamespace{

    struct cell{
        cell* next;
        type_el element;
    };

    using position = cell*;

    class linkedList{
        private:
            cell* HEAD;
        public:
        
        
        //Constructor
            linkedList(){
                HEAD = new cell;
                HEAD->next = nullptr;
            }

        //Destructor
            ~linkedList(){
                cell* tmp = HEAD;
                while(tmp->next != nullptr){
                    remove(HEAD);
                }
                delete tmp;
            }

        //Retrieve
            type_el retrieve(cell* pos){
                if(pos->next == nullptr){
                    return -11111111;
                }
                return pos->next->element;
            }

        //Print_list
            void print(){
                std::cout << "Wypis listy:\n [ ";
                cell* pos = HEAD;
                for(int i = 1;pos->next != nullptr; ++i){
                    std::cout << pos->next->element << ", ";
                    pos = pos->next;
                }
                std::cout << "]\n";
            }

        //First
            cell* first(){
                return HEAD;
            }
        
        
        //IsInList
            bool isInList(cell* elAdress){
                cell* tmp = HEAD;
                while(tmp != nullptr){
                    if(tmp == elAdress){
                        return true;
                    }
                    tmp = tmp->next;
                }
                return false;
            }   

        //Locate
            position locate(type_el el){
                cell* tmp = HEAD;
                while(tmp->next != nullptr){
                    if(tmp->next->element == el){
                        return tmp;
                    }
                    tmp = tmp->next;
                }
                return nullptr;
            }

        //Insert
            bool insert(type_el el, position pos){
                if(pos == nullptr){
                    return false;
                }
                else if(pos->next == nullptr){
                    pos->next = new cell;
                    pos->next->element = el;
                    pos->next->next = nullptr;
                    return true; 
                }
                else{
                    cell* tmp = pos->next;
                    pos->next = new cell;
                    pos->next->element = el;
                    pos->next->next = tmp;
                    return true;
                }
            }

        
        //Previous
            position previous(position p){
                cell* tmp = HEAD; 
                while(tmp != nullptr){
                    if(tmp->next == p){
                        return tmp;
                    }
                tmp = tmp->next;
                }
                return nullptr;
            }

        //End
            position end(){
                position pos = HEAD;
                while(true){
                    if(pos->next == nullptr){
                        return pos;
                    }
                    pos = pos->next;
                }
            }
        
        
        //Next
            position next(position p){
                if(p == end()){
                    return nullptr;
                }
                return p->next;
            }
        
        //delete 
            bool remove(position pos){
                if(pos->next == nullptr || pos == nullptr || !(isInList(pos))){
                    return false;
                }
                position tmp = pos->next;
                pos->next = pos->next->next;
                delete tmp;
                return true;
            }

        //clear
            cell* clear(){
                cell* tmp = HEAD;
                while(tmp->next != nullptr){
                    remove(HEAD);
                }
                return end();
            }
    };
}
/*

• DELETE(p,L) – usuwa element na pozycji p z listy.
• MAKENULL(L).Czyni listę pustą i zwraca pozycję END(L).

Remember: dajemy sobie cos takiego, ze element na komorke a1 czyli pierwsza to bedzie tak naprawde adres na komorke. Pozycja elemetu to wskazik do komorki wczesniejszej, czyli a1 to tak naprawde dostaniemy wksaznik do head, ale zeby dostac a1 to robimy poprostyu head->next i mamy i elo i czesc
*/