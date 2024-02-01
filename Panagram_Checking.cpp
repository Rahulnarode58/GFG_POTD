// <<<<<<<<<<<<<<<<<< Panagram Checking <<<<<<<<<<<<<<<<<<
// POTD Date 01-02-2024
// Coding_with_rahul
// Level : easy

/*Given a string s check if it is "Panagram" or not.

A "Panagram" is a sentence containing every letter in the English Alphabet.

Example 1:

Input:
s = "Bawds jog, flick quartz, vex nymph"
Output: 
1
Explanation: 
In the given input, there
are all the letters of the English
alphabet. Hence, the output is 1.*/


class Solution
{
  public:
    //Function to check if a string is Pangram or not.
    bool checkPangram (string s) {
        vector<int> f(26, 0);
        
        for(auto i : s){
            char cur = tolower(i);
            
            if(cur >= 'a' and cur <= 'z'){
                f[cur - 'a'] = 1;
            }
        }
            
        return accumulate(f.begin(), f.end(), 0) == 26;
    }

};