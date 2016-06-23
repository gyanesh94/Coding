#include "headers/tree.cpp"

int main() {
    tree tree;
    node *start = tree.newNode(2);
    start->left = tree.newNode(3);
    start->left->left = tree.newNode(8);
    start->right = tree.newNode(5);
    start->right->left = tree.newNode(10);
    start->right->right = tree.newNode(11);
    tree.printLevelOrderTraversalMethod1(start);
    return 0;
}