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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* temp = head;
        int cnt = 1;
        while (temp->next != NULL) {
            cnt++;
            temp = temp->next;
        }
        temp->next = head;
        k = k % cnt;
        if (k == 0) {
            temp->next = NULL;
            return head;
        }
        int ele = cnt - k;
        temp=head;
        for (int i = 0; i < ele - 1; i++) {
            temp = temp->next;
        }
        ListNode* newhead = temp->next;
        temp->next = NULL;
        return newhead;
    }
};