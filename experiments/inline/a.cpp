#include <iostream>
#include "inline_def.h"
using namespace std;

//using the same func in two dif files, with inline definition in header gives no multiple definition


int main(){
    cout<<sum(1, 2);
    return 0;
}