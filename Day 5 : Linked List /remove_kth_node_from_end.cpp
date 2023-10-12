/********   REMOVE Kth NODE FROM END   ********/

/**
 * @author : its_mahi
 * 
 * Code: https://www.codingninjas.com/studio/problems/799912?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
 * Article: https://takeuforward.org/data-structure/remove-n-th-node-from-the-end-of-a-linked-list/
 * 
 * Desc: Given a linked list, and a number N. Find the Nth node from the end of this linked list and delete it. Return the head of the new modified linked list.
 * 
 * 
 * Category: Easy
*/

/******* Approach 1 *******/

/**
 * Approach: Two pointer Approach
 *      - we can find the nth node just by one traversal by using a pointer approach.
 * 
 * Intuition: 
 * 
 *      1. We have the flexibility of using two-pointers now.
 *      2. We know, that the n-th node from the end is the same as (total nodes – n)th node from the start.
 *      3. But, we are not allowed to calculate total nodes, as we can do only one traversal.
 * 
 * What if, one out of the two-pointers is at the nth node from the start instead of the end? Will it make anything easier for us?
 * Yes, with two pointers in hand out of which is at the n-th node from the start, we can just advance both of them till the end simultaneously, once the faster reaches the end, the slower will stand at the n-th node from the end.
 * 
 * 
 * Approach: 
 *      1. Create two pointers slow and fast and initialize them to a head pointer.
 *      2. Move slow ptr by one step and simultaneously fast ptr by two steps until fast ptr is NULL or next of fast ptr is NULL.
 *      3. When the above condition is met, we can see that the slow ptr is pointing towards the middle of the Linked List and hence we can return the slow pointer.
 * 
 * 
 * Time Complexity : O(N)
 * Space Complexity : O(1)
 * 
*/


Node* removeKthNode(Node* head, int n)
{
    Node* fast = head;
    Node* slow = head;     

    // Start traversing until the fast pointer reaches the nth node.
    for(int i = 1; i <= n; i++) {
        fast = fast->next;
    }

    if(fast == NULL) {
        return head->next;
    }

    // Now start traversing by one step both of the pointers until the fast pointers reach the end.    
    while(fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    
    // When the traversal is done, just do the deleting part. Make slow pointers next to the next of the slow pointer to ignore/disconnect the given node.
    slow->next = slow->next->next;
    
    return head;
}

/**
 * Approach 2 : Using Recursion
 * 
 * Code : 
    void remove(Node* head, int &k) {
        if(head == NULL) {
            return;
        }

        remove(head->next, k);

        if(k == 0) {
            if(head->next != NULL) {
                head->next = head->next->next;
            }
            else {
                head->next = NULL;
            }
        }

        k--;
    }

    Node* removeKthNode(Node* head, int K)
    {
        remove(head, K);

        if(K == 0) {
            head = head->next;
        }
        
        return head;
    }
*/
