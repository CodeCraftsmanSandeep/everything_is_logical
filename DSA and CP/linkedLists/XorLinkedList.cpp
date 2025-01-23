#include <bits/stdc++.h>
using  namespace std;

class XORLinkedList;

class Node{
private:
    int data;
    Node* both; // xor of both next and prev

public:
    Node(int data){
        this->data = data;
        both = nullptr;
    }

    friend class XORLinkedList;
};

// sorted xor linked list
class XORLinkedList{
private:
    Node* head = nullptr;
    Node* XOR(Node* left, Node* right);
public:
    void insert_data(int data);    
    void delete_data(int data);
    void print_list();
};

Node* XORLinkedList::XOR(Node* left, Node* right){
    return (Node*)((uintptr_t)(left) ^ (uintptr_t)(right));
}

void XORLinkedList::insert_data(int data){
    Node* curr = new Node(data);
    Node* trav = head;
    Node* prev = nullptr;
    while(trav != nullptr){
        Node* curr = trav;
        if(trav->data < data){
            trav = XOR(prev, trav->both);
        }else{
            break;
        }
        prev = curr;
    }
    curr->both = XOR(prev, trav);
    if(prev != nullptr) prev->both = XOR(curr, XOR(prev->both, trav));
    if(trav != nullptr) trav->both = XOR(curr, XOR(trav->both, prev));
    if(head == trav) head = curr;
}

void XORLinkedList::delete_data(int data){
    Node* trav = head;
    Node* prev = nullptr;
    while(trav != nullptr && trav->data <= data){
        Node* next_trav = XOR(trav->both, prev);
        if(trav->data == data){
            if(prev != nullptr) prev->both = XOR(next_trav, XOR(prev->both, trav));
            if(next_trav != nullptr) next_trav->both = XOR(prev, XOR(next_trav->both, trav));
            if(trav == head) head = next_trav;
            delete trav;
            return;
        }
        prev = trav;
        trav = next_trav;
    }
    return;
}

void XORLinkedList::print_list(){
    if(head == nullptr){
        cout << "Empty linked list\n";
        return;
    }
    Node* trav = head;
    Node* prev = nullptr;
    while(trav != nullptr){
        cout << trav->data << " ";
        Node* curr = trav;
        trav = XOR(prev, trav->both);
        prev = curr;
    }
    cout << "\n";
}

int main(){
    int n;
    cin >> n;

    XORLinkedList l;

    while(n--){
        char op;
        cin >> op;

        if(op == '?'){
            l.print_list();
            continue;
        }

        int num;
        cin >> num;

        if(op == '+') l.insert_data(num);
        else if(op == '-') l.delete_data(num);
    }
}