// <<<<<<<<<<<<<<<<<< Count the nodes at distance K from leaf <<<<<<<<<<<<<<<<<<
// POTD Date 06-02-2024
// Coding_with_rahul
// Level : Medium
// company : Flipkart

/*Given a binary tree with n nodes and a non-negative integer k, the task is to count the number of special nodes.
A node is considered special if there exists at least one leaf in its subtree such that the distance between the node and leaf is exactly k.

Note: Any such node should be counted only once. For example, if a node is at a distance k from 2 or more leaf nodes, then it would add only 1 to our count.

Example 1:

Input:
Binary tree
        1
      /   \
     2     3
   /  \   /  \
  4   5  6    7
          \
          8
k = 2
Output:
2
Explanation:
There are only two unique nodes that are at a distance of 2 units from the leaf node. (node 3 for leaf with value 8 and node 1 for leaves with values 4, 5 and 7) Note that node 2 isn't considered for leaf with value 8 because it isn't a direct ancestor of node 8.*/

class Solution
{
public:
    int check(Node *node, int k, int d)
    {
        if (node->left == NULL && node->right == NULL)
        {
            if (d == k)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

        int c = 0;
        if (node->left)
        {
            c = c | check(node->left, k, d + 1);
        }
        if (node->right)
        {
            c = c | check(node->right, k, d + 1);
        }

        return c;
    }

    int traverse(Node *root, int k)
    {
        if (root == NULL)
            return 0;
        int ans = 0;
        if (check(root, k, 0))
        {
            ans++;
        }
        ans += traverse(root->left, k);
        ans += traverse(root->right, k);

        return ans;
    }

    // Function to return count of nodes at a given distance from leaf nodes.
    int printKDistantfromLeaf(Node *root, int k)
    {
        // Add your code here.
        int ans = 0;
        ans += traverse(root, k);
        return ans;
    }
};
