#include <iostream>

namespace lista{

typedef int elementtype, position;

const int maxlength=4;

struct List{
	elementtype elements[maxlength];
	int last;           //indeks ostatniego elementu listy
};

position END(List l){ 
    return l.last + 1;
}

position First(List l) {
    return 0;
}

position Next(position p,List l){
    if(p>=0 && p<=maxlength){
        return p+1;
    }
    else{
        return -1;
    }
}

position Previous(position p,List l) {
    if(p <= 0 || p > l.last+1){
        return -1;
    }
    else{
        return p-1;
    }
}

position Locate(elementtype x, List l) { 
    //zwraca pozycje x w l, gdy nie ma x w l zwraca end(l)
    for(int i = 0; i <= l.last; ++i){
        if(l.elements[i] == x){
            return i;
        }
    }
    return END(l);
}

elementtype Retrieve(position p, List l) {
    if(p>=0 && p<=l.last){
        return l.elements[p];
    }
    else{
       return -10000000; 
    }
}

bool Insert(int x, position p, List &l){
    // std::cout << "Dodaje na pos: " << p << " Element x: " << x <<std::endl;
    if(p < 0 || p >= maxlength || l.last+1 == maxlength || p > l.last+1){
        return false;
    }
    else if(p == l.last+1 || l.last == -1){
        l.elements[l.last+1] = x;
        ++l.last;
        return true;
    }
    else{
        for(int i = l.last+1; i > p; --i){
            l.elements[i] = l.elements[i-1];
        }
        l.elements[p] = x;
        ++l.last;
        return true;
    }
}

bool Delete(position p, List &l){
    if(p < 0 || p >= maxlength){
        return false;
    }
    else{
        for(int i = p; i < l.last; ++i){
            l.elements[p] = l.elements[p+1];
        }
        --l.last;
        return true;
    }
}
bool Duplicate(List &l){
    if((l.last+1 == 0) || (((l.last+1) * 2) > maxlength)){
        return false;
    }
    else{
        for(int i = 0; i<l.last+1; ++i){
            l.elements[END(l)+i] = l.elements[i];
        }
    l.last = (l.last*2)+1;
    return true;
    }
}
bool Purge(List &l){
    if(l.last + 1 == 0){
        return false;
    }
    for(int i = 0; i < END(l); ++i){
        for(int j = i+1; j < END(l); ++j){
            if(l.elements[i] == l.elements[j]){
                std::cout << "Usuwam" << std::endl;
                Delete(j,l);
                j--;

            }
        }
    }
    return true;
}
}