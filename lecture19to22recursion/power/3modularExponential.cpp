// Modular Exponentiation for large numbers 
// Medium Accuracy: 50.28% Submissions: 4070 Points: 4
// Implement pow(x, n) % M.
// In other words, given x, n and M, find (xn) % M.
 

// Example 1:

// Input:
// x = 3, n = 2, m = 4
// Output:
// 1
// Explanation:
// 32 = 9. 9 % 4 = 1.
// Example 2:

// Input:
// x = 2, n = 6, m = 10
// Output:
// 4
// Explanation:
// 26 = 64. 64 % 10 = 4.

class Solution

{
	public:
		long long int PowMod(long long int x,long long int n,long long int M)
		{
		    // Code here
		     //  we will apply law of exponential.
   
            //(a*b) % m = ( a % m * b % m ) % m;
              // a ^ n % m = ( a % m * a ^ n - 1 % m ) % m;
            //             Property 1: 
            // (m * n) % p has a very interesting property: 
            // (m * n) % p =((m % p) * (n % p)) % p
            // Property 2: 
            // if b is even: 
            // (a ^ b) % c = ((a ^ b/2) * (a ^ b/2))%c ? this suggests divide and conquer 
            // if b is odd: 
            // (a ^ b) % c = (a * (a ^( b-1))%c
          
            
            if(n==0)
                return 1;
            if(n&1){       //odd case 
                return ((x%M) * PowMod(x,n-1,M))%M;
            }
            else{
            long long int cp = PowMod(x,n/2,M)%M;
            return (cp*cp) %M;
		}
		}
};