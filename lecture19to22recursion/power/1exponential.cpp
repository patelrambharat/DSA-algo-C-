// 50. Pow(x, n)
// Medium

// 4688

// 5573

// Add to List

// Share
// Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

 

// Example 1:

// Input: x = 2.00000, n = 10
// Output: 1024.00000
// Example 2:

// Input: x = 2.10000, n = 3
// Output: 9.26100
// Example 3:

// Input: x = 2.00000, n = -2
// Output: 0.25000

class Solution {
public:
    double myPow(double x, int n) {
        if(n==0){
            return 1;
        }
        if (n < 0) { 
            n = abs(n);
            x = 1/x;
        }
      
        double ans = myPow(x,n/2);
        if(n&1){
            return x*ans*ans;
        }
        else{
            return ans*ans;
        }
    }
};