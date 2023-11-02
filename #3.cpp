#include <iostream>
#include <string.h>
#include <vector>
#include <random>
#include <unordered_set>

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {}
};

bool hasCycle(ListNode* head) {
    if (!head || !head->next) {
        return false;
    }

    ListNode* slow = head;
    ListNode* fast = head->next;

    while (slow != fast) {
        if (!fast || !fast->next) {
            return false;
        }
        slow = slow->next;
        fast = fast->next->next;
    }

    return true;
}

int main() {
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = nullptr;

    if (hasCycle(head)) {
        std::cout << "There is cycle!" << std::endl;
    }
    else {
        std::cout << "There is NOT cycle!" << std::endl;
    }

    delete head->next->next->next;
    delete head->next->next;
    delete head->next;
    delete head;

    return 0;
}
