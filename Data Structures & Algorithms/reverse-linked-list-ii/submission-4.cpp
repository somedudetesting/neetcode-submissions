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
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode *leftPart = &dummy;
        ListNode *cur = head;

        for (int i = 0; i < left - 1; i++) {
            leftPart = cur;
            cur = cur -> next;
        }

        ListNode *prev = NULL, *next = NULL;
        for (int i = 0; i < (right - left + 1); i++) {
            next = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = next;
        }

        leftPart -> next -> next = cur;
        leftPart -> next = prev;

        return dummy.next;
    }
};