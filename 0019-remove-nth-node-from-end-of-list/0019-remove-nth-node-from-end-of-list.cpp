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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr) return nullptr;
        ListNode* current = head;
        size_t size = 0;
        while(current) {
            current=current->next;
            size++;
        }
        
        int idx = size-n;
        current=head;
        ListNode* prev = nullptr;
        
        if(idx==0) {
            head=head->next;
            delete current;
            return head;
        }
        
        int i = 0;
        while(current&&i!=idx) {
            prev=current;
            current=current->next;
            i++;
        }
        
        if(current!=nullptr) {
            if(current->next==nullptr) {
                prev->next=nullptr;
                delete current;
            } else {
                prev->next = current->next;
                delete current;
            }
        }
            
        return head;
    }
};