// <<<<<<<<<<<<<<<<<< Check if all leaves are at same level <<<<<<<<<<<<<<<<<<
// POTD Date 08-02-2024
// Coding_with_rahul
// Level : easy
// company : Amazon

/*Given a binary tree with n nodes, determine whether all the leaf nodes are at the same level or not. Return true if all leaf nodes are at the same level, and false otherwise.

Example 1:

Input:
Tree:
    1
   / \
  2   3
Output:
true
Explanation:
The binary tree has a height of 2 and the leaves are at the same level.*/

class Solution
{
public:
    /*You are required to complete this method*/
    bool check(Node *root)
    {
        // Your code here
        if (root == NULL)
            return true;

        queue<Node *> q;
        q.push(root);
        int level = 0;
        int leaf = -1;
        while (!q.empty())
        {
            int n = q.size();
            level++;

            for (int i = 0; i < n; i++)
            {
                Node *curr = q.front();
                q.pop();

                if (!curr->left && !curr->right)
                {
                    // i have encountered a leaf node
                    if (leaf == -1)
                    {
                        leaf = level;
                    }
                    else if (leaf != level)
                    {
                        return false;
                    }
                }

                if (curr->left)
                {
                    q.push(curr->left);
                }
                if (curr->right)
                {
                    q.push(curr->right);
                }
            }
        }
        return true;
    }
};
