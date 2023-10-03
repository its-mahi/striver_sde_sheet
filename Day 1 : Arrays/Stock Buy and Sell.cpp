/**
 * @author : its_mahi
 * 
 * Code : https://www.codingninjas.com/studio/problems/best-time-to-buy-and-sell-stock_6194560?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
 * 
 * Problem Statement : 
 *      
 *
 * Difficulty : Medium
*/



int bestTimeToBuyAndSellStock(vector<int>&prices) {
    int n = prices.size();

    int ans = 0;
    int mini = INT_MAX;

    for(int i=0 ; i<n ; i++) {
        ans = max(ans, prices[i]-mini);
        mini = min(mini, prices[i]);
    }

    return ans;
} 
