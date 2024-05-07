#pragma once
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
