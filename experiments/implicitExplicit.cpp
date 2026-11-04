#include <iostream>
using namespace std;

class A{
    public:
    int a;
    A(int x){
        a = x;
    }
};

class B{
    public:
    int b;
    explicit B(int x){
        b = x;
    }
};

int foo(A obj){
    return obj.a;
}

int foo2(B obj){
    return obj.b;
}

int main(){
    cout<<foo(5); //implicit constructoion
    cout<<foo(A(5)); //explicit construction

    cout<<foo2(B(1)); //explicit in class
    cout<<foo2(1); //error
    return 0;
}