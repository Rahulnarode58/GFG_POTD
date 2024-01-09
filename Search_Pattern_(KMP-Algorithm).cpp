// <<<<<<<<<<<<<<<<<<  Search Pattern (KMP-Algorithm) <<<<<<<<<<<<<<<<<<
// POTD Date 09-01-2024
// Coding_with_rahul

/*Given two strings, one is a text string, txt and other is a pattern string, pat. The task is to print the indexes of all the occurences of pattern string in the text string. Use one-based indexing while returing the indices. 
Note: Return an empty list incase of no occurences of pattern. Driver will print -1 in this case.

Example 1:

Input:
txt = "geeksforgeeks"
pat = "geek"
Output: 
1 9
Explanation: 
The string "geek" occurs twice in txt, one starts are index 1 and the other at index 9. */


class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            //code here.
            int n= txt.length();
            int m= pat.length();
            int len=0;
            vector<int>arr(m,0);
            
            int i=1;
            while(i<m){
                if(pat[i]==pat[len]){
                    arr[i]=len+1;
                    len++;
                    i++;
                }
                else{
                    if(len==0){
                        arr[i]=0;
                        i++;
                    }
                    else{
                        len = arr[len-1];
                    }
                }
            }
            
            // for(auto )
            
            i=0; 
            int j=0;
            vector<int>ans;
            while(i<n){
                if(pat[j] == txt[i]){
                    i++;
                    j++;
                }
                if(j==m){
                    ans.push_back(i-j+1);
                    j=arr[j-1];
                }
                else if(i<n && pat[j] != txt[i]){
                    if(j==0){
                        i++;
                    }
                    else{
                        j=arr[j-1];
                    }
                }
            }
            
            if(ans.size()==0){
                return {-1};
            }
            
            return ans;
        }
     
};
