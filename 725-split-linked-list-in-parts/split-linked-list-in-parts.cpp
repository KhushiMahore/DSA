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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k,nullptr);
        int count = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        int part = count / k;
        int extra = count % k;
        temp = head;
        for (int i = 0; i < k; i++) {
            if (temp == nullptr) {
                ans[i] = nullptr;
                continue;
            }

            ans[i] = temp;
            int size = part;
            if (extra > 0) {
                size = size + 1;
                extra--;
            }
            for (int j = 1; j < size; j++) {
                temp = temp->next;
            }
            ListNode* newnode = temp->next;
            temp->next = nullptr;
            temp = newnode;
        }
        return ans;
    }
};