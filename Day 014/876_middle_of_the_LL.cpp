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
    int middleEle() {
        Node* slow = head;
        Node* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
    }
};
int main() {
    List l1;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(4);
    l1.push_back(5);
    l1.push_back(6);
    cout << "middle element of LL = " << l1.middleEle() << endl;
    return 0;
}