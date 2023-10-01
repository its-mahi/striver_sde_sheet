/**
 * @author : its_mahi
 * 
 * Code: https://www.codingninjas.com/studio/problems/630526?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
 * 
 * Problem Statement : 
 *      You are given an array 'arr' of length 'n', consisting of integers.
 *      A subarray is a contiguous segment of an array. In other words, a subarray can be formed by removing 0 or more integers from the beginning and 0 or more integers from the end of an array.
 *      
 *      Find the sum of the subarray (including empty subarray) having the maximum sum among all subarrays.
 *      
 *      The sum of an empty subarray is 0.
 * 
 * Example:
 *      Input: 'arr' = 11, 2, 7, -4, 3, 2, -10, 9, 11
 *      Output: 11
 *      
 *      Explanation: The subarray yielding the maximum sum is [1, 2, 7, -4, 3, 2].
 * 
 * Difficulty: Medium
 * 
 * Kadane's Algorithm
*/


long long maxSubarraySum(vector<int> arr, int n)
{
    long long ans = 0;
    long long temp = 0;

    for(int i=0 ; i<n ; i++) {
        if(temp + arr[i] > 0) {
            temp += arr[i];
            ans = max(ans, temp);
        }
        else {
            temp = 0;
        }
    }

    return ans;
}
