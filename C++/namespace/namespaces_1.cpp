#include <iostream>

namespace sandeep{
    int x = 10;
}
// aliasing namespaces in c++
namespace sd = sandeep;
int x = 20;

int main(){
    std::cout << sd::x << "\n";
}