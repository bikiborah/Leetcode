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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) return nullptr;

        ListNode* Odd = head;
        ListNode* temp1 = Odd;

        ListNode* Even = head -> next;
        ListNode* temp2 = Even;

        while(temp1 -> next != nullptr && temp2 -> next != nullptr){
          temp1 -> next = temp1 -> next -> next;
          temp1 = temp1 -> next;

          temp2 -> next = temp2 -> next -> next;
          temp2 = temp2 -> next;
        }

        temp1 -> next = Even;

        return Odd;
    }
};