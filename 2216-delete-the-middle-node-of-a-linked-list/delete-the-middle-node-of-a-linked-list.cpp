class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head == nullptr) return nullptr;

        if (head->next == nullptr) {
            return nullptr;
        }

        ListNode* S = head;
        ListNode* F = head;
        ListNode* prev = nullptr;

        while (F != nullptr && F->next != nullptr) {
            prev = S;
            S = S->next;
            F = F->next->next;
        }

        prev->next = S->next;
        S->next = nullptr;

        return head;
    }
};