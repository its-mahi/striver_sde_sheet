/************ MERGE TWO SORTED LISTS ************/

/**
 * @author: its_mahi
 * 
 * Code: 📝 [Problem Link](https://leetcode.com/problems/merge-two-sorted-lists/description/)
 * Article: 📖 [Explanation](https://takeuforward.org/data-structure/merge-two-sorted-linked-lists/)
 * 
 * Problem Statement: 📜
 * Given two singly linked lists that are sorted in increasing order of node values, merge two sorted linked lists and return them as a sorted list. The list should be made by splicing together the nodes of the first two lists.
 * 
 * Category: Easy
*/

/******* Approach 1 : Using an externally linked list to store answers *******/
/******* Approach 2 : Inplace method without using extra space ***************/


/**
 * Approach: 1
 * 
 * Step 1: Create a new dummy node. It will have the value 0 and will point to NULL respectively. This will be the head of the new list. Another pointer to keep track of traversals in the new list.
 * 
 * Step 2:  Find the smallest among two nodes pointed by the head pointer of both input lists, and store that data in a new list created.
 * 
 * Step 3: Move the head pointer to the next node of the list whose value is stored in the new list.
 * 
 * Step 4: Repeat the above steps till any one of the head pointers stores NULL. Copy remaining nodes of the list whose head is not NULL in the new list.
 * 
 * Time Complexity: ⏱️ O(N+M)
 * Space Complexity: 💾 O(N+M)
 * 
*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode * head = new ListNode(-1);


        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* curr = head;

        while(temp1 != NULL && temp2 != NULL) {
            int n1 = temp1->val;
            int n2 = temp2->val;

            if(n1 < n2) {
                ListNode* node = new ListNode(n1);
                temp1 = temp1->next;

                curr->next = node;
                curr = curr->next;
            }
            else {
                ListNode* node = new ListNode(n2);
                temp2 = temp2->next;

                curr->next = node;
                curr = curr->next;
            }
        }

        while(temp1 != NULL) {
            int n1 = temp1->val;
            ListNode* node = new ListNode(n1);
            temp1 = temp1->next;

            curr->next = node;
            curr = curr->next;
        }

        while(temp2 != NULL) {
            int n2 = temp2->val;
            ListNode* node = new ListNode(n2);
            temp2 = temp2->next;

            curr->next = node;
            curr = curr->next;
        }

        return head->next;
    }
};


/******* Approach 2 : Inplace method without using extra space ***************/

/**
 * Approach: 2
 * 
 * Step 1: Create two pointers, say l1 and l2. Compare the first node of both lists and find the small among the two. Assign pointer l1 to the smaller value node.
 * 
 * Step 2: Create a pointer, say res, to l1. An iteration is basically iterating through both lists till the value pointed by l1 is less than or equal to the value pointed by l2.
 * 
 * Step 3: Start iteration. Create a variable, say, temp. It will keep track of the last node sorted list in an iteration. 
 * 
 * Step 4: Once an iteration is complete, link node pointed by temp to node pointed by l2. Swap l1 and l2.
 * 
 * Step 5: If any one of the pointers among l1 and l2 is NULL, then move the node pointed by temp to the next higher value node.
 * 
 * 
 * Time Complexity: ⏱️ O(N)
 * Space Complexity: 💾 O(1)
 * 
*/


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        if(temp1 == NULL) {
            return temp2;
        }
        if(temp2 == NULL) {
            return temp1;
        }

        ListNode* merged = temp1->val < temp2->val ? temp1 : temp2;

        ListNode* head = merged;

        if(temp1->val < temp2->val) {
            temp1 = temp1->next;
        }
        else {
            temp2 = temp2->next;
        }

        while(temp1 != NULL && temp2 != NULL) {
            if(temp1->val < temp2->val) {
                merged->next = temp1;
                temp1 = temp1->next;
                merged = merged->next;
            }
            else {
                merged->next = temp2;
                temp2 = temp2->next;
                merged = merged->next;
            }
        }

        if(temp1 != NULL) {
            merged->next = temp1;
        }
        else {
            merged->next = temp2;
        }

        return head;
    }
};
