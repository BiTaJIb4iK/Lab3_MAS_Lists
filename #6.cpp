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
    ListNode() : val(0), next(nullptr) {}
};

int nodeMultiply(ListNode* head) {
    if (!head)
        return 0;

    head->val = head->val * 2 + nodeMultiply(head->next);
    if (head->val >= 10) {
        head->val -= 10;
        return 1;
    }
    return 0;
}

ListNode* multiplyListBy2(ListNode* head) {
    if (!head || !head->next)
        return head;

    if (nodeMultiply(head)) {
        ListNode* temp = new ListNode;
        temp->next = head;
        temp->val = 1;
        head = temp;
    }
    else
        return head;

}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = nullptr;

    ListNode* t = head;
    while (t) {
        std::cout << t->val;
        t = t->next;
    }
    std::cout << '\n';

    head = multiplyListBy2(head);

    t = head;
    while (t) {
        std::cout << t->val;
        t = t->next;
    }

    delete head->next->next;
    delete head->next;
    delete head;

    return 0;
}
