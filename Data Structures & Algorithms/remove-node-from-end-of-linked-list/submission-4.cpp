/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
private: 
    ListNode* rev(ListNode* node) {
        ListNode *cur = node, *next = NULL, *prev = NULL;

        while (cur != NULL) {
            next = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = next;
        } 

        return prev;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head -> next == NULL) return NULL;
        ListNode *node = head;

        node = rev(node);
        ListNode* newHead = node;

        if (n == 1) {
            return rev(newHead -> next);
        }
        while (--n > 1) {
            node = node -> next;
        }

        node -> next = node -> next -> next;

        newHead = rev(newHead);

        return newHead;
    }
};
