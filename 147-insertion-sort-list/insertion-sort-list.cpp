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
    ListNode*midNode(ListNode*head){
        ListNode*slow=head;
        ListNode*fast=head;
        ListNode*prev=NULL;
        while(fast && fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=NULL;
        return slow;
    }
    ListNode*merge(ListNode*head,ListNode*mid){
        ListNode*st=head;
        ListNode*en=mid;
        ListNode*newHead=NULL;
        ListNode*newTail=NULL;
        while(st!=NULL && en!=NULL){
            if(st->val < en->val){
                if(newHead==NULL){
                    newHead=newTail=st;
                    st=st->next;
                }
                else{
                    newTail->next=st;
                    newTail=st;
                    st=st->next;
                }
            }
            else{
                if(newHead==NULL){
                    newHead=newTail=en;
                    en=en->next;
                }
                else{
                    newTail->next=en;
                    newTail=en;
                    en=en->next;
                }
            }
        }
        while(st!=NULL){
            newTail->next=st;
            newTail=st;
            st=st->next;
        }
        while(en!=NULL){
            newTail->next=en;
            newTail=en;
            en=en->next;
        }
        return newHead;
    }
    ListNode* mergeSort(ListNode*head){
        if(head==NULL || head->next==NULL){
            return head ;
        }
        ListNode*mid=midNode(head);
        head=mergeSort(head);
        mid=mergeSort(mid);
        return merge(head,mid);
    }
    ListNode* insertionSortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        return mergeSort(head);
    }
};