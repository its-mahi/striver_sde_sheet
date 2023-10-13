/************ DELETE GIVEN NODE IN A LINKED LIST: O(1) APPROACH ************/

/**
 * @author: its_mahi
 * 
 * Code: 📝 [Problem Link](https://www.codingninjas.com/studio/problems/1105578?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website)
 * Article: 📖 [Explanation](https://takeuforward.org/data-structure/delete-given-node-in-a-linked-list-o1-approach/)
 * 
 * Problem Statement: 📜
 * You need to write a function to delete a node in a singly-linked list. But there's a twist! You won't be given access to the head of the list. Instead, you'll be given access to the node to be deleted directly. Rest assured, the node to be deleted is not the tail node in the list.
 * 
 * Category: Easy
 * 
 * Asked in: 💼 Adobe, Google, Bloomberg, Facebook, Oracle, Netflix, Flipkart, CRED, Meesho, Swiggy, Dream11, InMobi, Oyo
*/

/******* Approach 1: Swapping and Deleting *******/

/**
 * Approach: 🛠️
 * 1. We are given direct access to the node we want to delete in the linked list. This is the node we intend to remove from the list.
 * 2. To delete this node without needing access to the head of the list, we perform a clever trick:
 *    - We copy the value of the next node into the node to be deleted. This effectively 'replaces' the data in the current node with the data of the next node.
 *    - Then, we update the 'next' pointer of the current node to skip the next node, effectively removing it from the list.
 * 
 * Time Complexity: ⏱️ O(1)
 * Space Complexity: 💾 O(1)
 * 
*/

#include <bits/stdc++.h>

void deleteNode(LinkedListNode<int> * node) {
    // 🔄 Swap the data of the node to be deleted with the next node
    swap(node->data, node->next->data);

    // 🪓 Cut off the node to be deleted from the linked list
    node->next = node->next->next;
}
