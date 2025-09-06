#include <iostream>
#include <fstream>

using element_type = int;

namespace BT{
    struct Node
    {
        element_type element;
        Node* left;
        Node* right;
    };
    class BinaryTree{
        private:
            Node* ROOT;
        protected:

            //PREORDER HELP
            void preOrder(Node* t){
                std::cout << t->element << ", ";
                if(t->left != nullptr){
                    preOrder(t->left);
                }
                if(t->right != nullptr){
                    preOrder(t->right);
                }
            };

            //INORDER HELP
            void inOrder(Node* t){
                if(t == nullptr){
                    return;
                }
                inOrder(t->left);
                std::cout << t->element << ", ";
                inOrder(t->right);
            };

            //POSTORDER HELP
            void postOrder(Node* t){
                if(t->left != nullptr){
                    postOrder(t->left);
                }
                if(t->right != nullptr){
                    postOrder(t->right);
                }
                std::cout << t->element << ", ";
            };

            //BUILD TREE HELP
            Node* buildTreeHelp(int m, std::ifstream& file){
                if(m == 0){
                    return nullptr;
                }
                else{
                    Node* nowy = new Node();
                    file >> nowy->element; 
                    if((m%2) == 0){
                        nowy->right = buildTreeHelp((m/2)-1,file);
                        nowy->left = buildTreeHelp(m/2,file);
                    } else{
                        nowy->left = buildTreeHelp((m-1)/2,file);
                        nowy->right = buildTreeHelp((m-1)/2,file);
                    }
                    return nowy;
                }
            };

            //search from specific node in tree
            Node* search(Node* szukane, Node* rekur){
                Node* left_search;
                Node* right_search;

                if(rekur->left != nullptr && rekur->left != szukane){
                    left_search = search(szukane,rekur->left);
                }
                else if(rekur->left == szukane){
                    return rekur;
                } 
                else if(rekur->left == nullptr){
                    left_search = nullptr;
                }

                if(rekur->right != nullptr && rekur->right != szukane){
                    right_search = search(szukane,rekur->right);
                }
                else if(rekur->right == szukane){
                    return rekur;
                }else if(rekur->right == nullptr){
                    right_search = nullptr;
                }

                if(left_search != nullptr){
                    return left_search;
                } 
                else if(right_search != nullptr){
                    return right_search;
                }else{
                    return nullptr;
                }

            }
        public:
            BinaryTree(){
                ROOT = nullptr;
            };

            //PARENT
            Node* getParent(Node* n){
                Node* szukane = search(n, ROOT);
                return szukane;
            };

            //LEFT_CHILD
            Node* leftChild(Node* n){
                if(n->left == nullptr){
                    return nullptr;
                }
                return n->left;
            };

            //RIGHT_CHILD
            Node* rightChild(Node* n){
                if(n->right == nullptr){
                    return nullptr;
                }
                return n->right;
            };

            //GET_LABEL
            element_type getLabel(Node* n){
                if(n == nullptr){
                    return -1111111111;
                }
                return n->element;
            };

            //BUILDTREE
            void buildTree(int m){
                std::ifstream file("user_input.txt");
                ROOT = buildTreeHelp(m, file);
                file.close();
            };

            //ROOT
            Node* getRoot(){
                return this->ROOT;
            };

            //MAKENULL
            void makeNull(Node* p){
                Node* tmp_right = p->right;
                Node* tmp_left = p->left;
                p->left = nullptr;
                p->right = nullptr;
                delete p;
                if(tmp_right != nullptr){
                    makeNull(tmp_right);
                }
                if(tmp_left != nullptr){
                    makeNull(tmp_left);
                }

            };

            //PREORDER_PRINT
            void preOrderPrint(){
                std::cout << "preOrderPrint:\n[ ";
                preOrder(ROOT);
                std::cout << "]\n";  
            }

            //INORDER_PRINT
            void inOrderPrint(){
                std::cout << "inOrderPrint:\n[ ";
                inOrder(ROOT);
                std::cout << "]\n";    
            }

            //POSTORDER_PRINT
            void postOrderPrint(){
                std::cout << "postOrderPrint:\n[ ";
                postOrder(ROOT);
                std::cout << "]\n";
            }
            //DESTRUCTOR
            ~BinaryTree(){
                makeNull(this->ROOT);
            }
    };
}