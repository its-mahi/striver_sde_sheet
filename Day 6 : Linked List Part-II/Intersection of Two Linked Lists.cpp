/************ INTERSECTION OF TWO LINKED LISTS ************/

/**
 * @author: its_mahi
 * 
 * Code: 📝 [Problem Link](https://leetcode.com/problems/intersection-of-two-linked-lists/description/)
 * Article: 📖 [Explanation](https://takeuforward.org/data-structure/find-intersection-of-two-linked-lists/)
 * 
 * Problem Statement: 📜
 *      Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.
 * 
 * Category: Easy
 * 
*/

/******* Approach 1 : Using Unordered Map *******/

/**
 * Approach: Using Unordered Map
 * 
 * Time Complexity: ⏱️ O(M + N)
 * Space Complexity: 💾 O(N)
 * 
*/


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, int> mapp;

        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        while(temp1 != NULL) {
            mapp[temp1]++;
            temp1 = temp1->next;
        }

        while(temp2 != NULL) {
            mapp[temp2]++;

            if(mapp[temp2] == 2) {
                return temp2;
            }
            temp2 = temp2->next;
        }

        return NULL;
    }
};
