// >>>>>>>>>>>>>>  Count possible ways to construct buildings    <<<<<<<<<<<<<<<
// POTD Date 05-01-2024 
// Coding_with_rahul

/*There is a road passing through a city with N plots on both sides of the road. Plots are arranged in a straight line on either side of the road. Determine the total number of ways to construct buildings in these plots, ensuring that no two buildings are adjacent to each other. Specifically, buildings on opposite sides of the road cannot be adjacent.

Using * to represent a plot and || for the road, the arrangement for N = 3 can be visualized as follows: * * * || * * *.

Note: As the answer can be very large, print it mod 109+7.

Example 1:

Input: N = 1
Output: 4
Explanation: 
Possible ways for the arrangement are B||*, *||B, B||B, *||*
where B represents a building.*/

class Solution{
	public:
	int TotalWays(int N)
	{
	    // Code here
	    int mod=1e9+7;
	    if(N==1) return 4;
	    long long int B=1, S=1, Bn1, Sn1;
	    
	    for(int i=2;i<=N;i++){
	        Bn1 = B;
	        Sn1 = S;
	        
	        //updating our values
	        B = Sn1;
	        S = Bn1 + Sn1;
	        
	        B %=mod;
	        S %=mod;
	       
	    }
	    
	    long long int result = B+S;
	    result %= mod;
	    
	    result = result * result;
	    result %= mod;
	    
	    return result;
	}
};

