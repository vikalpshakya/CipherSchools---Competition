// Time complexity O(n) , space complexity = O(1) [not considering the recursive stack space] 

class Solution {
public:
    int lenght(ListNode*head){
        ListNode*temp = head; 
        int count=0;
        while ( temp!=NULL){
            temp=temp->next;
            count++;
        }
        return count;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL){
            return head;
        }
        // Base case 
        if(lenght(head)<k )
            return head;    
        ListNode*next =NULL;
        int count = 0;
        ListNode* prev=NULL;
        ListNode* current = head;
        while(current!=NULL&&count<k){
            next = current->next;
            current->next = prev;
            prev = current;
            current=next;
            count++;
        }
        if(next!=NULL){
            head->next= reverseKGroup(next,k);
        }
        return prev;
    }
};
