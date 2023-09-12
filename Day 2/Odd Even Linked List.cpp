class Solution {
public:
// -------Time complexity: O(n), Space complexity: O(1) -------//

    ListNode* oddEvenList( ListNode* head){
        if(!head || !head->next) return head;

        ListNode *odd = head , *even = head->next;
        ListNode *ans = head->next;

        while(odd->next && even->next ){
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = ans;
        return head;
    }
};
