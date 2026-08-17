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
    Node* mergeTwoLists(Node* head1,Node* head2){
        if(head1==NULL || head2==NULL){
            if(head1 == NULL){
                    return head2;
                }else{
                    return head1;
                }
        }
        if(head1->data <= head2->data){
            head1->next=mergeTwoLists(head1->next,head2);
            return head1;
        }else{
            head2->next=mergeTwoLists(head1,head2->next);
            return head2;
        }
    }
};
int main() {
    List l1, l2;

    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(4);

    l2.push_back(1);
    l2.push_back(3);
    l2.push_back(4);

    cout << "List 1: ";
    l1.printList();

    cout << "List 2: ";
    l2.printList();

    l1.head = l1.mergeTwoLists(l1.head, l2.head);

    cout << "Merged List: ";
    l1.printList();

    return 0;
}