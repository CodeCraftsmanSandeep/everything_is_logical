#include <bits/stdc++.h>
#include <iostream>
#include <stack>
using namespace std;

struct Node{
    int ele1 = 100;
    int ele2 = 200;

    Node(){

    }

    Node(int a, int b): ele1(a), ele2(b){

    }
};

int main(){
    stack <int> st;

    // push
    st.push(100);
    st.push(-200);
    st.push(11);

    // pop
    st.pop();

    // top element
    cout << "top : " << st.top() << "\n";

    // size
    cout << "size : " << st.size() << "\n";

    // checking empty
    cout << "Is empty : " << (st.empty()) << "\n";

    // not allowed
    // cout << st[0] << "\n";

    // emplace and push
    stack <Node> temp;
    Node node1;
    Node node2;

    temp.push(node1);
    node1.ele1 = -1;
    cout << temp.top().ele1 << "\n";

    temp.emplace(100, 200);
    node2.ele1 = -1;
    cout << temp.top().ele1  << "\n";

    // constructor of stack from https://cplusplus.com/reference/stack/stack/stack/
    std::deque<int> mydeque (3,100);          // deque with 3 elements
    std::vector<int> myvector (2,200);        // vector with 2 elements

    std::stack<int> first;                    // empty stack
    std::stack<int> second (mydeque);         // stack initialized to copy of deque

    std::stack<int,std::vector<int> > third;  // empty stack using vector
    std::stack<int,std::vector<int> > fourth (myvector);

    cout << "fourth top ele: " << fourth.top() << "\n";
}