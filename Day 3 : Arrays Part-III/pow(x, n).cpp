/**
 * @author : its_mahi
 * 
 * Code: https://leetcode.com/problems/powx-n/
 * Article: https://takeuforward.org/data-structure/implement-powxn-x-raised-to-the-power-n/
 * 
 * Desc: Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).
 *       Given a double x and integer n, calculate x raised to power n. Basically Implement pow(x, n).
 * 
 * 
 * Category: Easy
*/

/******* Approach 1 *******/

/**
 * 
 * Algorithm: 
 *      1. This code computes the power of a number efficiently using a recursive divide-and-conquer approach.
 *      2. The solve function recursively divides the problem into smaller subproblems, optimizing power calculation.
 *      3. The myPow function handles positive and negative exponents, returning the result or its reciprocal as appropriate.
 *      4. It's an efficient and concise way to compute powers with special case handling.
 * 
 * 
 * Time Complexity : O(logN)
 * Space Complexity : O(logN)
 * 
*/



class Solution {
public:
    double solve(double x, int n) {
        if(n == 0) {
            return 1.0;
        }

        double res = solve(x, n/2);

        if(n%2 == 0) {
            return res * res;
        }
        else {
            return res * res * x;
        }
    }

    double myPow(double x, int n) {
        if(n > 0) {
            return solve(x, n);
        }
        else {
            return 1/(solve(x,n));
        }
    }
};
