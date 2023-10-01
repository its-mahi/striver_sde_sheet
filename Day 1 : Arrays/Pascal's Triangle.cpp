/**
 * @author : its_mahi
 * 
 * Code: https://www.codingninjas.com/studio/problems/print-pascal-s-triangle_6917910?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
 * 
 * Problem Statement: You are given an integer 'N'. You need to return the first 'N' rows of Pascal's triangle.
 * 
 * Example:
 *      Input: N = 4
 *      
 *      Output:
 *          1
 *          1 1
 *          1 2 1
 *          1 3 3 1
 *      
 *      Explanation: The output matrix has the first four rows of Pascal's Triangle.
 * 
 * Difficulty: Easy
*/

vector<vector<int>> pascalTriangle(int N) {

    vector<vector<int> > ans;
    ans.push_back({1});

    for(int i=2 ; i<=N ; i++) {
        vector<int> temp;
        temp.push_back(1);

        for(int j=1 ; j<i-1 ; j++) {
            temp.push_back(ans[i-2][j-1] + ans[i-2][j]);
        }

        temp.push_back(1);

        ans.push_back(temp);
    }

    return ans;
}
