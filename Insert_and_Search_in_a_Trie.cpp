// <<<<<<<<<<<<<<<<<< Insert and Search in a Trie <<<<<<<<<<<<<<<<<<
// POTD Date 31-01-2024
// Coding_with_rahul
// Level : Medium 
// Company : Accolite, Amazon, Microsoft. D-E-Shaw, FactSet

/*
Complete the Insert and Search functions for a Trie Data Structure. 

Insert: Accepts the Trie's root and a string, modifies the root in-place, and returns nothing.
Search: Takes the Trie's root and a string, returns true if the string is in the Trie, otherwise false.
Note: To test the correctness of your code, the code-judge will be inserting a list of N strings called into the Trie, and then will search for the string key in the Trie. The code-judge will generate 1 if the key is present in the Trie, else 0.

Example 1:

Input:
n = 8
list[] = {the, a, there, answer, any, by, bye, their}
key = the
Output: 1
Explanation: 
"the" is present in the given set of strings. 
*/
class Solution
{
    public:
        //Function to insert string into TRIE.
        void insert(struct TrieNode *root, string key)
        {
            // code here
            int n=key.length();
            TrieNode* temp=root;
            for(int i=0;i<n;i++){
                int ind= CHAR_TO_INDEX(key[i]);
                if(temp->children[ind]==NULL){
                    temp->children[ind]=getNode();
                }
                temp=temp->children[ind];
            }
            
            temp->isLeaf=true;
        }
        
        //Function to use TRIE data structure and search the given string.
        bool search(struct TrieNode *root, string key) 
        {
            // code here
            int n=key.length();
            TrieNode* temp=root;
            for(int i=0;i<n;i++){
                int ind= CHAR_TO_INDEX(key[i]);
                if(temp->children[ind]==NULL){
                    return false;
                }
                temp=temp->children[ind];
            }
            
            if(temp!=NULL && temp->isLeaf==true){
                return true;
            }
            return false;
        
            
        }
};