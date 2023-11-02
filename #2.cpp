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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* current = head;

        while (current && current->next) {
            if (current->val == current->next->val) {
                // Duplicate found, skip the next node
                ListNode* duplicate = current->next;
                current->next = duplicate->next;
                delete duplicate; // Free the memory of the duplicate node
            } else {
                // Move to the next distinct element
                current = current->next;
            }
        }
        return head; // Return the updated linked list
    }
};