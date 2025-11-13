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
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* curr = head;
        vector<int> ans;
        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            int greater = 0;
            while (nextNode != nullptr) {
                if (nextNode->val > curr->val) {
                    greater = nextNode->val;
                    break;
                }
                nextNode = nextNode->next;
            }
            ans.push_back(greater);
            curr = curr->next;
        }
        return ans;
    }
};