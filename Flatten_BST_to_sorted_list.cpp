// <<<<<<<<<<<<<<<<<< Flatten BST to sorted list <<<<<<<<<<<<<<<<<<
// POTD Date 16-02-2024
// Coding_with_rahul
// Level : Medium
// Topic : Binary SearchTree and Data Structures
// Code Written in C++

/*You are given a Binary Search Tree (BST) with n nodes, each node has a distinct value assigned to it. The goal is to flatten the tree such that, the left child of each element points to nothing (NULL), and the right child points to the next element in the sorted list of elements of the BST (look at the examples for clarity). You must accomplish this without using any extra storage, except for recursive calls, which are allowed.

Note: If your BST does have a left child, then the system will print a -1 and will skip it, resulting in an incorrect solution.

Example 1:

Input:
          5
        /    \
       3      7
      /  \    /   \
     2   4  6     8
Output: 2 3 4 5 6 7 8
Explanation:
After flattening, the tree looks
like this
    2
     \
      3
       \
        4
         \
          5
           \
            6
             \
              7
               \
                8
Here, left of each node points
to NULL and right contains the
next node.*/

class Solution
{
public:
    void inorder(Node *curr, Node *&prev)
    {
        if (curr == NULL)
            return;
        inorder(curr->left, prev);
        prev->left = NULL;
        prev->right = curr;
        prev = curr;
        inorder(curr->right, prev);
    }
    Node *flattenBST(Node *root)
    {
        Node *dummy = new Node(-1);
        Node *prev = dummy;
        inorder(root, prev);

        prev->left = NULL;
        prev->right = NULL;
        Node *ret = dummy->right;

        delete dummy;
        return ret;
    }
};