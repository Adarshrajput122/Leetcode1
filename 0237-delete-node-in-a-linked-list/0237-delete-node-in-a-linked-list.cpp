/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* nextNode = node -> next;
        node->val = node->next->val;        // isme jo node ko delete karte hai usko smae bante hai like 4 5 1 9 then 4 5 9 9 banake nine ko delete 
        node->next = node->next->next;
        delete nextNode; 
    }
};