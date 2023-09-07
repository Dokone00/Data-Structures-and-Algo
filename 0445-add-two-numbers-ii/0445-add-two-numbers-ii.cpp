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
ListNode* reverse(ListNode* temp){
    ListNode* prev = NULL;
    ListNode* curr = temp;
    ListNode* forw = NULL;
    while(curr!=NULL){
        forw=curr->next;
        curr->next = prev;
        prev = curr;
        curr = forw;
    }
    temp = prev;
    return temp; 

}
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = reverse(l1);
        ListNode* temp2 = reverse(l2);
        int cnt = 0;
        ListNode* ans = new ListNode();
        ListNode* res = ans;
        while(temp1!=NULL && temp2!=NULL){
            ListNode* newNode = new ListNode();
            if(temp1->val+temp2-> val + cnt >9){
                newNode->val=((temp1->val+temp2->val+cnt)%10);
                cnt = 1;
            }
            else{
                newNode->val=temp1->val+temp2->val + cnt;
                cnt = 0;
            }
            temp1=temp1->next;
            temp2=temp2->next;
            ans->next=newNode;
            ans=ans->next;
        }
        while(temp1!=NULL){
            ListNode* newNode = new ListNode();
            if(temp1->val+cnt>9){
                newNode->val=0;
                cnt = 1;
            }
            else{
                newNode->val=temp1->val + cnt;
                cnt = 0;
            }
            temp1=temp1->next;
            ans->next=newNode;
            ans=ans->next;
        }
        while(temp2!=NULL){
            ListNode* newNode = new ListNode();
            if(temp2->val+cnt>9){
                newNode->val=0;
                cnt = 1;
            }
            else{
                newNode->val=temp2->val+cnt;
                cnt = 0;
            }
            temp2=temp2->next;
            ans->next=newNode;
            ans=ans->next;
        }
        if(cnt == 1){
            ListNode* newNode = new ListNode();
            newNode->val=1;
            ans->next=newNode;
            ans=ans->next;
        }
        return reverse(res->next);
    }
};