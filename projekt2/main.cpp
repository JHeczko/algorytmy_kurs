#include <random>
#include "graph.cpp"
#include "set.cpp"
#include "partition.cpp"
#include "labirynt.cpp"

using namespace std;


int main(void){
    Labirynt lab(10,11);
    lab.generateRandomLabirynt();
    //lab.printEdgesBase();
    lab.printEdgesLab();
    lab.visualizeLab();
}