#include "tree.h"

node *tree::newNode(int data) {
    node *ptr = new node();
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

int tree::giveHeightOfTree(node *start) {
    if (start == NULL)
        return 0;
    else {
        /* compute the height of each subtree */
        int leftTreeHeight = giveHeightOfTree(start->left);
        int rightTreeHeight = giveHeightOfTree(start->right);

        /* use the larger one */
        if (leftTreeHeight > rightTreeHeight) {
            return (leftTreeHeight + 1);
        }
        else {
            return (rightTreeHeight + 1);
        }
    }
}

int tree::giveNumberOfElements(node *start) {
    if (start == NULL)
        return 0;
    else {
        /* compute the elements in each subtree */
        int leftTreeElements = giveNumberOfElements(start->left);
        int rightTreeElements = giveNumberOfElements(start->right);

        return (leftTreeElements + rightTreeElements + 1);
    }
}

void tree::printElementsAtAGivenHeight(node *start, int height) {
    if (start == NULL)
        return;
    if (height == 1) {
        cout << start->data << "\t";
    }
    if (height > 1) {
        printElementsAtAGivenHeight(start->left, height - 1);
        printElementsAtAGivenHeight(start->right, height - 1);
    }
}


void tree::printLevelOrderTraversalMethod1(node *start) {
    int heightOfTree = giveHeightOfTree(start);
    for (int i = 1; i <= heightOfTree; i++) {
        printElementsAtAGivenHeight(start, i);
        cout << endl;
    }
}