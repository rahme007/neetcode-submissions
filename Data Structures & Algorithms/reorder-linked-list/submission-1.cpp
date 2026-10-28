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
    ListNode* findMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* temp = slow->next;
        slow->next = nullptr;

        return temp;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;

        while (head) {
            ListNode* temp = prev;
            prev = head;
            head = head->next;
            prev->next = temp;

        }
        return prev;
    }
    void reorderList(ListNode* head) {

        ListNode* temp1 = head;
        ListNode* mid = findMid(temp1);
        ListNode* prev = reverseList(mid);

        while (prev) {
            ListNode* temp2 = head;
            head = head->next;
            temp2->next = prev;
            ListNode* temp3 = prev;
            prev = prev->next;
            temp3->next = head;
            
        }
    }
};
