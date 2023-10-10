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


/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
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

