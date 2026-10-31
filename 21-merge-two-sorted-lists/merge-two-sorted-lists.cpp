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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
       if(list1 == nullptr) return list2;
       if(list2 == nullptr) return list1;
      
      
       ListNode* DummnyNode = new ListNode(-1);
       ListNode* curr = DummnyNode;

       ListNode* temp1 = list1;
       ListNode* temp2 = list2;

       while(temp1 != nullptr || temp2 != nullptr){
        if(temp1 != nullptr && temp2 != nullptr){
          if(temp1 -> val <= temp2 -> val){
            curr -> next = temp1;
            curr = curr -> next;
            temp1 = temp1 -> next;
          }
          else{
            curr -> next = temp2;
            curr = curr -> next;
            temp2 = temp2 -> next;
          }
        }

        else if(temp1 != nullptr){
            while(temp1 != nullptr){
                curr -> next = temp1;
                curr = curr -> next;
                temp1 = temp1 -> next;
            }
            curr -> next = nullptr;
            break;
        }
        else{
            while(temp2 != nullptr){
                curr -> next = temp2;
                curr = curr -> next;
                temp2 = temp2 -> next;
            }
            curr -> next = nullptr;
            break;
        }
       }


       return DummnyNode-> next;

       
     }
};