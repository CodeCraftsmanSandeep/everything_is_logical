#include <iostream>
#include <initializer_list>
#include <iomanip>
using namespace std;

template <typename T = int> 
class my_data{
private:
    T* arr;
    int size;
public:
    my_data(initializer_list <T> list){
        arr = new T[list.size()];
        size = 0;
        for(auto it = list.begin(); it != list.end(); it++){
            arr[size++] = *it;
        }
    }
    void print_data(){
        for(int i = 0; i < size; i++) cout << setprecision(6) << fixed << arr[i] << " ";
        cout << "\n";
    }

    ~my_data(){
        delete[] arr;
    }
};

int main(){
    // initilializing the object

    my_data <float> obj({4, 2, 2, 10});
    obj.print_data();

    cout << "\n";

    my_data <float> second_obj = {4, 3, 2};
    second_obj.print_data();
}