class Solution {
public:
// -----------APPROACH 1 ------------// 

/* --------Time complexity: O(n), Space complexity: O(n) --------*/

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
// ---------------APPROACH 2  ------------------// 

class Solution {
    public:
/* ------    TIME COMPLEXITY ~ O(NLogK), SPACE COMPLEXITY: O(K)  ---------    */

    class compare{      // custom comparator for comparing ListNode vals
        public:
        bool operator()(ListNode* first,ListNode* second ) {
            return first->val > second->val;}
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;
        ListNode* head = NULL;
        ListNode* tail = NULL;

        for(int i=0; i < lists.size(); i++){
            if(lists[i] != NULL)
            minHeap.push(lists[i]);
        }
        while(minHeap.size() > 0){
            ListNode* top = minHeap.top();
            minHeap.pop();
            if(top->next != NULL){
                minHeap.push(top->next);
            }
            if(head == NULL){   
                head = top;
                tail = top;
            }
            else{
                tail -> next = top;
                tail = top;
            }
        }
        return head;
    }
};
