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
    ListNode* rev(ListNode* node, int l, int r) {
        ListNode dummy(0);
        dummy.next = node;
        ListNode* prev = NULL, *cur = node, *next = NULL, *left = &dummy;
        int i = 0;
        while ((i++) < (l - 1)) {
            left = cur;
            cur = cur -> next;
        }

        i = 0;
        while (i++ < (r - l + 1)) {
            next = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = next;
            
        }

        left -> next -> next = cur;
        left -> next = prev;

        // if (node) {
        //     node -> next = prev;
        //     return node;
        // }

        return dummy.next;

    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        return rev(head, left, right);
    }
};