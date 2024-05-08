#pragma once
#include "set.cpp"
#include "graph.cpp"
using namespace set_namespace;

class Partition {
private:
    std::vector<SetAsArray*> particies;
public:

    Partition(int n) : particies(0){
        for(int i = 0; i<n; i++){
            SetAsArray* buf = new SetAsArray(n);
            buf->Insert(i);
            particies.push_back(buf);
        }
    }

    SetAsArray& findSet(Vertex* v){
        for(SetAsArray* set : particies){
            if(set->IsMember(v->getNumber())){
                return *(set);
            }
        }
        return *new SetAsArray(0);
    }

    int size(){
        return particies.size();
    }

    void join(SetAsArray& s, SetAsArray& t){
        for(int i = 0; i < particies.size(); i++){
            if(*particies[i] == s){
                particies.erase(particies.begin()+i);
            }
        }
        for(int i = 0; i < particies.size(); i++){
            if(*particies[i] == t){
                particies.erase(particies.begin()+i);
            }
        }
        particies.push_back(s+t);
    }
    void Wypisz(){
        for(SetAsArray* set : particies) {
            std::cout << "Partition: ";
            set->wypisz();
        }
    }
};

