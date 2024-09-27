/*
Merge sort of doubly linked list
Time: T(n) = 2T(n/2) + n/2 + n
      which is O(nlogn)
Auxillary space: O(logn)
*/
class Solution {
    void print(Node* head){
        while(head != nullptr){
            cout << head->data << " ";
            head = head->next;
        }
        cout << "\n";
    }
  public:
    Node* find_mid(Node* head){
        if(head == nullptr) return nullptr;
        
        Node* mid = head;
        Node* slow = head;
        Node* fast = head;
        
        while(fast != nullptr){
            mid = slow;
            slow = slow->next;
            fast = fast->next;
            if(fast != nullptr) fast = fast->next;
        }
        
        return mid;
    }
    
    Node* merge(Node* head1, Node* head2, bool inc){
        if(head1 == nullptr) return head2;
        if(head2 == nullptr) return head1;
        
        Node* trav1 = head1;
        Node* trav2 = head2;
        
        Node* head;
        if((trav2->data < trav1->data) == inc){
            head = trav2;
            trav2 = trav2->next;
        }else{
            head = trav1;
            trav1 = trav1->next;
        }
        Node* tail = head;
        tail->next = nullptr;
        
        while(trav1 != nullptr && trav2 != nullptr){
            if((trav1->data <= trav2->data) == inc){
                tail->next = trav1;
                trav1->prev = tail;
                
                trav1 = trav1->next;
            }else{
                tail->next = trav2;
                trav2->prev = tail;
                
                trav2 = trav2->next;
            }
            tail = tail->next;
            tail->next = nullptr;
        }
        if(trav1 == nullptr){
            tail->next = trav2;
            if(trav2 != nullptr) trav2->prev = tail;
        }
        if(trav2 == nullptr){
            tail->next = trav1;
            if(trav1 != nullptr) trav1->prev = tail;
        }
        return head;
    }
    
    Node* merge_sort(struct Node* head, bool inc){
        if(head == nullptr) return nullptr;
        if(head->next == nullptr) return head;

        Node* mid = find_mid(head);
        Node* next_trav = mid->next;

        mid->next = nullptr;
        if(next_trav != nullptr) next_trav->prev = nullptr;

        Node* new_head1 = merge_sort(head, inc);
        Node* new_head2 = merge_sort(next_trav, inc);
        
        return merge(new_head1, new_head2, inc);
    }
    
    struct Node *sortDoubly(struct Node *head) {
        head = merge_sort(head, true);
        
        return head;
    }
};