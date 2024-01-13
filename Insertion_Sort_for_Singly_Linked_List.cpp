// <<<<<<<<<<<<<<<<<<  Insertion Sort for Singly Linked List  <<<<<<<<<<<<<<<<<<
// POTD Date 13-01-2024
// Coding_with_rahul


/*Given a singly linked list, sort the list (in ascending order) using insertion sort algorithm.

Example 1:

Input:
N = 10
Linked List = 30->23->28->30->11->14->
              19->16->21->25 
Output : 
11 14 16 19 21 23 25 28 30 30 
Explanation :
The resultant linked list is sorted.*/

class Solution
{
    public:
    Node* insert(Node* newNode, Node* ans){
        if(ans == NULL){
            newNode->next = ans;
            ans = newNode;
        }
        else if(ans->data > newNode->data){
            newNode->next = ans;
            ans = newNode;
        }
        else{
            Node *temp=ans;
            while(temp->next !=NULL && temp->next->data <= newNode->data){
                temp=temp->next;
            }
            newNode->next = temp->next;
            temp->next= newNode;
        }
        
        return ans;
    }
    
    Node* insertionSort(struct Node* head)
    {
        //code here
        if(!head || !head->next){
            return head;
        }
        Node* ans=NULL;
        while(head != NULL){
            Node* next = head->next;
            ans = insert(head, ans);
            head = next;
        }
        
        return ans;
    }
    
};
