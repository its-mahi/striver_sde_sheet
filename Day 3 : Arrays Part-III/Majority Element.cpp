/**
 * @author : its_mahi
 * 
 * Code: https://leetcode.com/problems/majority-element/
 * Article: https://takeuforward.org/data-structure/find-the-majority-element-that-occurs-more-than-n-2-times/
 * 
 * Desc: Given an array nums of size n, return the majority element.
 *       The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
 * 
 * 
 * Category: Easy
*/


/**
 * Approach : 
 * 
 * 
 * Algorithm: 
 *      1. Initialize 2 variables: 
 *          Count –  for tracking the count of element
 *          Element – for which element we are counting
 * 
 *      2. Traverse through the given array.
 *          a. If Count is 0 then store the current element of the array as Element.   
 *          b. If the current element and Element are the same increase the Count by 1.
 *          c. If they are different decrease the Count by 1.
 * 
 *      3. The integer present in Element should be the result we are expecting 
 * 
 * 
 * Basically, we are trying to keep track of the occurrences of the majority element and minority elements dynamically. 
 * That is why, in iteration 4, the count becomes 0 as the occurrence of Element and the occurrence of the other elements are the same. So, they canceled each other. This is how the process works. The element with the most occurrence will remain and the rest will cancel themselves.
 * Here, we can see that 2 is the majority element. But if in this array, the last two elements were 3, then the Element variable would have stored 3 instead of 2. 
 * For that, we need to check if the Element is the majority element by traversing the array once more. But if the question guarantees that the given array contains a majority element, then we can bet the Element will store the majority one.
 * 
 * 
 * Time Complexity: O(N) + O(N), where N = size of the given array.
 *      Reason: The first O(N) is to calculate the count and find the expected majority element. The second one is to check if the expected element is the majority one or not.
 * 
 * Note: If the question states that the array must contain a majority element, in that case, we do not need the second check. Then the time complexity will boil down to O(N).
 * 
 * Space Complexity: O(1) as we are not using any extra space.
 * 
 * 
*/



class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int element = -1;
        int n = nums.size();

        for(int i=0 ; i<n ; i++) {
            if(count == 0) {
                count = 1;
                element = nums[i];
            }
            else if(count > 0 && element == nums[i]) {
                count++;
            }
            else if(count > 0 && element != nums[i]) {
                count--;
            }
        }

        return element;
    }
};





/*********** Approach 2 ***********/

/**
 * 
 * Approach: Using Unordered Map
 * 
 * Code : 
 * 
    class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            unordered_map<int, int> map;
            int n = nums.size();

            int ans = -1;

            for(int i=0 ; i<n ; i++) {
                map[nums[i]]++;

                if(map[nums[i]] > floor(n/2)) {
                    ans = nums[i];
                }
            }

            return ans;
        }
    };
 * 
*/
