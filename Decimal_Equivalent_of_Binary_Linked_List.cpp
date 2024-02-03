// <<<<<<<<<<<<<<<<<< Decimal Equivalent of Binary Linked List <<<<<<<<<<<<<<<<<<
// POTD Date 03-02-2024
// Coding_with_rahul
// Level : easy
//company : Juniper Networks

/*Given a singly linked list of length n. The link list represents a binary number, ie- it contains only 0s and 1s. Find its decimal equivalent.
The significance of the bits decreases with the increasing index in the linked list.
An empty linked list is considered to represent the decimal value 0. 

Since the answer can be very large, answer modulo 109+7 should be printed.

Example 1:
Input:
n = 3
Linked List = {0, 1, 1}
Output:
3
Explanation:
0*22 + 1*21 + 1*20 =  1 + 2 + 0 = 3
*/
class Solution
{
    public:
        // Should return decimal equivalent modulo 1000000007 of binary linked list 
        long long unsigned int decimalValue(Node *head)
        {
           // Your Code Here
           long long unsigned int ans=0;
           int mod=1e9+7;
           Node*temp=head;
           while(temp){
               ans=ans*2+temp->data;
               temp=temp->next;
               ans=ans%mod;
           }
           return ans;
        }
};
