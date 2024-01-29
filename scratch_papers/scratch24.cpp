#include <iostream>
#include <vector>
using namespace std;

class ListNode {
    public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* head = new ListNode(-10001);
ListNode* tail = head;

void insert (ListNode* new_node) 
{
    ListNode* n = new ListNode(new_node->val);
    if (n->val > tail->val) {

        tail->next = n;
        tail = tail->next;
        return;

    } else {

        if (head->val > n->val) {
            n->next = head;
            head = n;
            return;
        }
        ListNode* temp = head;
        while (temp != tail && temp->next->val < n->val) {
            temp = temp->next;
        }
        n->next = temp->next;
        temp->next = n;
        if (temp == tail)
            tail = n;
    }
}
ListNode* mergeKLists(vector<ListNode*>& lists) 
{   
    int size = lists.size();
    for (int i = 0; i < size; i++) {

        if (lists[i] == nullptr) {
            lists.erase(lists.begin() + i);
            size--;
            i--;
        }
    }
    
    while (!lists.empty()) {

        size = lists.size();

        for (int i = 0; i < size; i++) {

            insert(lists[i]);
            lists[i] = lists[i]->next;
            if (lists[i] == nullptr) {
                lists.erase(lists.begin() + i);
                size--;
                i--;
            }
        }
        
    }

    return head->next;
}
int main ()
{
    vector<ListNode*> lists;
    ListNode* p1 = new ListNode(1);
    p1->next = new ListNode(4);
    p1->next->next = new ListNode(5);

    ListNode* p2 = new ListNode(1);
    p2->next = new ListNode(3);
    p2->next->next = new ListNode(4);

    ListNode* p3 = new ListNode(2);
    p3->next = new ListNode(6);

    lists.push_back(p1);
    lists.push_back(p2);
    lists.push_back(p3);

    cout << mergeKLists(lists)->val;
    return 0;
}