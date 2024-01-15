/************ REVERSE LINKED LIST ************/

/**
 * @author: its_mahi
 * 
 * Code: 📝 [Problem Link](https://www.codingninjas.com/studio/problems/reverse-linked-list_920513?utm_source=youtube&utm_medium=affiliate&utm_campaign=Codestudio_Linkedlistseries)
 * Article: 📖 [Explanation](https://takeuforward.org/data-structure/reverse-a-linked-list/)
 * 
 * Problem Statement: 📜
 * Given the head of a singly linked list, write a program to reverse the linked list, and return the head pointer to the reversed list.
 * 
 * Category: Easy
 * 
*/

/******* Approach 1 : Iterative *******/

/**
 * Approach: 🛠️
 * 
 * The previous approach uses O(N) addition space which can be avoided by interchanging the connecting links of the nodes of the linked list in place.
 * 
 * The main idea is to flip the order of connections in the linked list, which changes the direction of the arrows. When this happens, the last element becomes the new first element of the list. This in-place reversal allows us to efficiently transform the original list without using extra space.
 * 
 * Time Complexity: ⏱️ O(N)
 * Space Complexity: 💾 O(1)
 * 
*/


Node* reverseLinkedList(Node *head)
{
    if(head == NULL) {
        return head;
    }

    Node * prev = head;
    Node * curr = head->next;

    while(curr != NULL) {
        Node * temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    return prev;
}


/******* Approach 2 : Recursive *******/


/**
 * Approach: 🛠️
 * 
 * 
 * Base Case:
 *      Check if the linked list is empty or contains only one node. Return the head as it’s already reversed in these cases.
 * 
 * Recursive Function:
 *      The core of the algorithm lies in implementing a recursive function responsible for reversing the linked list. This function operates based on the following principle:
 *      If the base case conditions are not met, the function invokes itself recursively. This recursion continues until it reaches the base case, gradually reversing the linked list starting from the second node (node after it) onward.
 * 
 * Return:
 *      Following the recursion, the function returns the new head of the reversed linked list. This head marks the last node of the original list before reversal, now the first node in the reversed sequence.
 * 
 * Time Complexity: ⏱️ O(N)
 * Space Complexity: 💾 O(1)
 * 
*/

void reverse(Node* head, Node* &ans) {
    if(head->next == NULL) {
        ans = head;
        return;
    }

    reverse(head->next, ans);

    Node * temp1 = head->next;
    temp1->next = head;

    head->next = NULL;
    //specially for last node of reversed linked list, for else it will be updated in next iteration
}


Node* reverseLinkedList(Node *head)
{
    Node* ans;
    reverse(head, ans);

    return ans;
}
