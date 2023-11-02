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


ListNode* uniteSortedLists(std::vector<ListNode*> heads) {

    std::vector<ListNode*> all_nodes;

    for (int i = 0; i < heads.size(); i++) {
        while (heads[i]) {
            all_nodes.push_back(heads[i]);
            heads[i] = heads[i]->next;
        }
    }

    auto custom_sort = [](const ListNode* a, const ListNode* b)->bool {
        return a->val < b->val;
        };

    std::sort(all_nodes.begin(), all_nodes.end(), custom_sort);

    for (int i = 0; i < all_nodes.size() - 1; i++) {
        all_nodes[i]->next = all_nodes[i + 1];
    }
    all_nodes.back()->next = nullptr;

    return all_nodes[0];
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = nullptr;

    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(3);
    head2->next->next = new ListNode(5);
    head2->next->next->next = new ListNode(4);
    head2->next->next->next->next = new ListNode(5);
    head2->next->next->next->next->next = nullptr;

    ListNode* t = head;
    while (t) {
        std::cout << t->val;
        t = t->next;
    }
    std::cout << '\n';

    head = uniteSortedLists(std::vector<ListNode*>() = { head, head2 });

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
