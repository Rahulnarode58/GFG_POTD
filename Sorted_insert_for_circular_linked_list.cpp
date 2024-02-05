// <<<<<<<<<<<<<<<<<< Sorted insert for circular linked list <<<<<<<<<<<<<<<<<<
// POTD Date 04-02-2024
// Coding_with_rahul
// Level : easy
// company : zoho

/*Given a sorted circular linked list of length n, the task is to insert a new node in this circular list so that it remains a sorted circular linked list.

Example 1:

Input:
n = 3
LinkedList = 1->2->4
(the first and last node is connected, i.e. 4 --> 1)
data = 2
Output:
1 2 2 4
Explanation:
We can add 2 after the second node.*/

class Solution
{
public:
    // Helper function to get the last node in the circular list
    Node *getLastNode(Node *head)
    {
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        return temp;
    }

    Node *sortedInsert(Node *head, int data)
    {
        if (head == NULL)
        {
            Node *newnode = new Node(data);
            newnode->next = newnode; // Point to itself in a circular list
            return newnode;
        }

        if (head->data > data)
        {
            Node *newnode = new Node(data);
            Node *last = getLastNode(head);
            newnode->next = head;
            last->next = newnode;
            return newnode;
        }

        Node *temp = head;
        while (temp->next != head && temp->next->data < data)
        {
            temp = temp->next;
        }

        Node *newnode = new Node(data);
        Node *temp1 = temp->next;
        temp->next = newnode;
        newnode->next = temp1;

        return head;
    }
};
