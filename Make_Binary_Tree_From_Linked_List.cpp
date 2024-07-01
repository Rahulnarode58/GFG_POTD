// <<<<<<<<<<<<<<<<<< Swapping pairs make sum equal <<<<<<<<<<<<<<<<<<
// POTD Date 01-07-2024
// Coding_with_Rahul
// Level : Medum
// Company : Amazon
// Topic : Queue , Tree, Data Structures , Linked List

/* Given a Linked List Representation of Complete Binary Tree. The task is to construct the Binary tree and print the level order traversal of the Binary tree.
Note: The complete binary tree is represented as a linked list in a way where if the root node is stored at position i, its left, and right children are stored at position 2*i+1, and 2*i+2 respectively. H is the height of the tree and this space is used implicitly for the recursion stack.

Examples:

Input: n = 5, k = 1->2->3->4->5
Output: 1 2 3 4 5
Explanation: The tree would look like
      1
    /   \
   2     3
 /  \
4   5
Now, the level order traversal of
the above tree is 1 2 3 4 5. */

/* CODE */

// Function to make binary tree from linked list.

TreeNode *solve(vector<int> &arr, int i)
{
    // base case
    if (i >= arr.size())
        return NULL;
    TreeNode *newNode = new TreeNode(arr[i]);
    newNode->left = solve(arr, 2 * i + 1);
    newNode->right = solve(arr, 2 * i + 2);
    return newNode;
}

void convert(Node *head, TreeNode *&root)
{
    // Your code here
    vector<int> arr;
    Node *temp = head;
    while (temp != NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }
    root = solve(arr, 0);
}
