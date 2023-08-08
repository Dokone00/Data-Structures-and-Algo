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
ListNode* solve(ListNode* list1, ListNode* list2){

    if(list1 -> next == NULL){
        list1 -> next = list2;
        return list1;
    }
    ListNode* prev = list1;
    ListNode* curr = prev -> next;
    ListNode* prev2 = list2;
    ListNode* curr2 = prev2 -> next;

    while(curr != NULL && prev2 != NULL){
        if((prev2 -> val >= prev -> val) && (prev2 -> val <= curr -> val)){
            prev -> next = prev2;
            curr2 = prev2 -> next;
            prev2 -> next = curr;

            prev = prev2;
            prev2 = curr2;    
        }
        else{
            
            prev = curr;
            curr = curr -> next;
            if(curr == NULL){
                prev -> next = prev2;
                return list1;
            }

            
        }

    }
    return list1;
}
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL){
            return list2;
        }
        if(list2 == NULL)
            return list1;
        if(list1 == NULL && list2 == NULL){
            return NULL;
        }
        
        if(list1 -> val >= list2 -> val){
            return solve(list2,list1);

        }
        else{
            return solve(list1,list2);

        }
    }
};