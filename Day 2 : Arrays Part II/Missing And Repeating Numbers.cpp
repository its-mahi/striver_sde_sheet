/**
 * @author : its_mahi
 * 
 * Code: https://www.codingninjas.com/studio/problems/missing-and-repeating-numbers_6828164
 * Article: https://takeuforward.org/data-structure/find-the-repeating-and-missing-numbers/
 * 
 * Desc: 
 *      You are given a read-only array of N integers with values also in the range [1, N] both inclusive. Each integer appears exactly once except A which appears twice and B which is missing. The task is to find the repeating and missing numbers A and B where A repeats twice and B is missing.     
 * 
 * Category: Medium
*/

/**
 * Approach : Bitwise XOR
 * 
 * 
 * Steps : 
 *      1. Calculate XOR of All Elements and Numbers from 1 to N :
 *          Find the XOR of all elements in the array and all numbers from 1 to N.
 *          (X^Y) = (a[0]^a[1]^…^a[n-1]) ^ (1^2^3^…^N)
 * 
 *      2. Find the First Different Bit from Right in (X^Y):
 *          Look for the first set bit from the right in the result obtained in step 1, (X^Y).
 *          The position of this first different bit indicates the differing bit between X and Y.
 * 
 *      3. Group Elements into Two Sets Based on the Different Bit:
 *          Create two groups, one for all array elements and the other for numbers from 1 to N.
 *          Examine the bit at the position found in step 2 for each element in these two groups.
 *          If the bit is 0, place the element in the first group; if it's 1, put it in the second group.
 *          
 *      4. XOR the Elements in the Two Groups:
 *          Perform XOR on all elements in the first group, resulting in one number (either X or Y).
 *          Perform XOR on all elements in the second group, resulting in the other number (the other one of X or Y).
 * 
 *      5. Determine Repeating and Missing Numbers: 
 *          To distinguish between the repeating number (X) and the missing number (Y), iterate through the original array.
 *          The number that appears twice is the repeating number (X), and the other one is the missing number (Y).
 * 
 * 
 *  Time Complexity: O(N), where N = the size of the given array.
 *                   Reason: We are just using some loops running for N times. So, the time complexity will be approximately O(N).
 * 
 *  Space Complexity: O(1) as we are not using any extra space to solve this problem.
 * 
*/



#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	int xr = 0;
	for(int i=0 ; i<n ; i++) {
		xr = xr ^ arr[i];
	}
	for(int i=1 ; i<=n ; i++) {
		xr = xr ^ i;
	}

	int bitNo = 0;
	while(1) {
		if(xr%2 == 1) {
			break;
		}
		bitNo++;
		xr /= 2;
	}

	int one = 0;
	int zero = 0;

	for(int i=0 ; i<n ; i++) {
		if((arr[i] & (1<<bitNo)) != 0) {
			one = one ^ arr[i];
		}
		else {
			zero = zero ^ arr[i];
		}
	}
	
	for(int i=1 ; i<=n ; i++) {
		if((i & (1<<bitNo)) != 0) {
			one = one ^ i;
		}
		else {
			zero = zero ^ i;
		}
	}

	for(int i=0 ; i<n ; i++) {
		if(arr[i] == one) {
			return {zero, one};
		}
	}

	return {one, zero};
}
