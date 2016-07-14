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
    ListNode *swapPairs(ListNode *head) {
        if (!head || !head->next)
            return head;
        ListNode *newHead = head->next;
        head->next = head->next->next;
        newHead->next = head;

        newHead->next->next = swapPairs(newHead->next->next);
        return newHead;
    }
};