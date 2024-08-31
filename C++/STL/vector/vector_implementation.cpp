#include <iostream>
namespace my_space{
    template <typename T> 
    class vector{
    private:
        const int maximum_size = (int)1e9;
        int reserved_size = 0;
        int actual_size = 0;
        T* arr = nullptr;
        void expand();

    public:
        vector();
        vector(int );
        vector(int, int);
        int size();
        int max_size();
        bool empty();
        void push_back(T );
        void pop_back();
        void resize(int );
        T operator[](int );
    };

    template <typename T>
    vector<T>::vector() {}

    template <typename T>
    vector<T>::vector(int n){
        reserved_size = n;
        actual_size = n;
        arr = new T[n];
    }

    template <typename T>
    vector<T>::vector(int n, int initial_value){
        reserved_size = n;
        actual_size = n;
        arr = new T[n];
        for(int i = 0; i < actual_size; i++) arr[i] = initial_value;
    }

    template <typename T> 
    int vector<T>::size(){
        return this->actual_size;
    }

    template <typename T>
    int vector<T>::max_size(){
        return this->maximum_size;
    }

    template <typename T>
    bool vector<T>::empty(){
        return actual_size == 0;
    }

    template <typename T>
    void vector<T>::expand(){
        int new_size;
        if(reserved_size == 0) new_size = 1;
        else new_size = std::min(2*reserved_size, maximum_size);
        if(reserved_size == new_size){
            throw std::runtime_error("Maximum size reached, and size cannot be increased more\n");
        }
        T* new_arr = new T[new_size];
        for(int i = 0; i < reserved_size; i++) new_arr[i] = arr[i];
        reserved_size = new_size;
        delete[] arr;
        arr = new_arr;
    }

    template <typename T>
    void vector<T>::push_back(T val){
        if(actual_size == reserved_size) expand();
        arr[actual_size++] = val;
    }

    template <typename T>
    void vector <T>::pop_back(){
        if(empty()) throw std::runtime_error("No elements are present to pop\n");
        actual_size--;
    }

    template <typename T>
    T vector <T>::operator[](int index){
        if(index < actual_size) return arr[index];
        throw std::runtime_error("Out of bound\n");
    }

    template <typename T>
    void vector <T>::resize(int new_size){
        if(new_size <= reserved_size){
            actual_size = new_size;
            return;
        }
        if(new_size > maximum_size) throw std::runtime_error("Maximum size reached\n");
        T* new_arr = new T[new_size];
        for(int i = 0; i < actual_size; i++) new_arr[i] = arr[i];
        actual_size = new_size;
        reserved_size = new_size;
        delete[] arr;
        arr = new_arr;
    }
}

int main(){
    my_space::vector <double> vec1;
    vec1.push_back(10.10);
    vec1.push_back(-11.12);

    for(int i = 0; i < vec1.size(); i++) std::cout << vec1[i] << " ";
    std::cout << "\n";

    vec1.pop_back();
    vec1.pop_back();
    vec1.pop_back();
        // gives an error

    
}