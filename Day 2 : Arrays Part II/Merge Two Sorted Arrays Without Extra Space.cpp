/**
 * @author : its_mahi
 * 
 * Code : https://www.codingninjas.com/studio/problems/merge-two-sorted-arrays-without-extra-space_6898839?utm_source=striver&utm_medium=website&utm_campaign=codestudio_a_zcourse
 * Article : https://takeuforward.org/data-structure/merge-two-sorted-arrays-without-extra-space/
 * 
 * Desc : 
 *      Given two non-decreasing sorted arrays, 'A' and 'B', having 'N'and 'M' elements, respectively.
 *      You must merge these arrays, 'A' and 'B', into a sorted array without using extra space. Of all the 'N + M' sorted elements, array 'A' should contain the first 'N' elements, and array 'B' should have the last 'M' elements.
 * 
 * Note:
 *      You must perform the merge operation in place and must not allocate any extra space to merge the two arrays.
 * 
 * Category: Medium
*/

/**
 * Approach : 
 *      The sizes of the given arrays are n(size of arr1[]) and m(size of arr2[]).
 * 
 *      Steps : 
 *          1. We will declare two pointers i.e. left and right. The left pointer will point to the last index of the arr1[](i.e. Basically the maximum element of the array). The right pointer will point to the first index of the arr2[](i.e. Basically the minimum element of the array).
 * 
 *          2. Now, the left pointer will move toward index 0 and the right pointer will move towards the index m-1. While moving the two pointers we will face 2 different cases like the following:
 *              a. If arr1[left] > arr2[right]: In this case, we will swap the elements and move the pointers to the next positions.
 *              b. If arr1[left] <= arr2[right]: In this case, we will stop moving the pointers as arr1[] and arr2[] are containing correct elements.
 *          
 *          3. Thus, after step 2, arr1[] will contain all smaller elements and arr2[] will contain all bigger elements. Finally, we will sort the two arrays.       
 * 
 * 
 * Time Complexity: O(min(n, m)) + O(n*logn) + O(m*logm), where n and m are the sizes of the given arrays.
 * Reason: O(min(n, m)) is for swapping the array elements. And O(n*logn) and O(m*logm) are for sorting the two arrays.
 * 
 * Space Complexity: O(1) as we are not using any extra space.
 * 
 * @video : https://www.youtube.com/watch?v=n7uwj04E0I4
*/


#include<vector>

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b){

	int n = a.size();
	int m = b.size();

	int i=n-1;
	int j=0;

	while(i>=0 && j<m) {
		if(a[i] > b[j]) {
			swap(a[i], b[j]);
			i--;
			j++;
		}
		else {
			break;
		}
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
}
