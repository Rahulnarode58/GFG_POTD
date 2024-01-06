// <<<<<<<<<<<<<<<<<< Techfest and the Queue  <<<<<<<<<<<<<<<<<<
// POTD Date 06-01-2024
// Coding_with_rahul


/*A Techfest is underway, and each participant is given a ticket with a unique number. Organizers decide to award prize points to everyone who has a ticket ID between a and b (inclusive). The points given to a participant with ticket number x will be the sum of powers of the prime factors of x.

For instance, if points are to be awarded to a participant with ticket number 12, the amount of points given out will be equal to the sum of powers in the prime factorization of 12 (22 × 31), which will be 2 + 1 = 3.

Given a and b, determine the sum of all the points that will be awarded to the participants with ticket numbers between a and b (inclusive).

Example 1:

Input: 
a = 9
b = 12
Output: 
8
Explanation: 
For 9, prime factorization is:32 
So, sum of the powers of primes is: 2
For 10, prime factorization is : 21x51 
So, sum of the powers of primes is: 2
For 11, prime factorization is : 111 
So, sum of the powers of primes is: 1
For 12, prime factorization is : 22x 31 
So, sum of powers of primes is: 3
Therefore the total sum is 2+2+1+3=8.*/



class Solution {
public:
	int sumOfPowers(int a, int b){
	    // Code here
	    //create the pre-requisite table
	    vector<int>v(b+1,-1);
	    v[0]=0; v[1]=1;
	    for(int i=2;i<=b;i++){
	        if(v[i]==-1){
	            //remained unvisited
	            for(int x=i;x<=b;x+=i){
	                v[x]=i;
	            }
	        }
	    }
	    
	    int ans=0;
	    for(int i=a;i<=b;i++){
	        int x=i;
	        while(x>1){
	            ans++;
	            x = x/v[x];
	            
	        }
	    }
	    return ans;
	}
};
