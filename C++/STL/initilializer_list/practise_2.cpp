#include <initializer_list>
#include <iostream>
#include <algorithm>

int main(){
    std::initializer_list <int> my_list = {400, 12, 1, 10};

    // The below line gives compile time error, because sort() function requires mutable iterators but the iterators passed are immutable
    // std::sort(my_list.begin(), my_list.end());

    // const_cast is a type casting operator in C++ that allows you to add or remove the const or volatile qualifiers from a variable. 
    // This operator is particularly useful when you need to modify an object that is originally declared as const, but you must do so with caution to avoid undefined behavior.
    int* arr_begin = const_cast <int*> (my_list.begin());
    std::sort(arr_begin, arr_begin + my_list.size());
    for(auto it: my_list){
        std::cout << it << " ";
    }
    std::cout << "\n";
}