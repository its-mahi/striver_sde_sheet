/**
 * @author : its_mahi
 * 
 * Code: https://www.codingninjas.com/studio/problems/973250?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
 * Article: https://takeuforward.org/data-structure/find-middle-element-in-a-linked-list/
 * 
 * Desc: Given a singly linked list of 'N' nodes. The objective is to determine the middle node of a singly linked list. However, if the list has an even number of nodes, we return the second middle node.
 * 
 * 
 * Time Complexity : O(N)
 * Space Complexity : O(1)
 * 
 * Category: Easy
*/

/******* Approach 1 *******/

/**
 * Tortoise-Hare-Approach
 *      - We don’t have to maintain node count and we will be able to find the middle node in a single traversal so this approach is more efficient.
 * 
 * Intuition: In the Tortoise-Hare approach, we increment slow ptr by 1 and fast ptr by 2, so if we take a close look fast ptr will travel double that of the slow pointer. So when the fast ptr will be at the end of the Linked List, slow ptr would have covered half of the Linked List till then. So slow ptr will be pointing towards the middle of Linked List.
 * 
 * Approach: 
 *      1. Create two pointers slow and fast and initialize them to a head pointer.
 *      2. Move slow ptr by one step and simultaneously fast ptr by two steps until fast ptr is NULL or next of fast ptr is NULL.
 *      3. When the above condition is met, we can see that the slow ptr is pointing towards the middle of the Linked List and hence we can return the slow pointer.
 * 
*/

Node *findMiddle(Node *head) {
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}


/******* Approach 2 *******/

/**
 * 
 * Solution 2: Native Approach (Brute Force)
 * 
 * Intuition: We can traverse through the Linked List while maintaining a count of nodes let’s say in variable n, and then traversing for 2nd time for n/2 nodes to get to the middle of the list.
 * 
 * 
 *   class Solution {
 *   public:
 *       ListNode* middleNode(ListNode* head) {
 *           int n = 0;
 *           ListNode* temp = head;
 *           while(temp) {
 *               n++;
 *                   temp = temp->next;
 *           }
 *       
 *           temp = head;
 *       
 *           for(int i = 0; i < n / 2; i++) {
 *                   temp = temp->next;
 *           }
 *       
 *           return temp;
 *       }
 *   };
 * 
 * 
*/
