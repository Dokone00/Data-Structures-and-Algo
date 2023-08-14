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

    ListNode *mergetwolist(ListNode *l1 , ListNode *l2){

        if(l1==NULL)return l2;
        if(l2==NULL)return l1;
        if(l1->val<=l2->val){
            
            l1->next = mergetwolist(l1->next,l2);
            return l1;
        }else{
            l2->next =mergetwolist(l1,l2->next);
            return l2;
        }
        return NULL;
    }

    ListNode *breakandjoin(int start,int end,vector<ListNode*>& lists){
        if(start>end){
            return NULL;
        }
        if(start==end){
            return lists[start];
        }
        int mid = start+(end-start)/2;
        ListNode *list1 = breakandjoin(start,mid,lists);
        ListNode *list2 = breakandjoin(mid+1,end,lists);

        return mergetwolist(list1,list2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k= lists.size();
        if(k==0){
            return NULL;
        }
        return breakandjoin(0,k-1,lists);
    }
};