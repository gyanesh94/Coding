#include <iostream>

using namespace std;

typedef struct node {
    int data;
    struct node *next;
} node;

int countNodes(node *head) {
    int count = 0;

    while (head) {
        count++;
        head = head->next;
    }

    return count;
}

node *addNode(node *head, int data) {
    node *newNode = new node;
    node *temp = head;
    newNode->data = data;
    newNode->next = NULL;
    if (temp == NULL) {
        return newNode;
    }
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;

    return head;
}

void printLinkedList(node *head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
}

void mergeLinkedList(node *head1, node **head2){
    node *head2Curr = *head2;
    node *head1Next, *head2Next;

    while (head1 != NULL && head2Curr != NULL) {
        head1Next = head1->next;
        head2Next = head2Curr->next;

        head1->next = head2Curr;
        head2Curr->next = head1Next;

        head1 = head1Next;
        head2Curr = head2Next;
    }

    *head2 = head2Curr;
}

int main (){
    node *head1 = NULL, *head2 = NULL;

    head1 = addNode(head1, 1);
    head1 = addNode(head1, 2);
    head1 = addNode(head1, 3);
    cout << "First Linked List:\n";
    printLinkedList(head1);

    head2 = addNode(head2, 4);
    head2 = addNode(head2, 5);
    head2 = addNode(head2, 6);
    head2 = addNode(head2, 7);
    head2 = addNode(head2, 8);
    cout << "\nSecond Linked List:\n";
    printLinkedList(head2);

    mergeLinkedList(head1, &head2);

    cout << "\nModified First Linked List:\n";
    printLinkedList(head1);

    cout << "\nModified Second Linked List:\n";
    printLinkedList(head2);
}