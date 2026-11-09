#include <iostream>
#include <string>

//15 bytes (15 + /0 = 16bytes) and less - sso mode

int main(){
    
    std::string s = "Hello World!___";
    std::cout<<s.size()<<"\n"<<&s<<"\n"<<static_cast<void*>(s.data());

    return 0;
}
