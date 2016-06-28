/* Created Linked list is 1->2->3->4->5->6->7->8->9 */

#include <iostream>

using namespace std;

typedef struct node {
    int data;
    struct node *next;
} node;

void addNode(node **head, int data) {
    node *newNode = new node;
    node *temp = *head;
    newNode->data = data;
    newNode->next = NULL;
    if (temp == NULL) {
        *head = newNode;
        return;
    }
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printLinkedList(node *head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
}

// O(n^2)
node *reverseLinkedListRecursiveLong(node *head) {
    if (head == NULL) {
        return NULL;
    }
    node *tempNode, *result;
    if (head->next != NULL) {
        result = reverseLinkedListRecursiveLong(head->next);
    } else {
        return head;
    }
    tempNode = result;
    while (tempNode->next != NULL) {
        tempNode = tempNode->next;
    }
    tempNode->next = head;
    head->next = NULL;
    return result;
}

// O(n)
void reverseLinkedListRecursiveShort(node **head) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }
    node *first = (*head);
    node *rest = first->next;
    reverseLinkedListRecursiveShort(&rest);
    first->next->next = first;
    first->next = NULL;
    *head = rest;
    return;
}

// O(n)
node *reverseLinkedListIterative(node *head) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == NULL) {
        return head;
    }
    node *prev, *curr, *next;
    prev = NULL;
    curr = head;
    while (curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}

int main() {
    node *head = NULL;

    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);
    addNode(&head, 5);
    addNode(&head, 6);
    addNode(&head, 7);
    addNode(&head, 8);
    addNode(&head, 9);

    cout << "Actual Linked List\n";
    printLinkedList(head);

//    head = reverseLinkedListIterative(head);
    reverseLinkedListRecursiveShort(&head);

    cout << "\nReversed Linked List\n";
    printLinkedList(head);

    return 0;
}