#include <iostream>

template<typename T>

class MyList{
    private:
        struct Node{
            T data;
            Node* prev;
            Node* next;
        };

        Node* head = nullptr;
        Node* tail = nullptr;
    
    public:
        void push_back(const T& value){
            Node* newNode = new Node();
            if(tail == nullptr){
                head = newNode;
            }
            else{
                newNode->prev = tail;
                tail->next = newNode;
            }
            newNode->data = value;
            newNode->next = nullptr;
            tail = newNode;
        }

        void pop_back(){
            if(tail == nullptr)return;
            if(head == tail){
                delete tail;
                head = nullptr;
                tail = nullptr;
                return;
            }
            Node* new_tail = tail->prev;
            delete tail;
            tail = new_tail;
            tail->next = nullptr;
        }

        void push_front(const T& value){
            Node* newNode = new Node();
            if(head == nullptr){
                tail = newNode;
            }
            else{
                head->prev = newNode;
                newNode->next = head;
            }
            newNode->data = value;
            newNode->prev = nullptr;
            head = newNode;
        }

        void pop_front(){
            if(head == nullptr)return;
            if(head == tail){
                delete head;
                head = nullptr;
                tail = nullptr;
                return;
            }
            Node* new_head = head->next;
            delete head;
            head = new_head;
            head->prev = nullptr;
        }

        void insert(int pos, const T& value){
            if(pos < 0)return;
            Node* new_node = new Node();
            if (pos == 0) {
                new_node->next = head;
                if (head != nullptr)
                    head->prev = new_node;
                else
                    tail = new_node;

                head = new_node;
                return;
            }
            Node* current = head;
            for(int i = 0; i < pos - 1; i++){
                current = current->next;
            }
            if(current == nullptr){
                delete new_node;
                return;
            }
            new_node->data = value;
            new_node->next = current->next;
            new_node->prev = current;
            if(current->next != nullptr) current->next->prev = new_node;
            else tail = new_node;
            current->next = new_node;
            
        }

        void erase(int pos){
            if(pos < 0 || head == nullptr)return;
            Node* current = head;
            for(int i = 0; i < pos; i++){
                current = current->next;
            }
            if (current == head) {
                head = head->next;
                if (head != nullptr) head->prev = nullptr;
                else tail = nullptr;
            }
            else if (current == tail) {
                tail = tail->prev;
                tail->next = nullptr;
            }
            else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }

            delete current;

        }

        void print_all(){
            for(Node* ptr = head; ptr!=nullptr; ptr = ptr->next){
                std::cout<<ptr->data<<" ";
            }
        }

        ~MyList(){
            Node* ptr = head;
            while(ptr != nullptr){
                Node* next = ptr->next;
                delete ptr;
                ptr = next;
            }
        }
};

int main(){
    MyList<int> l;
    l.push_back(2);
    l.push_front(5);
    l.insert(1, 3);
    l.erase(0);
    // l.~MyList();
    l.print_all();

    return 0;
}