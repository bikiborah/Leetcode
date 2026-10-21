
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;

        while (temp != nullptr && temp->next != nullptr) {
            if (temp->val == temp->next->val) {
                ListNode* x = temp->next;
                temp->next = temp->next->next;
                delete x;
            } else {
                temp = temp->next;
            }
        }

        return head;
    }
};
