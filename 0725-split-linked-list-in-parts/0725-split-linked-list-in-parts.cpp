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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> v(k, nullptr);
        int length = 0;
        ListNode* t = head;
        
        while (t) {
            t = t->next;
            length++;
        }
        
        if (length <= k) {
            int j = 0;
            while (j < length) {
                v[j] = head;
                ListNode* temp = head->next;
                head->next = nullptr;
                head = temp;
                j++;
            }
            return v;
        }
        
        int extra = length % k;
        int i = 0;
        
        while (i < k) {
            int j = 0;
            v[i] = head;
            i++;
            
            while (j < (length / k) - 1) {
                head = head->next;
                j++;
            }
            
            if (extra) {
                head = head->next;
                extra--;
            }
            
            ListNode* temp = head->next;
            head->next = nullptr;
            head = temp;
        }
        
        return v;
    }
};