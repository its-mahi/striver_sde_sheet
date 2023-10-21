/**
 * @author : its_mahi
 * 
 * Code: https://leetcode.com/problems/search-a-2d-matrix/
 * Article: https://takeuforward.org/data-structure/search-in-a-sorted-2d-matrix/
 * 
 * Desc: 
 *      You are given an m x n integer matrix matrix with the following two properties:
 *          * Each row is sorted in non-decreasing order.
 *          * The first integer of each row is greater than the last integer of the previous row.
 *
 * Given an integer target, return true if target is in matrix or false otherwise.
 * You must write a solution in O(log(m * n)) time complexity.
 * 
 * 
 * Category: Medium
*/

/**
 * Approach : Flatten 2D matrix into 1D array
 * 
 * Algorithm : 
 *      Step 1: Place the 2 pointers i.e. low and high: Initially, we will place the pointers. The pointer low will point to 0 and the high will point to (NxM)-1.
 * 
 *      Step 2: Calculate the ‘mid’: Now, inside the loop, we will calculate the value of ‘mid’ using the following formula: 
 *              mid = (low+high) // 2 ( ‘//’ refers to integer division)
 * 
 *      Step 3: Eliminate the halves based on the element at index mid: To get the element, we will convert index ‘mid’ to the corresponding cell using the above formula. Here no. of columns of the matrix = M.
 *              row = mid / M, col = mid % M.
 *              
 *              a. If matrix[row][col] == target: We should return true here, as we have found the ‘target’.
 *              b. If matrix[row][col] < target: In this case, we need bigger elements. So, we will eliminate the left half and consider the right half (low = mid+1).
 *              c. If matrix[row][col] > target: In this case, we need smaller elements. So, we will eliminate the right half and consider the left half (high = mid-1).
 *            
 *      Step 4: Steps 2-3 will be inside a while loop and the loop will end once low crosses high
 *              (i.e. low > high). If we are out of the loop, we can say the target does not exist in the matrix. So, we will return false.
 * 
 * Time Complexity : O(N*N) + O(N*N).One O(N*N) is for transposing the matrix and the other is for reversing the matrix.
 * Space Complexity : O(1)
 * 
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        //apply binary search:
        int low = 0, high = n * m - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            int row = mid / m, col = mid % m;

            if (matrix[row][col] == target) {
                return true;
            }
            else if (matrix[row][col] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return false;
    }
};


/**
 * 
 * Another Apporach : Using Two Binary Search
 * 
 * Algorithm : 
 * 
 *      Step 1: The code searches for a target value in a 2D matrix using two binary searches, first to find the potential row where the target may exist in the first column and then to find the target within that row.
 *      Step 2: If the target is found in the matrix, the function returns true; otherwise, it returns false.
 *      Step 3: It handles a special case when the matrix contains only one element and checks if that element is equal to the target, returning true if it is.
 * 
*/


/* Code : 

class Solution {
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> first_col;
        int n = matrix.size();
        int m = matrix[0].size();

        if(n == 1 && m == 1) {
            return matrix[0][0] == target;
        }

        int row = -1;

        int s = 0;
        int e = n-1;
        int mid;

        while(s<=e) {
            mid = (s+e)/2;

            if(matrix[mid][0] == target) {
                return true;
            }

            if(matrix[mid][0] < target) {
                s = mid+1;
            }
            if(matrix[mid][0] > target) {
                e = mid-1;
            }
        }

        row = e;
        s = 0;
        e = m-1;

        if(row < 0) {
            return false;
        }

        while(s <= e) {
            mid = (s+e)/2;

            if(matrix[row][mid] == target) {
                return true;
            }

            if(matrix[row][mid] < target) {
                s = mid+1;
            }
            if(matrix[row][mid] > target) {
                e = mid-1;
            }
        }

        return false;
    }
};

*/
