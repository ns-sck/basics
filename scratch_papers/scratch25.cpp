#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int main ()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    int k = 2;
    ListNode* sentinel = new ListNode();
    sentinel->next = head;
    head = sentinel;
    ListNode* temp = sentinel;
    bool cant = false;
    while (true) {

        vector<ListNode*> v;
        ListNode* temp2 = temp;
        for (int i = 0; i < k; i++) {

            if (temp2->next == nullptr) {
                cant = true;
                break;
            }
        
            v.push_back(temp2->next);
            temp2 = temp2->next;
        }
        if (cant)
            break;

        v[0]->next = v[v.size() - 1]->next;
        for (int i = v.size() - 1; i >= 1; i--) {
            v[i]->next = v[i-1];
        }
        temp->next = v[v.size() - 1];
        temp = v[0];
        cant = false;
    }
    return 0;
}