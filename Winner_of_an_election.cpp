// Winner of an election
// POTD Date 30-12-2023 
// Coding_with_rahul

/*
Given an array of n names arr of candidates in an election, where each name is a string of lowercase characters. A candidate name in the array represents a vote casted to the candidate. Print the name of the candidate that received the maximum count of votes. If there is a draw between two candidates, then print lexicographically smaller name.

Example 1:

Input:
n = 13
arr[] = {john,johnny,jackie,johnny,john 
jackie,jamie,jamie,john,johnny,jamie,
johnny,john}
Output: john 4
Explanation: john has 4 votes casted for 
him, but so does johny. john is 
lexicographically smaller, so we print 
john and the votes he received.
*/

class Solution{
 public:
  
  //Function to return the name of candidate that received maximum votes.
  vector<string> winner(string arr[],int n)
  {
   
    unordered_map<string, int>mp;
    int count=0;
     
    for(int i=0;i<n;i++){
      mp[arr[i]]++;
      if(count < mp[arr[i]]) count=mp[arr[i]];
    }
     
    string ans="";
    for(int i=0;i<n;i++){
      if(mp[arr[i]]==count){
        if(ans==""){
          ans=arr[i];
        }
        else if(arr[i] < ans){
          ans= arr[i];
        }
      }
       
    }
    return {ans, to_string(count)};
  }
};
