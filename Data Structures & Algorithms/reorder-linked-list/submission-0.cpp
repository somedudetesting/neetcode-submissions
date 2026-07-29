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
        ListNode *cur = node, *prev = NULL, *next = NULL;

        while (cur != NULL) {
            next = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = next;
        }

        return prev;
    }
public:
    void reorderList(ListNode* head) {
        ListNode *slow = head, *fast = head -> next;

        while (fast != NULL && fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        ListNode* two = rev(slow -> next);
        slow -> next = NULL;
        
        ListNode* one = head;
        while (two != NULL) {
            ListNode* t1 = one -> next;
            ListNode* t2 = two -> next;
            one -> next = two;
            two -> next = t1;
            one = t1;
            two = t2;
        }
    }
};
