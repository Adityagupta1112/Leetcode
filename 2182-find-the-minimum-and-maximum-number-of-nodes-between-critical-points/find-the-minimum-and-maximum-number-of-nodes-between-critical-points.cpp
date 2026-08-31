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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>critical_point;
        vector<int>ans;
        ListNode*temp=head->next;
        ListNode*prev=head;
        int kth=2;
        while(temp->next!=NULL){
            ListNode*curr=temp;
            ListNode*next=temp->next;
            if(prev->val<curr->val && next->val<curr->val){
                critical_point.push_back(kth);
            }
            else if(prev->val>curr->val && next->val>curr->val){
                critical_point.push_back(kth);
            }
            kth++;
            prev=temp;
            temp=next;
        }
        int m=critical_point.size();

        if(m<2){
            return {-1,-1};
        }
        int minDistance=INT_MAX;
        int maxDistance=critical_point[m-1]-critical_point[0];

        for(int k=1;k<m;k++){
            int dist=critical_point[k]-critical_point[k-1];
            minDistance=min(minDistance,dist);
        }
        
        ans.push_back(minDistance);
        ans.push_back(maxDistance);
        return ans;
    }
};