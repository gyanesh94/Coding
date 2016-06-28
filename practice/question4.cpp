#include <stdio.h>
#include <stdlib.h>

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
    node *newNode = (node *) malloc(sizeof(node));
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

node *pushNodeToFront(node *head, int data) {
    node *newNode = (node *) malloc(sizeof(node));
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

node *sumTwoNode(node *head1, node *head2, int diff) {
    node *result = NULL;
    int sum = 0, tempDigit;

    // first list is empty
    if (head1 == NULL) {
        return head2;
    }// second list is empty
    else if (head2 == NULL) {
        return head1;
    }

    while (diff--) {
        sum = (sum * 10) + head1->data;
        head1 = head1->next;
    }

    while (head1 && head2) {
        sum = (sum * 10) + head1->data + head2->data;
        head1 = head1->next;
        head2 = head2->next;
    }

    while (sum) {
        tempDigit = sum % 10;
        result = pushNodeToFront(result, tempDigit);
        sum = sum / 10;
    }

    return result;
}

node *sumRecurForSameSizeList(node *head1, node *head2, int *carry) {
    node *tempResult = (node *)malloc(sizeof(node));
    int sum = 0;

    if (head1 == NULL) {
        return NULL;
    }

    tempResult->next = sumRecurForSameSizeList(head1->next, head2->next, carry);
    sum = head1->data + head2->data + *carry;
    tempResult->data = sum % 10;
    *carry = sum / 10;

    return tempResult;
}


void sumRemaining(node** result, node *head, int diff, int *carry) {
    int sum;
    if (diff > 0){
        sumRemaining(result, head, --diff, carry);
        sum = head->data + *carry;
        *carry = sum / 10;
        *result = pushNodeToFront(*result, sum % 10);
    }
}

node *sumTwoNodeUsingRecursion(node *head1, node *head2, int diff) {
    node **result, *tempHead1 = head1;
    int sum = 0, tempDiff = diff, carry = 0;

    // first list is empty
    if (head1 == NULL) {
        return head2;
    }// second list is empty
    else if (head2 == NULL) {
        return head1;
    }

    while (tempDiff > 0) {
        tempHead1 = tempHead1->next;
        tempDiff--;
    }

    (*result) = sumRecurForSameSizeList(tempHead1, head2,  &carry);

    sumRemaining(result, head1, diff, &carry);

    return *result;

}

void printList(node *head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    };
}

int main() {
    node *head1 = NULL, *head2 = NULL, *result = NULL;
    int head1Count, head2Count;

    head1 = addNode(head1, 5);
    head1 = addNode(head1, 6);
    head1 = addNode(head1, 3);

    head2 = addNode(head2, 8);
    head2 = addNode(head2, 4);
    head2 = addNode(head2, 2);
    head2 = addNode(head2, 2);

    head1Count = countNodes(head1);
    head2Count = countNodes(head2);

    if (head1Count >= head2Count) {
        result = sumTwoNodeUsingRecursion(head1, head2, head1Count - head2Count);
    } else {
        result = sumTwoNodeUsingRecursion(head2, head1, head2Count - head1Count);
    }

    printList(result);

    return 0;
}