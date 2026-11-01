/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
//     BRUTE FORCE SE KIA
// class Solution {
// public:
//     Node* copyRandomList(Node* head) {
//       unordered_map<Node*,Node*> mpp;
//       Node* temp = head;

//       while(temp != nullptr){
//         Node* NewNode = new Node(temp->val);
//         mpp[temp] = NewNode;
//         temp = temp -> next;
//       }

//       temp = head;

//       while(temp != nullptr){
//         Node* CopyNode = mpp[temp];
//         CopyNode -> next = mpp[temp->next];
//         CopyNode -> random = mpp[temp -> random];
//         temp = temp -> next;
//       }

//       return mpp[head];
//     }
// };


class Solution {
private:

    Node* FixRandom(Node* head) {

        Node* temp = head;

        while(temp != nullptr) {

            if(temp->random != nullptr)
                temp->next->random = temp->random->next;
            else
                temp->next->random = nullptr;

            temp = temp->next->next;
        }

        return head;
    }

    Node* InsertAtMiddle(Node* head) {

        Node* temp = head;

        while(temp != nullptr) {

            Node* NextNode = temp->next;

            Node* CopyNode = new Node(temp->val);

            CopyNode->next = temp->next;
            temp->next = CopyNode;

            temp = NextNode;
        }

        return head;
    }

public:

    Node* copyRandomList(Node* head) {

        if(head == nullptr)
            return nullptr;

        head = InsertAtMiddle(head);

        head = FixRandom(head);

        Node* temp = head;

        Node DummyNode(-1);
        Node* res = &DummyNode;

        while(temp != nullptr) {

            Node* CopyNode = temp->next;

            // Connect cloned list
            res->next = CopyNode;
            res = res->next;

            // Restore original list
            temp->next = CopyNode->next;

            // Move to next original node
            temp = temp->next;
        }

        return DummyNode.next;
    }
};
