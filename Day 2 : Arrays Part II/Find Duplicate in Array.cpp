/**
 * @author : its_mahi
 * 
 * Code : https://www.codingninjas.com/studio/problems/1112602?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
 * Article : https://takeuforward.org/data-structure/find-the-duplicate-in-an-array-of-n1-integers/
 * 
 * Desc : 
 *      You are given an array of integers 'ARR' containing N elements. Each integer is in the range [1, N-1], with exactly one element repeated in the array.
 *      Your task is to find the duplicate element. The duplicate element may be repeated more than twice in the error, but there will be exactly one element that is repeated in the array.
 * 
 * Note:
 *      All the integers in the array appear only once except for precisely one integer which appears two or more times.
 * 
 * Category: Easy
*/

#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n){
	unordered_map<int, int> map;

	for(int i=0 ; i<n ; i++) {
		map[arr[i]]++;
		if(map[arr[i]] > 1) {
			return arr[i];
		}
	}

	return -1;
}	
