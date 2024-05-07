#pragma once

#include <vector>
#include <iostream>
#include "visitor.cpp"

// STANDARD CONTAINER
template <typename T>class Container {
public:
    Container() {};
    virtual int Count() const = 0;
    virtual bool IsEmpty() const { return Count() == 0; };
    virtual bool IsFull() const = 0;
    virtual void MakeNull() = 0;
    virtual void accept (Visitators::Visitor<T> & v)=0;
};


// SET
template <typename T> class Set : public virtual Container<T> {

protected:
    int count;
    int universeSize;

public:
    Set(int n) : universeSize(n) {}
    int UniverseSize() const { return universeSize; }
    int Count() const { return count; };
    virtual void Insert(T element) = 0;
    virtual bool IsMember(T element) const = 0;
    virtual void Withdraw(T element) = 0;
};

template<typename T> class IteratorAbs{
public:
    virtual ~IteratorAbs(){};
    virtual bool IsDone() const = 0;
    virtual T operator*() const = 0;
    virtual void operator++() = 0;
};

namespace set_namespace{
//SET AS ARRAY
class SetAsArray : public Set<int> {
private:
    std::vector<bool> array;
    class IteratorSet : public IteratorAbs<int>{
    private:
        std::vector<bool> data;
        int universeSize;
        int index;
    public:

        IteratorSet(std::vector<bool> array, int us){
            data = array;
            universeSize = us;
            index = us;
            for(int i = 0; i<us; ++i){
                if(data[i] == true){
                    index = i;
                    break;
                }
            }
        };

        ~IteratorSet(){};

        bool IsDone() const{
            if(index == (universeSize)){
                return true;
            }else{
                return false;
            }
        };
        int operator*() const{
            return index;
        };
        void operator++(){
            for(int i = index+1; i<universeSize; ++i){
                if(data[i] == true){
                    index = i;
                    return;
                }
            }
            index = universeSize;
        };
    };

public:

    SetAsArray(unsigned int n) : Set(n){
        this->array = *(new std::vector<bool>(n,false)); 
    };
    
    void MakeNull(){
        this->count = 0;
    }; // metody z containera

    bool IsFull() const { 
        return (Count() == UniverseSize()); 
    };

    void Insert(int element){
        if(IsFull() || element >= UniverseSize()){
            return;
        }else{
            array[element] = 1;
            count++;
        }
    };

    bool IsMember(int element) const{
        if(array[element] == 1){
            return true;
        }else{
            return false;
        }
    };

    void Withdraw(int element){
        if(element >= UniverseSize() || IsFull()){
            return;
        }else{
            array[element] = 0;
            count--;
        }
    };

    void const wypisz(){
        if(IsEmpty()){
            std::cout << "{}\n";
            return;
        }
        std::cout << "{";
        for(int i = 0; i<UniverseSize(); i++){
            if(array[i] == true){
                std::cout << i << ", ";
            }
        }
        std::cout << '}' << std::endl;
    };

    void accept(Visitators::Visitor<int>& v){
        for(int i = 0; (i<UniverseSize()) && (!v.isDone()); i++){
            if(array[i]) {
                v.Visit(i);
            }
        }
    };

    IteratorSet& NewIterator(){
        return *(new IteratorSet(array,UniverseSize()));
    };

    // Przyjaciel - funkcja uzyska prawo dostępu do prywatnych elementów danej klasy.
    friend SetAsArray* operator+(SetAsArray const& T, SetAsArray const& S);
    friend SetAsArray operator-(SetAsArray const& T, SetAsArray const& S);
    friend SetAsArray operator*(SetAsArray const& T, SetAsArray const& S);
    friend bool operator==(SetAsArray const& T, SetAsArray const& S);
    friend bool operator<=(SetAsArray const& T, SetAsArray const& S);
    // void Accept(Visitor&) const{};
    // O metodzie Accept powiemy na następnych zajęciach
};
SetAsArray* operator+(SetAsArray const& T, SetAsArray const& S){
    SetAsArray* newSet = new SetAsArray(T.UniverseSize());
    if(T.UniverseSize() == S.UniverseSize()){
        for(int i = 0; i<T.UniverseSize(); ++i){
            if(T.array[i] == true || S.array[i] == true){
                newSet->array[i] = true;
                newSet->count++;
            }
        }
    }else{
        return new SetAsArray(0);
    }
    return newSet;
}

SetAsArray operator-(SetAsArray const& T, SetAsArray const& S){
    SetAsArray newSet = *(new SetAsArray(T.UniverseSize()));

    if(T.UniverseSize() == S.UniverseSize()){
        for(int i = 0; i<T.UniverseSize(); ++i){
            if(T.array[i] == true && S.array[i] == true){
                newSet.array[i] = false;
            //Sprawdzilismy juz czy usuwamy wiec teraz zostają nam te wszystkie ktore maja
            //zera na lub jedynki ale nie mozemy ich usunac
            }else if(S.array[i] == false || S.array[i] == true){
                newSet.array[i] = T.array[i];
                if(T.array[i] == true){
                    newSet.count++;
                }
            }
        }
    }else{
        return *(new SetAsArray(0));
    }
    return newSet;
};

SetAsArray operator*(SetAsArray const& T, SetAsArray const& S){
    SetAsArray newSet = *(new SetAsArray(T.UniverseSize()));

    if(T.UniverseSize() == S.UniverseSize()){
        for(int i = 0; i<T.UniverseSize(); ++i){
            if(T.array[i] == true && S.array[i] == true){
                newSet.array[i] = true;
                newSet.count++;
            }
        }
    }else{
        return *(new SetAsArray(0));
    }
    return newSet;
};

bool operator==(SetAsArray const& T, SetAsArray const& S){
    if(T.UniverseSize() == S.UniverseSize()){
        for(int i = 0; i<T.UniverseSize(); ++i){
            if(T.array[i] != S.array[i]){
                return false;
            }
        }
        return true;
    }else{
        return false;
    }
};

bool operator<=(SetAsArray const& T, SetAsArray const& S){
    if(T.UniverseSize() == S.UniverseSize()){
            for(int i = 0; i<T.UniverseSize(); ++i){
                if((T.array[i] == true) && (S.array[i] == false)){
                    return false;
                }
            }
            return true;
        }else{
            return false;
        }
};

}

