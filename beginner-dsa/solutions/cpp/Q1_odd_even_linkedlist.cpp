//this code will seperate the odd and even values in linked list

#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to separate linked list into odd and even VALUE lists
void separateOddEvenValues(ListNode* head, ListNode*& oddHead, ListNode*& evenHead) {
    ListNode* oddTail = NULL;
    ListNode* evenTail = NULL;

    while (head != NULL) {
        if (head->val % 2 == 0) {
            // Even value node
            if (evenHead == NULL) {
                evenHead = evenTail = new ListNode(head->val);
            } else {
                evenTail->next = new ListNode(head->val);
                evenTail = evenTail->next;
            }
        } else {
            // Odd value node
            if (oddHead == NULL) {
                oddHead = oddTail = new ListNode(head->val);
            } else {
                oddTail->next = new ListNode(head->val);
                oddTail = oddTail->next;
            }
        }
        head = head->next;
    }
}

// Function to print linked list
void printList(ListNode* head) {
    if (!head) {
        cout << "Empty List";
        return;
    }
    while (head != NULL) {
        cout << head->val;
        if (head->next != NULL) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Function to create a linked list from user input
ListNode* createList(int n) {
    if (n <= 0) return NULL;

    int val;
    cout << "Enter value for node 1: ";
    cin >> val;
    ListNode* head = new ListNode(val);
    ListNode* current = head;

    for (int i = 2; i <= n; i++) {
        cout << "Enter value for node " << i << ": ";
        cin >> val;
        current->next = new ListNode(val);
        current = current->next;
    }
    return head;
}

// ---- Driver Code ----
int main() {
    int n;
    cout << "Enter number of nodes in the linked list: ";
    cin >> n;

    if (n <= 0) {
        cout << "Linked list is empty!" << endl;
        return 0;
    }

    ListNode* head = createList(n);

    cout << "\nOriginal Linked List:" << endl;
    printList(head);

    ListNode* oddHead = NULL;
    ListNode* evenHead = NULL;

    // Separate odd and even value lists
    separateOddEvenValues(head, oddHead, evenHead);

    cout << "\nLinked List with Odd Numbers:" << endl;
    printList(oddHead);

    cout << "\nLinked List with Even Numbers:" << endl;
    printList(evenHead);

    return 0;
}
