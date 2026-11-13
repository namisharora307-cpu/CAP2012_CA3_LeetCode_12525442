class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* temp = head;
        int count = 0;

        while (temp != NULL && count < k) {
            temp = temp->next;
            count++;
        }

        
        if (count == k) {
            ListNode* prev = NULL;
            ListNode* curr = head;
            ListNode* next = NULL;

            for (int i = 0; i < k; i++) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

           
            head->next = reverseKGroup(curr, k);

            return prev;
        }

        return head;
    }
};

