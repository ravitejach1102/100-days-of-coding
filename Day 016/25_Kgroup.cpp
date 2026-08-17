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
public:
    Node* head;
    Node* tail;
    List() {
        head = NULL;
        tail = NULL;
    }
    void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
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
    Node* reverseKGroup(Node* head, int k) {
    Node* temp = head;
    int cnt = 0;

    // Check whether k nodes are available
    while (cnt < k) {
        if (temp == NULL) {
            return head;
        }

        temp = temp->next;
        cnt++;
    }

    // Reverse remaining groups
    Node* prevNode = reverseKGroup(temp, k);

    temp = head;
    cnt = 0;

    while (cnt < k) {
        Node* next = temp->next;
        temp->next = prevNode;

        prevNode = temp;
        temp = next;
        cnt++;
    }

    return prevNode;
} 
};
int main() {
    List l;

    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    l.push_back(6);

    cout << "Original List: ";
    l.printList();

    int k = 2;

    l.head = l.reverseKGroup(l.head, k);

    cout << "After Reverse in Groups: ";
    l.printList();

    return 0;
}