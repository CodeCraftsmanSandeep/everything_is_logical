// #include <iostream>
// using namespace std;

// template <int n>
// struct funcStruct{
//     enum {val = n * funcStruct<n-1>::val};
// };

// template <>
// struct funcStruct <0> {
//     enum {val = 1};
// };

// int main(){
//     funcStruct <5> obj;
//     cout << obj.val << "\n";
// }

#include <iostream>
using namespace std;

template <int n>
struct funcStruct{
    const static int val = n * funcStruct<n-1>::val; // the constant should be constant and static
};

template <>
struct funcStruct <0> {
    const static int val = 1;
};

int main(){
    funcStruct <5> obj;
    cout << obj.val << "\n";
}