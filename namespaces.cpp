#include <iostream>
using namespace std;

namespace namespace1{
    void say_hello(){
        std::cout << "vra4ev e edno jujence!" << std::endl;
    }
    namespace inner_namespace1{
    void say_hello(){
        std::cout << "vra4ev e inner jujence!" << std::endl;
    }
}
}
namespace namespace2{
    void say_hello(){
        std::cout << "vra4ev e dve jujence!" << std::endl;
    }
}
using namespace namespace1;
int main(){
    say_hello();
    namespace2::say_hello();
    inner_namespace1::say_hello();
}
