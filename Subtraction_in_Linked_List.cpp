
// <<<<<<<<<<<<<<<<<< Subtraction in Linked List <<<<<<<<<<<<<<<<<<
// POTD Date 04-02-2024
// Coding_with_rahul
// Level : Hard
// company : Amazon

/*You are given two linked lists that represent two large positive numbers. From the two numbers represented by the linked lists, subtract the smaller number from the larger one. Look at the examples to get a better understanding of the task.

Example 1:

Input:
L1 = 1->0->0
L2 = 1->2
Output: 88
Explanation:
First linked list represents 100 and the
second one represents 12. 12 subtracted from 100
gives us 88 as the result. It is represented
as 8->8 in the linked list.*/

class Solution
{
public:
    int length(Node *head)
    {
        Node *temp = head;
        int count = 1;
        while (temp)
        {
            temp = temp->next;
            count++;
        }
        return count;
    }

    Node *reverse(Node *head)
    {
        Node *temp = head;
        Node *next = head->next;
        Node *prev = NULL;
        while (next)
        {
            temp->next = prev;
            prev = temp;
            temp = next;
            next = temp->next;
        }

        temp->next = prev;
        return temp;
    }

    Node *subLinkedList(Node *head1, Node *head2)
    {
        // Your implementation of subLinkedList goes here
        // Make sure to return the head of the resulting linked list
        while (head1->next != NULL && head1->data == 0)
        {
            head1 = head1->next;
        }
        while (head2->next != NULL && head2->data == 0)
        {
            head2 = head2->next;
        }

        int n1 = length(head1);
        int n2 = length(head2);

        if (n1 == 0 && n2 == 0)
        {
            return new Node(0);
        }
        if (n1 < n2)
        {
            return subLinkedList(head2, head1);
        }
        else if (n1 == n2)
        {
            Node *t1 = head1;
            Node *t2 = head2;
            while (t1 && t2 && t1->data == t2->data)
            {
                t1 = t1->next;
                t2 = t2->next;
            }
            if (t1 == NULL)
            {
                return new Node(0);
            }
            else if (t1->data < t2->data)
            {
                return subLinkedList(head2, head1);
            }
        }

        head1 = reverse(head1);
        head2 = reverse(head2);

        Node *t1 = head1;
        Node *t2 = head2;

        Node *res = NULL;

        while (t1)
        {
            int sub = 0;
            if (t2 != NULL)
            {
                sub = t2->data;
                t2 = t2->next;
            }

            if (t1->data < sub)
            {
                t1->next->data -= 1;
                t1->data += 10;
            }

            Node *n = new Node(t1->data - sub);
            t1 = t1->next;

            n->next = res;
            res = n;
        }

        while (res->next && res->data == 0)
        {
            res = res->next;
        }

        return res;

        return NULL;
    }
};
