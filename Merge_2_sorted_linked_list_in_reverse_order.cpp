// <<<<<<<<<<<<<<<<<<  Merge 2 sorted linked list in reverse order  <<<<<<<<<<<<<<<<<<
// POTD Date 08-01-2024
// Coding_with_rahul


/*Given two linked lists of size N and M, which are sorted in non-decreasing order. The task is to merge them in such a way that the resulting list is in non-increasing order.

Example 1:

Input:
N = 2, M = 2
list1 = 1->3
list2 = 2->4
Output:
4->3->2->1
Explanation:
After merging the two lists in non-increasing order, we have new lists as 4->3->2->1.*/

class Solution
{
    public:
    
    Node* merge(Node* node1, Node* node2){
        if(node1->data > node2->data){
            return merge(node2, node1);
        }
        
        Node* head = node1;
        node1=node1->next;
        Node* temp=head;
        
        while(node1 && node2){
            if(node1->data <=node2->data){
                temp=temp->next;
                node1=node1->next;
            }
            else{
                temp->next=node2;
                temp=temp->next;
                node2 = node2->next;
                temp->next = node1;
            }
        }
        if(node2){
            temp->next=node2;
        }
        
        return head;
    }
    
    Node* reverse(Node* node){
        Node* temp=node;
        Node* prev=NULL;
        Node* next=temp->next;
        
        while(next){
            temp->next = prev;
            prev=temp;
            temp=next;
            next=next->next;
        }
        
        temp->next =prev;
        
        return temp;
    }
    
    struct Node * mergeResult(Node *node1,Node *node2)
    {
        // your code goes here
        if(node1==NULL && node2==NULL){
            return NULL;
        }
        if(node1==NULL){
           return reverse(node2); 
        }
        if(node2==NULL){
            return reverse(node1);
        }
        
        //merge the linked list
        Node* head = merge(node1, node2);
        
        //reverse the linked list
        head= reverse(head);
        
        return head;
    }  
};
