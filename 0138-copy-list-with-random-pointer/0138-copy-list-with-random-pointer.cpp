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
void insertNode(Node* &head, Node* &tail,int d){
    Node* newNode = new Node(d);
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    else{
        tail -> next = newNode;
        tail = newNode;
    }
}

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;

        Node* temp = head;
        while(temp!=NULL){
            insertNode(cloneHead,cloneTail,temp->val);
            temp = temp->next;
        }
        unordered_map<Node*,Node*>mapping;
        Node* temp1 = head;
        Node* temp2 = cloneHead;

        while(temp1!=NULL && temp2!=NULL){
            mapping[temp1]=temp2;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        temp1 = head;
        temp2 = cloneHead;

        while(temp1!=NULL && temp2 != NULL){
            temp2->random = mapping[temp1->random];
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return cloneHead;

    }
};