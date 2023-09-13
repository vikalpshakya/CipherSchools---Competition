class Solution {
public:
// -------Time complexity: O(n), Space complexity: O(1)--------//

    ListNode* rotateRight(ListNode* head, int k) {
        if( !head || !head->next || k == 0) return head;
        int len = 1;
        ListNode* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
            len++;}  
        temp->next = head;
        k = k % len;
        k = len - k;
        while(k--){
            temp = temp->next;}
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};
