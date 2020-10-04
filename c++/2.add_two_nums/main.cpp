/**
 * Definition for singly-linked list.

 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //count the length of the two linkedlist, then add zero to make them have equal length
        int length1 = countLength(l1);
        int length2 = countLength(l2);
        if(length1>length2){
            addZero(l2, length1-length2);
        }else{
            addZero(l1, length2-length1);
        }
        ListNode* l3 = new ListNode(0);
        ListNode* temp = l3;
        int count = 0;
        while(l1!=nullptr){
            temp->next = new ListNode();
            temp = temp->next;
            temp->val = (l1->val + l2->val + count)%10;
            count = (l1->val + l2->val + count)/10;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(count){
            temp->next = new ListNode(count);
        }
        return l3->next;
    }

    int countLength(ListNode* l){
        int length = 0;
        ListNode* temp = l;
        while(temp!=nullptr){
            length++;
            temp = temp->next;
        }
        return length;
    }

    void addZero(ListNode* l, int length){
        while(l->next!=nullptr){
            l=l->next;
        }
        while(length--){
            l->next = new ListNode(0);
            l = l->next;
        }
    }
};