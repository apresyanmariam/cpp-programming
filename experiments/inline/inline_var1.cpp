#include <iostream>

//running inline_var1 and inline_var2 gives multiple definition error
//if values are the same - inline int x = 1 - no multiple definition error

inline int x = 1;

void print1(){
    std::cout<<x;
}