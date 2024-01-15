/************ MERGE TWO SORTED LISTS ************/

/**
 * @author: its_mahi
 * 
 * Code: 📝 [Problem Link](https://leetcode.com/problems/add-two-numbers/)
 * Article: 📖 [Explanation](https://takeuforward.org/data-structure/add-two-numbers-represented-as-linked-lists/)
 * 
 * Problem Statement: 📜
 * Given the heads of two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
 * 
 * Category: Medium
*/

/******* Approach 1 : Elementary Math *******/

/**
 * Approach: 1
 * 
 * Keep track of the carry using a variable and simulate digits-by-digits sum starting from the head of the list, which contains the least significant digit.
 *  
 * Time Complexity: ⏱️ O(max(M, N))
 * Space Complexity: 💾 O(max(M, N))
 * 
*/



class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * res = new ListNode(-1);
        ListNode * temp = res;

        int carry = 0;

        while(l1 != NULL || l2 != NULL) {
            int n1 = 0;
            int n2 = 0;

            if(l1 != NULL) {
                n1 = l1->val;
                l1 = l1->next;
            }

            if(l2 != NULL) {
                n2 = l2->val;
                l2 = l2->next;
            }

            ListNode * node = new ListNode((n1+n2+carry)%10);

            carry = (n1+n2+carry)/10;

            temp->next = node;
            temp = temp->next;
        }

        if(carry > 0) {
            ListNode * node = new ListNode(carry);
            temp->next = node;
        }

        return res->next;
    }
};
