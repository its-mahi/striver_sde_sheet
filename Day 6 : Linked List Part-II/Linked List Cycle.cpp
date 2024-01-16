/************ LINKED LISTS CYCLE ************/

/**
 * @author: its_mahi
 * 
 * Code: 📝 [Problem Link](https://leetcode.com/problems/linked-list-cycle/description/)
 * Article: 📖 [Explanation](https://takeuforward.org/data-structure/detect-a-cycle-in-a-linked-list/)
 * 
 * Problem Statement: 📜
 *      Given head, the head of a linked list, determine if the linked list has a cycle in it. There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer.
 * 
 *      Return true if there is a cycle in the linked list. Otherwise, return false.
 * 
 * Category: Easy
 * 
*/


/******* Approach 1 : Slow and Fast Pointer Approach *******/

/**
 * Approach: Slow and Fast Pointer
 * 
 * Time Complexity: ⏱️ O(N)
 * Space Complexity: 💾 O(1)
 * 
*/



class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {
                return true;
            }
        }

        return false;
    }
};


/******* Approach 2 : Using Unordered Map *******/

/**
 * Approach: Using Unordered Map
 * 
 * Time Complexity: ⏱️ O(N)
 * Space Complexity: 💾 O(N)
 * 
*/


class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* temp = head;
        unordered_map<ListNode*, int> map;

        while(temp != NULL) {
            map[temp]++;

            if(map[temp] == 2) {
                return true;
            }

            temp = temp->next;
        }

        return false;
    }
};
