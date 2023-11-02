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

ListNode* removeNodeValue(ListNode* head, int value) {
    ListNode dum;
    dum.next = head;

    ListNode* prev = &dum;

    while (head) {
        if (head->val == value) {
            prev->next = head->next;
            delete head;
            break;
        }
        prev = head;
        head = head->next;
    }

    return dum.next;
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

    head = removeNodeValue(head, 100);

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
