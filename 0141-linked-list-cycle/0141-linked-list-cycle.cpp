#include <map>;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL){
            return false;
        }
        if(head -> next == NULL){
            return false;
        }

        ListNode* fast = head;
        ListNode* slow = head;

        while(fast != NULL && slow != NULL){
            fast = fast -> next;
            if(fast != NULL){
                fast = fast -> next;
            }
            slow = slow -> next;
            if(fast == slow){
                return true;
            }
        }
        return false;
        // map <ListNode* ,bool> visited;
        // ListNode* temp = head;

        // while(temp != NULL){
        //     if(visited[temp] == true ){
        //         return true;
        //     }
        //     visited[temp] = true;
        //     temp = temp -> next;
        //     temp = temp -> next;
        // }
        // return false;

        
    }
};