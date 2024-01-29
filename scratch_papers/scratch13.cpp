#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

    ListNode* temp1 = list1;
    ListNode* temp2 = list2;

    ListNode* new_list = new ListNode();
    ListNode* curr = new_list;
    
    while (temp1 || temp2) {

        if (temp1 && !temp2) {
            curr->next = new ListNode(temp1->val);
            curr = curr->next;
            temp1 = temp1->next;
        } else if (!temp1 && temp2) {
            curr->next = new ListNode(temp2->val);
            curr = curr->next;
            temp2 = temp2->next;
        } else if (temp1->val <= temp2->val) {
            curr->next = new ListNode(temp1->val);                                                                               
            curr = curr->next;
            temp1 = temp1->next;
        } else if (temp2->val <= temp1->val) {
            curr->next = new ListNode(temp2->val);
            curr = curr->next;
            temp2 = temp2->next;
        }
    }
    return new_list->next;
}

int main ()
{

    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    cout << mergeTwoLists(list1, list2)->next;
    return 0;
}