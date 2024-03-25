#include "BinaryTree.cpp"
#include <iostream>

using namespace BT;
using namespace std;

void UI(BinaryTree& t){
    Node* pos_in_tree = t.getRoot();
    int choice = 10;
    system("clear");
    cout << "Instrukcja: \n-Aby wyjsc z UI kliknij 0\n-Aby poruszyc się w lewą gałąź drzewa wpisz 1\n-Aby poruszyc sie w prawa galaz drzewa kliknij 2\n-Aby cofnac sie do rodzica wpisz 3\n";
    cout << "Wartosc korzenia: " << t.getLabel(pos_in_tree) << endl; 
    while(choice != 0){
        cout << "Rusz sie: ";
        cin >> choice;
        switch(choice){
            case 0:
                return;
            case 2:
                if(t.getLabel(t.rightChild(pos_in_tree)) == -1111111111){
                    cout << "Chcesz wyjść poza drzewo\n";
                } else{
                    pos_in_tree = t.rightChild(pos_in_tree);
                    cout << "Wartosc akutalnego wezla: " << t.getLabel(pos_in_tree) << endl; 
                }
                break;
            case 1:
                if(t.getLabel(t.leftChild(pos_in_tree)) == -1111111111){
                    cout << "Chcesz wyjść poza drzewo\n";
                } else{
                    pos_in_tree = t.leftChild(pos_in_tree);
                    cout << "Wartosc akutalnego wezla: " << t.getLabel(pos_in_tree) << endl; 
                }
                break;
            case 3:
                if(pos_in_tree == t.getRoot()){
                    cout << "Chcesz wyjść poza drzewo\n"; 
                    break;  
                }
                pos_in_tree = t.getParent(pos_in_tree);
                cout << "Wartosc akutalnego wezla: " << t.getLabel(pos_in_tree) << endl;
                break;
            default:
                cout << "Bledny wybor\n";
                break;
        }
    }
}

int main(){
    //setup
    BinaryTree tree;
    tree.buildTree(9);

    //tests
    cout << "Lewe dziecko korzenia: " << tree.getLabel(tree.leftChild(tree.getRoot())) << "\nPrawe dziecko korzenia: " << tree.getLabel(tree.rightChild(tree.getRoot()))<< endl;
    cout << "Wartosc rodzica prawego dziecka korzenia: " << tree.getLabel(tree.getParent(tree.rightChild(tree.getRoot()))) << endl;
    cout << "Poprostu kolejny test" << tree.getLabel(tree.rightChild(tree.leftChild(tree.getRoot()))) << "\n\n";
    tree.preOrderPrint();
    tree.inOrderPrint();
    tree.postOrderPrint();
    //UI
    UI(tree);

    
}