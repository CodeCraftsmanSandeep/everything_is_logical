#include <iostream>
#include <initializer_list>

namespace my_space{
    template <typename T> 
    class vector{
    private:
        const int maximum_size = (int)1e9;
        int reserved_size = 0;                  // capacity
        int actual_size = 0;                    // size
        T* arr = nullptr;
        void expand();

    public:
        vector();
        vector(int );                       // size 
        vector(int, T);                     // size, initial_value
        vector(const vector <T>& );         // vector is created with assignment operator
        vector(std::initializer_list <T>);  // initialized
        ~vector();

        int capacity() const;
        int size() const;
        int max_size() const;
        bool empty() const ;
        void push_back(T );
        void pop_back();
        void resize(int );
        void reserve(int );
        T& operator[](int ) const;
        vector <T>& operator=(const vector <T>& );
    };

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
    vector<T>::~vector() {delete[] arr; }

    // custom construtor with no initialization
    template <typename T>
    vector<T>::vector() {}

    // custom constructor with size
    template <typename T>
    vector<T>::vector(int n){
        reserved_size = n;
        actual_size = n;
        arr = new T[n];
    }

    // custom constructor with size, initial_value
    template <typename T>
    vector<T>::vector(int n, T initial_value){
        reserved_size = n;
        actual_size = n;
        arr = new T[n];
        for(int i = 0; i < actual_size; i++) arr[i] = initial_value;
    }

    // custom constructor with assignment operator
    template <typename T>
    vector<T>::vector(const vector <T>& obj){
        this->arr = new T[obj.size()];
        for(int i = 0; i < obj.size(); i++) this->arr[i] = obj[i];
        this->actual_size = obj.size();
        this->reserved_size = obj.size();
    }

    template <typename T>
    vector<T>::vector(std::initializer_list <T> list){
        int n = list.size();
        this->arr = new T[n];
        reserved_size = n;
        actual_size = n;
        int i = 0;
        for(auto ele: list) this->arr[i++] = ele;
    }

    template <typename T>
    int vector<T>::capacity() const{
        return this->reserved_size;
    }

    template <typename T> 
    int vector<T>::size() const{
        return this->actual_size;
    }

    template <typename T>
    int vector<T>::max_size() const{
        return this->maximum_size;
    }

    template <typename T>
    bool vector<T>::empty() const {
        return actual_size == 0;
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

    // rvalue
    template <typename T>
    T& vector <T>::operator[](int index) const{
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


    template <typename T>
    void vector <T>::reserve(int n){
        // reserving space for atleat n elements
        if(n <= reserved_size) return;
        T* new_arr = new T[n];
        for(int i = 0; i < actual_size; i++) new_arr[i] = arr[i];
        reserved_size = n;
        delete[] arr;
        arr = new_arr;
    }

    // assignment operation
    template <typename T>
    vector <T>& vector<T>::operator=(const vector <T>& obj){
        if(this == &obj){
            // self-assignment check
            return *this;
        }
        delete[] arr;
        arr = new T[obj.size()];
        reserved_size = obj.size();
        actual_size = obj.size();
        for(int i = 0; i < obj.size(); i++) arr[i] = obj[i]; // copying elements
        return *this;
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
    // vec1.pop_back(); // gives a run-time error
    std::cout << "Size: " << vec1.size() << "\n";

    for(int i = 100; i < 200; i++) vec1.push_back(i);
    std::cout << "Size: "  << vec1.size() << "\n";

    my_space::vector <double> vec2 = vec1;
    std::cout << vec1.size() << "\n";

    my_space::vector <double> vec3 = {1, 2, 3};
    vec2 = vec3;
    vec2[0] = 100;
    std::cout << "Size: " << vec2.size() << "\n";
    std::cout << vec2[0] << "\n";
    
    my_space::vector <double> vec4(vec3);
    std::cout << "Size: " << vec4.size() << "\n";

    my_space::vector <std::string> vec5(10, "sandeep");
    std::cout << vec5[0] << "\n";
}