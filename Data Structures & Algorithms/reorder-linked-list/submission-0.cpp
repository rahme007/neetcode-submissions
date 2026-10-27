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

    ListNode* findMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast =  head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

        }
        ListNode* temp = slow->next;
        slow->next = nullptr;
        return temp;
    }

    void reorderList(ListNode* head) {
        ListNode* t1 = head;
        ListNode* mid = findMid(t1);
        ListNode* prev = reverseList(mid);

        while (prev) {
            ListNode* temp = head;
            ListNode* temp1 = prev;
            head = head->next;
            temp->next = prev;
            prev = prev->next;
            temp1->next = head;
        }

    }
};
