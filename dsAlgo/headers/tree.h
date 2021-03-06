#ifndef DSALGO_TREE_H
#define DSALGO_TREE_H

#include <iostream>
#include <queue>

using namespace std;

typedef struct node {
    int data;
    struct node *left, *right;
} node;

class tree {
public:
    node *newNode(int data); // Create new node
    int giveHeightOfTree(node *start); // give height of tree
    int giveNumberOfElements(node *start); // give number of elements in tree
    void printElementsAtAGivenHeight(node *start, int height); // print elements of a tree at a given height

    /* METHOD 1 Level Order Traversal (Breadth order traversal) Print element at each height

      // Function to print level order traversal of tree
        printLevelorder(tree)
            for d = 1 to height(tree)
            printGivenLevel(tree, d);

      // Function to print all nodes at a given level
        printGivenLevel(tree, level)
            if tree is NULL then return;
            if level is 1, then
                print(tree->data);
            else if level greater than 1, then
                printGivenLevel(tree->left, level-1);
                printGivenLevel(tree->right, level-1);

        Time Complexity: O(n^2) in worst case. For a skewed tree, printGivenLevel() takes O(n) time where n is the number of nodes in the skewed tree. So time complexity of printLevelOrder() is O(n) + O(n-1) + O(n-2) + .. + O(1) which is O(n^2).
     */
    void printLevelOrderTraversalMethod1(node *start);


    /*
      METHOD 2 Level Order Traversal (Breadth order traversal) Use Queue
      printLevelorder(tree)
          1) Create an empty queue q
          2) temp_node = root //start from root
              3) Loop while temp_node is not NULL
              a) print temp_node->data.
              b) Enqueue temp_node’s children (first left then right children) to q
              c) Dequeue a node from q and assign it’s value to temp_node
                  Time Complexity: O(n) where n is number of nodes in the binary tree
   */
    void printLevelOrderTraversalMethod2(node *start);

};

#endif //DSALGO_TREE_H
