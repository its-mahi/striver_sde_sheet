/************ PALINDROME LINKED LISTS ************/

/**
 * @author: its_mahi
 * 
 * Code: 📝 [Problem Link](https://leetcode.com/problems/palindrome-linked-list/description/)
 * Article: 📖 [Explanation](https://takeuforward.org/data-structure/check-if-given-linked-list-is-plaindrome/)
 * 
 * Problem Statement: 📜
 *      Given the head of a singly linked list, return true if it is a palindrome.
 * 
 * Category: Easy
 * 
*/

/******* Approach 1 : Slow and Fast Pointer Approach *******/

/**
 * Approach: 
 *      with the approach of slow pointer and fast pointer, till fast is not reach end we will traverse list
 *      at the end slow will reach at center and fast at end
 *      now reverse the list started from where slow is pointing
 *      and now we can compare list starting from head and another from slow (middle, reversed)
 * 
 * Time Complexity: ⏱️ O(N/2)+O(N/2)+O(N/2)
 * Space Complexity: 💾 O(1)
 * 
*/


class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode * prev = NULL;
        ListNode * curr = head;

        while(curr != NULL) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* start = head;
        ListNode* mid = reverse(slow);
        ListNode* mid1 = mid;

        while(mid1 != NULL) {
            cout << mid1->val << " ";
            mid1 = mid1->next;
        }

        while(mid != NULL) {
            if(mid->val != start->val) {
                return false;
            }

            mid = mid->next;
            start = start->next;
        }

        return true;
    }
};


/******* Approach 2 : Reverse and Compare *******/

/**
 * Approach: 
 *      Create Reversed Linked List (Another, Copied)
 *      Make sure that it is copied linked list, else it will not give prefered result, if we change it in given list
 *      
 *      Compare both the list (Reversed and Given List
 * 
 * Time Complexity: ⏱️ O(N) + O(N)
 * Space Complexity: 💾 O(N)
 * 
*/


class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL) {
            ListNode* temp = new ListNode(curr->val);
            temp->next = prev;
            prev = temp;
            curr = curr->next;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {

        if(head == NULL || head->next == NULL){
            return (head);
        }

        ListNode* rev = reverse(head);

        while(head && rev){
            if(head->val != rev->val){
                return false;
            }
            head = head->next;
            rev = rev->next;
        }


        return true;
    }
};
