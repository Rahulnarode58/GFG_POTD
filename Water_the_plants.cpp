// <<<<<<<<<<<<<<<<<< Water the plants <<<<<<<<<<<<<<<<<<
// POTD Date 18-01-2024
// Coding_with_rahul

/*A gallery with plants is divided into n parts, numbered 0, 1, 2, 3, ..., n-1. There are provisions for attaching water sprinklers in every division. A sprinkler with range x at division i can water all divisions from i-x to i+x.

Given an array gallery[] consisting of n integers, where gallery[i] is the range of the sprinkler at partition i (a power of -1 indicates no sprinkler attached), return the minimum number of sprinklers that need to be turned on to water the entire gallery. If there is no possible way to water the full length using the given sprinklers, print -1.

Example 1:

Input:
n = 6
gallery[] = {-1, 2, 2, -1, 0, 0}
Output:
2
Explanation: 
Sprinklers at index 2 and 5
can water the full gallery, span of
sprinkler at index 2 = [0,4] and span
of sprinkler at index 5 = [5,5].*/

class Solution{
    public:
    int min_sprinklers(int gallery[], int n)
    {
        vector<pair<int,int>> cover(n);
        
        for(int i = 0; i < n; i++){
            if(gallery[i] == -1)
                cover[i] = {1e7, 1e7};
            else
                cover[i] = {i - gallery[i], i + gallery[i]};
        }
        
        sort(cover.begin(), cover.end());
        
        int take = 0, index = 0, ans = 0;
        
        while(take < n){
            int nax = take - 1;
            
            while(index < n and cover[index].first <= take){
                nax = max(nax, cover[index++].second);
            }
            
            if(nax + 1 > take){
                ++ans;
                take = nax + 1;
            }
            else
                return -1;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        int gallery[n];
        for(int i=0; i<n; i++)
            cin>> gallery[i];
        Solution obj;
        cout<< obj.min_sprinklers(gallery,n) << endl;
    }
	return 1;
}
