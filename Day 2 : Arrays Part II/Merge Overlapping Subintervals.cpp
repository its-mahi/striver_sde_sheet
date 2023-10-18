/**
 * @author : its_mahi
 * 
 * Code: https://leetcode.com/problems/merge-intervals/
 * Article: https://takeuforward.org/data-structure/merge-overlapping-sub-intervals/
 * 
 * Desc: Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
 * 
 * 
 * Category: Medium
*/


/**
 * Approach : 
 * 
 * Intuition: 
 *          Since we have sorted the intervals, the intervals which will be merging are bound to be adjacent. We kept on merging simultaneously as we were traversing through the array and when the element was non-overlapping we simply inserted the element in our answer list.
 * 
 * Approach: 
 *      1. First, we will group the closer intervals by sorting the given array of intervals(if it is not already sorted).
 *      2. After that, we will start traversing the array using a loop(say i) and insert the first element into our answer list(as the answer list is empty).
 *      3. Now, while traversing we will face two different cases: 
 *          Case 1: If the current interval can be merged with the last inserted interval of the answer list:
 *                  In this case, we will update the end of the last inserted interval with the maximum(current interval’s end, last inserted interval’s end) and continue moving afterward. 
 *          Case 2: If the current interval cannot be merged with the last inserted interval of the answer list:
 *                  In this case, we will insert the current interval in the answer array as it is. And after this insertion, the last inserted interval of the answer list will obviously be updated to the current interval.
 *      4. Thus the answer list will be updated with the merged intervals and finally, we will return the answer list.
 * 
 * 
 * Time Complexity: O(N*logN) + O(N), where N = the size of the given array.
 *                  Reason: Sorting the given array takes  O(N*logN) time complexity. Now, after that, we are just using a single loop that runs for N times. So, the time complexity will be O(N).
 * Space Complexity: O(N), as we are using an answer list to store the merged intervals. Except for the answer array, we are not using any extra space.
 * 
*/


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        for(int i=0 ; i<n ; i++) {
            int prev_end = ans.back()[1];

            if(intervals[i][0] <= prev_end) {
                ans.back()[1] = max(prev_end, intervals[i][1]);;
            }
            else {
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};
