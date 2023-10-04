/**
 * @author : its_mahi
 * 
 * Code : https://www.codingninjas.com/studio/problems/next-greater-permutation_6929564?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
 * Article : https://takeuforward.org/data-structure/next_permutation-find-next-lexicographically-greater-permutation/
 * 
 * Desc : 
 *      You are given an array 'a' of 'n' integers.
 *      You have to return the lexicographically next to greater permutation.
 * 
 * Note:
 *      If such a sequence is impossible, it must be rearranged in the lowest possible order.
 * 
 * Example:
 *      Input: 'a' = [1, 3, 2]
 *      Output: 2 1 3
 *      
 *      Explanation: All the permutations of [1, 2, 3] are [il, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1]. 
 *                   Hence the next greater permutation of [1, 3, 2] is [2, 1, 3].
 * 
 * Note : In Article there are 3 approaches are given.
 * 
 * Category : Medium
*/


/**
 * Using function of STL Library
 * 
 * vector<int> nextGreaterPermutation(vector<int> &A) {
 *      next_permutation(A.begin(), A.end());
 *      return A;
 * }
 * 
*/


vector<int> nextGreaterPermutation(vector<int> &A) {
    int n = A.size();

    int idx = -1;
    for(int i=n-2 ; i>=0 ; i--) {
        if(A[i]<A[i+1]) {
            idx = i;
            break;
        }
    }

    if(idx == -1) {
        sort(A.begin(), A.end());
        return A;
    }

    for(int i=n-1 ; i>idx ; i--){
        if(A[i]>A[idx]){
            swap(A[i],A[idx]);
            sort(A.begin()+idx+1,A.end());
            return A;
        }
    }
}
