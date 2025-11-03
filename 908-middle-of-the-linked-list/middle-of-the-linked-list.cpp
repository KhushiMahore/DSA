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
    ListNode* middleNode(ListNode* head) {
        int count = 0;
        ListNode* val = head;
        while (val != nullptr) {
            count++;
            val = val->next;
        }

        val = head;
        for (int i = 0; i < count / 2; i++) {
            val = val->next;
        }
        return val;
    }
};