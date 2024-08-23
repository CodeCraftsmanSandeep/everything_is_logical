#include <iostream>
#include <vector>
#include <set>
using namespace std;

void iterating(){
    // local struct
    struct Node{
        int data;
        int parent;
        Node(int data, int parent){
            this->data = data;
            this->parent = parent;
        }
    };

    auto custom_cmp = [](const Node& nd1, const Node& nd2){
        return (nd1.data < nd2.data) || ((nd1.data == nd2.data) && (nd1.parent < nd2.parent));
    };

    set <Node, decltype(custom_cmp)> st1(custom_cmp);
    st1.insert(Node(1, 2));
    st1.insert(Node(2, 3));
    st1.insert(Node(1, 3));
    st1.insert(Node(1, 2));
    cout << st1.size() << "\n"; // output: 3
    // note that Node(1, 2) is inserted only once
    // that's my boy!!

    set <Node, decltype(custom_cmp)> st2(custom_cmp);
    // the following line gives error in lower versions of C++ compiler
    // but in C++ 20 it is working
    // to make work in lower functions, we have to write operator() in struct and use it instead of using lamda function as comparator in set
    st2 = st1;

    // [] based access in not allowed
    // below line gives compilation error
    // cout << st1[0] << "\n";

    cout << "Range based loop(copy): ";
    for(auto ele: st1){
        cout << ele.data << " ";
        ele.data = 100; // this will not change the data in st1, becuase ele is just a copy of the data in st1
    }
    cout << "\n";


    cout << "Range based loop(reference): ";
    for(auto &ele: st1){
        cout << ele.data << " ";
        // ele.data = -10000; // gives compilation error, because std::set elements are const (due to the nature of the container enforcing uniqueness and ordering), you can't modify the elements directly.
    }
    cout << "\n";

    cout << "Thorugh iteration: ";
    for(auto it = st1.begin(); it != st1.end(); it++){
        // cout << it->data << " ";
        // (or) euivalently
        cout << (*it).data << " ";
    }
    cout << "\n";
}

int main(){
    // different types of iterating in c++
    iterating();
}