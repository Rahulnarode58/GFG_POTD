// <<<<<<<<<<<<<<<<<< Check for Children Sum Property in a Binary Tree <<<<<<<<<<<<<<<<<<
// POTD Date 09-02-2024
// Coding_with_rahul
// Level : medium
// company : Intuit

/*Given a binary tree having n nodes. Check whether all of its nodes have the value equal to the sum of their child nodes. Return 1 if all the nodes in the tree satisfy the given properties, else it return 0.

For every node, data value must be equal to the sum of data values in left and right children. Consider data value as 0 for NULL child.  Also, leaves are considered to follow the property.

Example 1:

Input:
Binary tree
       35
      /   \
     20  15
    /  \  /  \
   15 5 10 5
Output:
1
Explanation:
Here, every node is sum of its left and right child.*/

class Solution
{
public:
    // Function to check whether all nodes of a tree have the value
    // equal to the sum of their child nodes.

    bool f(Node *root)
    {
        if (root == NULL)
            return true;
        if (!root->left && !root->right)
            return true;

        bool left = true;
        bool right = true;

        int sum = 0;
        if (root->left != NULL)
        {
            sum += root->left->data;
            if (f(root->left) == false)
                return false;
        }
        if (root->right != NULL)
        {
            sum += root->right->data;
            if (f(root->right) == false)
                return false;
        }

        return root->data == sum;
    }
    int isSumProperty(Node *root)
    {
        // Add your code here
        return f(root);
    }
};