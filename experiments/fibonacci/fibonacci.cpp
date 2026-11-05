#include <iostream>
using namespace std;

template<int n>


int fib_nums(){
    return fib_nums<n-1>() + fib_nums<n-2>();
}

template<>
int fib_nums<0>(){
    return 1;
}

template<>
int fib_nums<1>(){
    return 1;
}

int main(){
    cout<<fib_nums<4>();

    return 0;
}