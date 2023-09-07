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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) {
            return head;
        }
        
        ListNode* temp = head;
        ListNode* prev = nullptr;
        int cnt = 1;


        while (cnt < left) {
            prev = temp;
            temp = temp->next;
            cnt++;
        }
        
        ListNode* start = prev; 
        ListNode* end = temp;  
        ListNode* next = nullptr;
        

        while (cnt <= right) {
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
            cnt++;
        }
        
        if (start == nullptr) {
            head = prev; 
        } else {
            start->next = prev;
        }
        
        end->next = temp;
        
        return head;
    }
};
