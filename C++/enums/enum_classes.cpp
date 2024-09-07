#include <iostream>
using namespace std;

enum class gender{
    Male,
    Female
};

enum class Male{
    boy,
    man,
    uncle
};

int main(){
    // cout << Male << "\n"; // error 
    // cout << (gender::Female) << "\n"; // this is also error

    gender obj = gender::Male;
    if(obj == gender::Female){
        cout << "Object is female\n";
    }else{
        cout << "Object is male\n";
    }
}