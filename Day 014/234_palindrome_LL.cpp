#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
    ~Node() {
        if (next != NULL) {
            delete next;
            next = NULL;
        }
    }
};
class List {
    Node* head;
    Node* tail;
public:
    List() {
        head = NULL;
        tail = NULL;
    }
    ~List() {
        if (head != NULL) {
            delete head;
            head = NULL;
        }
    }
    void push_back(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    bool palindrome() {
    // Find the middle
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half
    Node* curr = slow;
    Node* prev = NULL;

    while (curr != NULL) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // Compare first half and reversed second half
    Node* front = head;
    Node* back = prev;

    while (back != NULL) {
        if (front->data != back->data) {
            return false;
        }

        front = front->next;
        back = back->next;
    }

    return true;
}
};
int main(){
     List l1;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(2);
    l1.push_back(1);
    int result=l1.palindrome();
    if(result){
        cout<<"true";
    }else{
        cout<<"false";
    }
    return 0;
}