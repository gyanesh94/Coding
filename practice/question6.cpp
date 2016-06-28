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

// My own
node *reverseLinkedListMyOwn(node *head, int k) {
    if (k == 1 || head == NULL || head->next == NULL) {
        return head;
    }
    int tmpK = k;
    node *prev, *curr, *next;
    prev = NULL;
    curr = head;
    while (curr && tmpK-- != 0) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    if (next != NULL) {
        next = reverseLinkedListMyOwn(next, k);
        while (prev->next != NULL) {
            prev = prev->next;
        }
        prev->next = next;
    }
    return head;
}

node *reverseLinkedListGeeksForGeeks(node *head, int k) {
    if (k == 1 || head == NULL || head->next == NULL) {
        return head;
    }
    int tmpK = k;
    node *prev, *curr, *next;
    prev = NULL;
    curr = head;
    while (curr && tmpK-- != 0) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    // Untill Here Prev contain Starting Element of the list
    // Head contains Last element of the list
    if (next != NULL) {
        next = reverseLinkedListGeeksForGeeks(next, k);
        head->next = next;
    }
    return prev;
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

    head = reverseLinkedListGeeksForGeeks(head, 3);

    cout << "\nReversed Linked List\n";
    printLinkedList(head);

}