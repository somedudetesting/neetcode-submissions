/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> otc;
        otc[NULL] = NULL;

        Node* cur = head;
        while (cur) {
            Node* copy = new Node(cur -> val);
            otc[cur] = copy;
            cur = cur -> next;
        }

        cur = head;
        while (cur) {
            Node* copy = otc[cur];
            copy -> next = otc[cur->next];
            copy -> random = otc[cur -> random];
            cur = cur -> next;
        }
        
        return otc[head];
    }
};
