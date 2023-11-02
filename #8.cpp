class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode start;
        start.next = head;
        ListNode* prev_group_end = &start;

        while(true){
            ListNode* group_start = prev_group_end->next,
                *next_group_start = group_start,
                *group_end = group_start;

            for(int i=0;i<k;i++){
                if(!next_group_start)
                    return start.next;
                next_group_start = next_group_start->next;
            }

            for(int i=0;i<k-1;i++){
                ListNode* temp = group_end->next;
                group_end->next = temp->next;
                temp->next = group_start;
                prev_group_end->next = temp;
                group_start = temp;
            }
            prev_group_end = group_end;
        }
        return start.next;
    }
};