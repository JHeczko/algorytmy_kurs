#pragma once
#include <vector>
#include <iostream>
#include <unistd.h>
using namespace std;


class ContainerQueue 
{
    protected:
        ContainerQueue (){};
    public:
        virtual unsigned int Count () const = 0;
        virtual bool IsEmpty () const {return Count()==0;};
        virtual bool IsFull () const = 0;
        virtual void MakeNull() = 0;
 };
 
template <typename T> class PriorityQueue : public ContainerQueue
{
    public:
        virtual void Enqueue (T element) = 0;
        virtual T  FindMin () const = 0;
        virtual void DequeueMin () = 0;
};

namespace bh{
template <typename T> class BinaryHeap : public PriorityQueue<T>
{
    protected:
        int max;
        int count;
        std::string name;
        std::vector<T> data;
        
    public:

        BinaryHeap(unsigned int n, std::string name){
            this->count = 0;
            this->name = name;
            data.reserve(n);
        };

        BinaryHeap(unsigned int n){
            this->count = 0;
            this->name = "Kolejka";
            data.reserve(n);
        };

        BinaryHeap(){;};

        ~BinaryHeap (){;};

        void MakeNull(){
            this->count = 0;
        };

    /**
    * W tablicy o indeksach zaczynających się od zera:
    * Rodzic – i-ta komórka -> Dzieci 2*i+1,2*i+2
    * Dziecko indeks j -> Rodzic indeks (j-1)/2 (dzielenie liczb całkowitych, bez reszty)
    */

        void Enqueue (T element){
            int pos = count;
            int parent_pos = 0;
            bool flag = true;
            if(data.size() == count){
                //cout << "Powiekszam" << count;
                data.resize(data.capacity()+10);
            }
            try{
                while(flag){
                    //Znajdywanie wartosci rodzica wezla pod ktory wstawiamy
                    parent_pos = floor((pos-1)/2);
                    //cout << " Coutn: " << count << " Parent Pos: "<< parent_pos << " Pos: " << pos << " Element: " << element << endl;
                    if(pos == 0){
                        data[pos] = element;
                        flag = false;
                    }else if(data[parent_pos] <= element){
                        data[pos] = element;
                        flag = false;
                    }else {
                        data[pos] = data[parent_pos];
                        data[parent_pos] = 0;
                        pos = parent_pos;
                    }
                }
            }catch(out_of_range e){
                cerr << "Out of range exception";
                return;
            }
            ++count;
        };

        T FindMin () const{
            if(count > 0){
                return data.at(0);
            }
            T cos;
            return cos;
        };

        void DequeueMin (){
            if(count == 0){
                return;
            }
            count--;
            int buf;
            int pos = 0;
            int lewy,prawy;
            try{

                buf = data.at(count);

                while(pos < count){
                    lewy = (2*pos)+1;
                    prawy = (2*pos)+2;

                    //sprawdzenie czy jestesmy w lisciu
                    if(lewy>=count && prawy>=count){
                        data[pos] = buf;
                        break;
                    }
                    
                    //sprawdzenie czy nie mamy jednego liscia po prawej stronie
                    if(lewy >= count ){
                        if(buf <= data[prawy]){
                            data[pos] = buf;
                        }else{
                            data[pos] = data[prawy];
                            data[prawy] = buf;
                        }
                        break;
                    } 
                    if(prawy>=count){
                        if(buf <= data[lewy]){
                            data[pos] = buf;
                        }else{
                            data[pos] = data[lewy];
                            data[lewy] = buf;
                        }
                        break;
                    }

                    //sprawdzanie czy nasz element z dolu moze byc wstawiona w srodek gdzies
                    if((buf <= data.at(lewy)) && (buf <= data.at(prawy))){
                        data[pos] = buf; 
                    }

                    //sprawdzenie jakie dziecko musimy wziac czy te z lewa czy z prawa
                    if(data[lewy] <= data[prawy]){ 
                        data[pos] = data[lewy];
                        pos = lewy;
                    }else{
                        data[pos] = data[prawy];
                        pos = prawy;
                    }
                }
            }catch(out_of_range e){
                cerr << "Out of bonds exception\n";
            }
        };

        bool IsEmpty () const{
            if(count == 0){
                return true;
            }
            return false;
        };

        bool IsFull () const {
            if(data.size() == count){
                return true;
            }else{
                return false;
            }

        };

        void wypisz() const{
            try{
            cout << "Wypis " << this->name << ":\n";
            for(int i = 0; i<count; i++){ 
                cout << i << ": "<< data.at(i) << endl;
            }
            }catch(out_of_range e){
                cerr << "Out of range exception" << endl;
            }
        };

        unsigned int Count() const {
            return count;
            }
};
}
// template <typename T>
// //BinaryHeap<T>::BinaryHeap (unsigned int n):count(0),data(n){};
// BinaryHeap<T>::BinaryHeap (unsigned int n):count(0){data.reserve(n);};
// template <typename T>