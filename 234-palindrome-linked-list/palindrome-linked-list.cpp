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
    ListNode* Reverse(ListNode* Head) {
        ListNode* temp = Head;
        ListNode* prev = nullptr;
        while (temp != nullptr) {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
       if(head == nullptr || head->next == nullptr) return true;

       ListNode* slow = head;
       ListNode* fast = head;

       while(fast->next != nullptr && fast->next->next != nullptr){
        fast = fast->next->next;
        slow = slow->next;
       }

       ListNode* Newhead = Reverse(slow->next);

       ListNode* First = head;
       ListNode* Second = Newhead;

       while(Second != nullptr){
        if(First->val != Second->val){
            slow->next = Reverse(Newhead);
            return false;

        }
        First = First->next;
        Second = Second->next;

       }

       slow->next = Reverse(Newhead);
       return true;

    }
};