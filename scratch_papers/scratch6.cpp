#include <iostream>
using namespace std;

class Node 
{
    public:
        string name;
        int day;
        int time;
        Node* next;
};

void printList(Node* head)
{
    while(head) {
        cout << head->name << '-';
        head = head->next;
    }
    cout << '\n';
}

void lectures_at(Node* head, int day, int time)
{
    while(head) {
        if (head->day == day && head->time == time)
            cout << head->name << '-';
        head = head->next;
    }
}

Node* new_list(Node* head) {
    Node* new_head = NULL;
    Node* temp = NULL;

    while (head) {
        Node* new_node = new Node;
        *new_node = *head;

        if (!new_head) {
            new_head = new_node;
            new_head->next = NULL;
            head = head->next;
            continue;
        }

        temp = new_head;
        Node* prev = new_head;

        while (temp) {

            if (new_node->day < temp->day || (new_node->day == temp->day && new_node->time < temp->time)) {
                
                new_node->next = temp;
                if (temp == new_head) {
                    new_head = new_node;
                } else {
                    prev->next = new_node;
                }
                break;
            }

            if (!temp->next) {
                temp->next = new_node;
                new_node->next = NULL;
            }

            prev = temp;
            temp = temp->next;
        }

        head = head->next;
    }
    return new_head;
}

int main ()
{
    Node* head = NULL;

    Node* n = new Node;
    n->name = "math";
    n->day = 5;
    n->time = 2;

    Node* n1 = new Node;
    n1->name = "ds";
    n1->day = 2;
    n1->time = 2;

    Node* n2 = new Node;
    n2->name = "alg";
    n2->day = 3;
    n2->time = 1;

    Node* n3 = new Node;
    n3->name = "oop";
    n3->day = 2;
    n3->time = 1;

    head = n;
    n->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;

    // printList(head);
    // lectures_at(head, 3, 1);
    printList(new_list(head));
    return 0;
}