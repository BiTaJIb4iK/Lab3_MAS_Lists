class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next)
            return head;
        
        ListNode start_left;
        ListNode start_right;

        ListNode* tail_left = &start_left;
        ListNode* tail_right = &start_right;

        ListNode* current_node = head;

        while(current_node){
            if(current_node->val < x){
                tail_left -> next = current_node;
                tail_left = current_node;
            }else{
                tail_right ->next = current_node;
                tail_right = current_node;
            }
            current_node = current_node->next;
        }

        tail_left->next = start_right.next;

        if(tail_right != nullptr){
            tail_right->next = nullptr;
        }

        return start_left.next;
    }
};