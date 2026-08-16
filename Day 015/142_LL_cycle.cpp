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
};
class List {
    Node* head;
    Node* tail;
public:
    List() {
        head = NULL;
        tail = NULL;
    }
    void push_front(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
    }
    void push_back(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void createCycle() {
        if (head != NULL) {
            tail->next = head;
        }
    }
    Node* cycleStart() {
        Node* slow = head;
        Node* fast = head;
        bool isCycle = false;
        // Detect cycle
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                cout << "Cycle exists\n";
                isCycle = true;
                break;
            }
        }
        // No cycle
        if (!isCycle) {
            cout << "Cycle doesn't exist\n";
            return NULL;
        }
        // Find starting point of cycle
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        // Return the node where cycle starts
        return slow;
    }

    void print() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL"<<endl;
    }
};

int main() {
    List ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);

    ll.createCycle();

    Node* result = ll.cycleStart();
    if (result != NULL) {
        cout << "Cycle starts at node: " << result->data << endl;
    }
    else {
        cout << "No cycle"<<endl;
    }
    return 0;
}