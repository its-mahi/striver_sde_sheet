/**
 * @author : its_mahi
 * 
 * Code : https://www.codingninjas.com/studio/problems/zero-matrix_1171153?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
 * 
 * Problem Statement : You are given a matrix 'MATRIX' of dimension 'N' × 'M'. Your task is to make all the elements of row 'i' and column 'j' equal to O if any element in the ith row or ith column of the matrix is 0.
 * 
 * Difficulty : Easy
*/


#include <bits/stdc++.h> 

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
	
	vector<vector<int>> ans = matrix;
	
	for(int i=0 ; i<n ; i++) {
		for(int j=0 ; j<m ; j++) {
			if(matrix[i][j] == 0) {
				for(int p=0 ; p<n ; p++) {
					ans[p][j] = 0;
				}

				for(int p=0 ; p<m ; p++) {
					ans[i][p] = 0;
				}
			}
		}
	}

	return ans;	
}