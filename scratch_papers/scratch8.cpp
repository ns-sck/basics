#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
};

Node* new_node(int data)
{
    Node* ptr = new Node;
    ptr->data = data;
    return ptr;
}

void add_node(Node*& head, int data)
{
    Node* ptr = new Node;

    if (head == NULL) {

        ptr->data = data;
        head = ptr;
    } else {
        Node *temp = head;

        
        while (temp->next != NULL) {
            
            if (head->data > data) {
                ptr->next = head;
                head->prev = ptr;
                head = ptr;
                return;
            }
            if (temp->next->data > data) {
                
                ptr->next = temp->next;
                temp->next->prev = ptr;
                temp->next = ptr;
                ptr->prev = temp;
                return;
            }

        }

            temp->next->next = ptr;
                ptr->prev = temp->next;
                return;
    }
}
int main ()
{

    Node* head = new Node;
    head->data = 1;
    head->next = new_node(2);
    head->next->next = new_node(3);
    head->next->next->next = new_node(5);

    return 0;
}