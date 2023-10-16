/**
 * @author : its_mahi
 * 
 * Code: https://leetcode.com/problems/rotate-image/
 * Article: https://takeuforward.org/data-structure/rotate-image-by-90-degree/
 * 
 * Desc: 
 *      You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
 *      You have to rotate the image in place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
 * 
 * Category: Medium
*/

/**
 * Approach: Transpose & Reverse
 * 
 * Intuition: 
 *          By observation, we see that the first column of the original matrix is the reverse of the first row of the rotated matrix, 
 *          so that’s why we transpose the matrix and then reverse each row, and since we are making changes in the matrix itself space complexity gets reduced to O(1).
 * 
 * Approach: 
 *      Step 1: Transpose of the matrix. (transposing means changing columns to rows and rows to columns)
 *      Step 2: Reverse each row of the matrix.
 * 
 * Time Complexity : O(N*N) + O(N*N).One O(N*N) is for transposing the matrix and the other is for reversing the matrix.
 * Space Complexity : O(1)
 * 
*/



class Solution {
public:
    void transpose(vector<vector<int>> &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i=0 ; i<n ; i++) {
            for(int j=i ; j<n ; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }

    void reverse_every_row(vector<vector<int>> &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i=0 ; i<n ; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }

    // resulting function
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        reverse_every_row(matrix);
    }
};



/*********** Rotate Matrix: Another Code ***********/

/**
 * 
 * Code: https://www.codingninjas.com/studio/problems/981260?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
 * Article: https://takeuforward.org/data-structure/rotate-image-by-90-degree/
 * 
 * Desc: 
 *      Given a 2-dimensional matrix of size 'N' x'M', rotate the elements of the matrix clockwise.
 *
 * For Example:
 *      Input Matrix: 
 *          [ [ 1, 2, 3 ]
 *            [ 4, 5, 6 ]
 *            [ 7, 8, 9 ] ]
 *        
 *      Output Matrix:    
 *          [ [ 4, 1, 2 ]
 *            [ 7, 5, 3 ]
 *            [ 8, 9, 6 ] ]
 * 
 * The output matrix is generated by rotating the elements of the input matrix in a clockwise direction. Note that every element is rotated only once.
 * 
 * Category: Medium
*/




#include <bits/stdc++.h>

void rotate(vector<vector<int>> &mat, int si, int sj, int ei, int ej) {
    int copy = mat[si][sj];

    for(int i=si ; i<ei ; i++) {
        mat[i][sj] = mat[i+1][sj];
    }

    for(int i=sj ; i<ej ; i++) {
        mat[ei][i] = mat[ei][i+1];
    }

    for(int i=ei ; i>si ; i--) {
        mat[i][ej] = mat[i-1][ej];
    }
    
    for(int i=ej ; i>sj ; i--) {
        mat[si][i] = mat[si][i-1];
    }

    mat[si][sj+1] = copy;
}

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    int si=0;
    int sj=0;
    int ei=n-1;
    int ej=m-1;

    while(si<ei && sj<ej) {
        rotate(mat, si, sj, ei, ej);
        si++;
        sj++;
        ei--;
        ej--;
    }
}
