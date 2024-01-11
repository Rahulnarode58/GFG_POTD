// <<<<<<<<<<<<<<<<<<  Remove K Digits  <<<<<<<<<<<<<<<<<<
// POTD Date 11-01-2024
// Coding_with_rahul

/*Given a non-negative integer S represented as a string, remove K digits from the number so that the new number is the smallest possible.
Note : The given num does not contain any leading zero.

Example 1:

Input:
S = "149811", K = 3
Output: 
111
Explanation: 
Remove the three digits 
4, 9, and 8 to form the new number 111
which is smallest.*/




class Solution {
  public:
    string removeKdigits(string S, int K) {
        int n=S.length();
        if(K==0) return S;
        else if(K==n) return "0";
        
        stack<char>st1;
        st1.push(S[0]);
        for(int i=1;i<n;i++){
            while(!st1.empty() && st1.top()>S[i] && K!=0){
                K--;
                st1.pop();
            }
            st1.push(S[i]);
        }
        
        while(K!=0){
            K--;
            st1.pop();
        }
        
        stack<char>st2;
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        
        while(st2.size()!=1 && st2.top()=='0'){
            st2.pop();
        }
        
        string res="";
        while(!st2.empty()){
            res+=st2.top();
            st2.pop();
        }
        
        return res;
    }
};
