/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (headA == nullptr || headB == nullptr)
            return nullptr;
        ListNode* pointA = headA;
        ListNode* pointB = headB;
        while (pointA != pointB) {
            if (pointA != nullptr) {
                pointA = pointA->next;
            } else {
                pointA = headB;
            }
            if (pointB != nullptr) {
                pointB = pointB->next;
            } else {
                pointB = headA;
            }
        }
        return pointA;
    }
};