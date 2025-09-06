#include <random>
#include "graph.cpp"
#include "set.cpp"
#include "partition.cpp"
#include "labirynt.cpp"

using namespace std;


int main(int argc, char** argv){
    Labirynt* lab;
    if(argc!=3){
        lab = new Labirynt(4,4);
    }else{
        lab = new Labirynt(stoi(argv[1]), stoi(argv[2]));
    }
    lab->generateRandomLabirynt();
    //lab.printEdgesBase();
    lab->printEdgesLab();
    lab->visualizeLab();
}