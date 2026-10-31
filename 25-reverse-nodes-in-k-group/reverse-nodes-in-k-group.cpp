/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};
*/

class Solution {
private:
    ListNode* Reverse(ListNode* temp){
        if(temp == nullptr) return nullptr;
 
        ListNode* prev = nullptr;
        while(temp != nullptr){
            ListNode* front = temp -> next;
            temp -> next = prev;
            prev = temp;
            temp = front;
        }

        return prev;
    }

    ListNode* getKthNode(ListNode* temp,int k){
        while(temp != nullptr && k > 1){
            temp = temp -> next;
            k--;
        }
        return temp;
    }


public:
    ListNode* reverseKGroup(ListNode* head, int k) {

    ListNode* temp = head;
    ListNode* prevNode = nullptr;
    
    while(temp != nullptr){
      ListNode* kthNode = getKthNode(temp,k);
     
      if(kthNode == nullptr){
       if(prevNode != nullptr) prevNode -> next = temp;
       break; 
      }

      ListNode* nextNode = kthNode -> next;
      kthNode -> next = nullptr;

      Reverse(temp);


      if(temp == head){
        head = kthNode;
      }

      else{
        prevNode -> next = kthNode;
      }

      prevNode = temp;

      temp = nextNode;
    }

    return head;

    }
};