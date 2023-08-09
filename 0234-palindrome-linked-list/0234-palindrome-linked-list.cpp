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
ListNode* getMiddle(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head -> next;

    while ( fast != NULL && fast -> next != NULL){
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    return slow;
}
ListNode* reverse(ListNode* head){
    ListNode* curr = head;
    ListNode* prev = NULL;
    ListNode* next = NULL;

    while( curr != NULL){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
class Solution {

public:
    bool isPalindrome(ListNode* head) {
        if(head -> next == NULL){
            return true;
        }
        if(head -> next -> next == NULL){
            if(head -> val != head -> next -> val){
                return false;
            }
        }
        ListNode* middle = getMiddle(head);
        ListNode* temp = middle -> next;
        middle -> next = reverse(temp);

        ListNode* h1 = head;
        ListNode* h2 = middle -> next;

        while(h2 != NULL){
            if(h1 -> val != h2 -> val){
                return false;
            }
            h1 = h1->next;
            h2 = h2->next; 
        }
        temp = middle -> next;
        middle -> next = reverse(temp);
        return true;
       
    }
};

// Approch - t.c = O(n) and S.C. = O(n)

// #include<vector>
// bool checkP(vector<int>arr){
//     int s = 0, e=arr.size()-1;
//     while(s<=e){
//         if(arr[s] != arr[e]){
//             return 0;
//         }
//         s++;
//         e--;
//     }
//     return 1;
        
// }
// class Solution {

// public:
//     bool isPalindrome(ListNode* head) {
//         vector<int>arr;
//         ListNode* temp = head;

//         while(temp != NULL){
//             arr.push_back(temp->val);
//             temp=temp->next;
//         }
//         return checkP(arr);
//     }
// };