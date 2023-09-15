class Solution {
public:
/* --------Time complexity: O(n*k), Space complexity: O(n*k) --------*/

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int index=-1;
        for(int i = 0; i < lists.size(); i++){
            ListNode* temp = lists[i];
            if(temp){
                index = i;
                break;
            }
        }
        if(index == -1){
            return NULL;
        }
        vector<int>ans;
        ListNode* temp;
        for(int i = index; i < lists.size(); i++){
            temp = lists[i];
            while(temp != NULL){
                ans.push_back(temp->val);
                temp = temp->next;
            }
        }
        sort(ans.begin(),ans.end());
        ListNode* dummy = new ListNode(ans[0]);
        temp = dummy;
        for(int i = 1; i < ans.size()&&temp; i++){
            ListNode* newNode = new ListNode(ans[i]);
            temp->next = newNode;
            temp = temp->next;
        }
        return dummy;
    }
};
