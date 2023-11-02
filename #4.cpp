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

ListNode* mixTask(ListNode* head) {
    if (!head || !head->next)
        return head;

    std::vector<ListNode*> vect;

    while (head) {
        vect.push_back(head);
        head = head->next;
    }

    std::vector<ListNode*> vect2;

    int l = 0, r = vect.size() - 1;
    int i = 0;

    while (l <= r) {
        if (i % 2 == 0) {
            vect2.push_back(vect[l++]);
        }
        else {
            vect2.push_back(vect[r--]);
        }
        i++;
    }

    for (int i = 0; i < vect2.size() - 1; i++) {
        vect2[i]->next = vect2[i + 1];
    }

    vect2.back()->next = nullptr;

    return vect2[0];
}

//   Wrong Formula 

ListNode* mixNotTheTask(ListNode* head) {
    if (!head || !head->next)
        return head;

    std::vector<ListNode*> vect;

    std::vector<ListNode*> normal_part, reversed_part;

    for (int i = 0;head; i++) {
        if (i % 2 == 0)
            normal_part.push_back(head);
        else
            reversed_part.push_back(head);

        head = head->next;
    }

    std::reverse(reversed_part.begin(), reversed_part.end());

    int n = normal_part.size(), m = reversed_part.size();

    int i = 0, j = 0;

    while (i < n && j < m) {
        vect.push_back(normal_part[i]);
        vect.push_back(reversed_part[j]);
        i++;
        j++;
    }
    while (i < n) {
        vect.push_back(normal_part[i]);
        i++;
    }
    while (j < m) {
        vect.push_back(reversed_part[j]);
        j++;
    }

    for (int i = 0; i < vect.size() - 1; i++) {
        vect[i]->next = vect[i + 1];
    }

    vect.back()->next = nullptr;

    return vect[0];
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

    head = mixTask(head);

    t = head;
    while (t) {
        std::cout << t->val;
        t = t->next;
    }

    delete head->next->next->next;
    delete head->next->next;
    delete head->next;
    delete head;

    return 0;
}
