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
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        vector<int> array;
        ListNode* temp = head;
        while (temp != nullptr) {
            array.push_back(temp->val);
            temp = temp->next;
        }
        sort(array.begin(), array.end());
        temp = head;
        int i = 0;
        while (temp != nullptr) {
            temp->val = array[i++];
            temp = temp->next;
        }
        return head;
    }
};