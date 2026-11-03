#include <iostream>


struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int value){
        data = value;
    }
};

class My_BST{
    private:
        Node* root;
        void destroy(Node* node) {
            if (node == nullptr)
                return;

            destroy(node->left);
            destroy(node->right);
            delete node;
        }
    public:
        My_BST(){
            root = nullptr;
        }
        ~My_BST(){
            destroy(root);
        }
        
        void insert(const int& value) {
            Node* newNode = new Node(value);
            if(root == nullptr){
                root = newNode;
                return;
            }
            Node* current = root;
            while(true){
                if(value < current->data){
                    if(current->left == nullptr){
                        current->left = newNode;
                        return;
                    }
                    current = current->left;
                }
                else if(value > current->data){
                    if(current->right == nullptr){
                        current->right = newNode;
                        return;
                    }
                    current = current->right;
                }
                else{
                    delete newNode;
                    return;
                }
            }
        }

        bool search(const int& value) {
            if(root == nullptr){
                return false;
            }
            Node* current = root;
            while(current != nullptr){
                if(value < current->data){
                    current = current->left;
                }
                else if(value > current->data){
                    current = current->right;
                }
                else{
                    return true;
                }
            }
            return false;
        }

        // void erase(const int& value){
        //     if(root == nullptr){
        //         return;
        //     }
        //     Node* current = root;
        //     while(current != nullptr && current->right != null && ptrcurrent->left != nullptr){
        //         if(value < current->left->data){
        //             current = current->left;
        //         }
        //         else if(value > current->right->data){
        //             current = current->right;
        //         }
                
        //     }
        // }
};

int main(){
    My_BST bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(6);
    std::cout<<bst.search(3);

    return 0;
}