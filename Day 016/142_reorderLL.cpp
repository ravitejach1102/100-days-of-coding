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
    Node* splitAtMid(Node* head) {
        Node* slow = head;
        Node* fast = head;
        Node* prev = NULL;
        while (fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (prev != NULL) {
            prev->next = NULL;
        }
        return slow;
    }
    Node* reverse(Node* head) {
        Node* curr = head;
        Node* prev = NULL;
        while (curr != NULL) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    void reorderList() {
        Node* rightHead = splitAtMid(head);
        Node* rightHeadRev = reverse(rightHead);
        Node* left = head;
        Node* right = rightHeadRev;
        while (left != NULL && right != NULL) {
            Node* nextLeft = left->next;
            Node* nextRight = right->next;
            
            left->next = right;
            right->next = nextLeft;

            tail=right;

            left = nextLeft;
            right = nextRight;
        }
        if(right!=NULL){
            tail->next=right;
        }
    }
};

int main() {

    List l1;

    l1.push_front(5);
    l1.push_front(4);
    l1.push_front(3);
    l1.push_front(2);
    l1.push_front(1);

    cout << "Original List: ";
    l1.printList();

    l1.reorderList();

    cout << "Reordered List: ";
    l1.printList();

    return 0;
}


// class Solution {
// public:
//     ListNode* splitAtMid(ListNode* head) {
//         ListNode* slow = head;
//         ListNode* fast = head->next;

//         while (fast != NULL && fast->next != NULL) {
//             slow = slow->next;
//             fast = fast->next->next;
//         }

//         ListNode* rightHead = slow->next;
//         slow->next = NULL;

//         return rightHead;
//     }

//     ListNode* reverse(ListNode* head) {
//         ListNode* curr = head;
//         ListNode* prev = NULL;

//         while (curr != NULL) {
//             ListNode* next = curr->next;

//             curr->next = prev;
//             prev = curr;
//             curr = next;
//         }

//         return prev;
//     }

//     void reorderList(ListNode* head) {
//         ListNode* rightHead = splitAtMid(head);
//         ListNode* rightHeadRev = reverse(rightHead);

//         ListNode* left = head;
//         ListNode* right = rightHeadRev;

//         while (left != NULL && right != NULL) {
//             ListNode* nextLeft = left->next;
//             ListNode* nextRight = right->next;

//             left->next = right;
//             right->next = nextLeft;

//             left = nextLeft;
//             right = nextRight;
//         }
//     }
// };