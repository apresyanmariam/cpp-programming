#include <iostream>
using namespace std;

class MyPointer{
    private: int* ptr;
    public: 
        MyPointer(int p){
            ptr = new int(p);
        }

        int* get(){
            return ptr;
        }

        void reset(int* p = 0){
            delete ptr;
            ptr = p;
        }


        ~MyPointer(){
            delete ptr;
        }
};


int main(){

    MyPointer p(7);
    cout<<*p.get(); //gives 7 after allocating

    p.reset(new int(3));

    cout<<*p.get();  // gives 3 after deleting the 7 and allocating 3

    p.reset();

    cout<<*p.get(); // segmentation fault



    return 0;
}