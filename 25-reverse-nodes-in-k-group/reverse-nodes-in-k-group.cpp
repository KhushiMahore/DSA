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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1)
            return head;
        vector<int> value;
        ListNode* temp = head;
        while (temp != nullptr) {
            value.push_back(temp->val);
            temp = temp->next;
        }
        for (int i = 0; i + k <= value.size(); i = i + k) {
            reverse(value.begin() + i, value.begin() + i + k);
        }
        temp = head;
        int index = 0;
        while (temp != nullptr) {
            temp->val = value[index++];
            temp = temp->next;
        }
        return head;
    }
};