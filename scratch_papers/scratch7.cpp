    #include <iostream>
    #include <string>
    #include <vector>
    using namespace std;


    class Node{
        public:
        int data;
        Node* next;
        Node(int);
        Node();
    };

    Node::Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    Node::Node()
    {
        this->next = NULL;
    }
    void printNode(Node* head)
    {
        while(head != NULL){
            cout << head->data;
            head = head->next;
        }
    }

    void append(Node*& head, int data)
    {
        if (!head) {
            head = new Node(data);
            return;
        }
        Node* last = head;
        while(last->next != NULL){
            last = last->next;
        }
        Node* new_node = new Node();
        new_node->data = data;
        new_node->next = NULL;
        last->next = new_node;
    }

        Node* addTwoNumbers(Node* l1, Node* l2) {
        
        Node* new_list = NULL;
        Node* current;
        int carry = 0;

        while (l1 || l2 || carry) {
            int sum = (l1 ? l1->data : 0) + (l2 ? l2->data : 0) + carry;
            carry = sum / 10;

            if (!new_list) {
                new_list = new Node(sum % 10);
                current = new_list;
            } else {
                current->next = new Node(sum % 10);
                current = current->next;
            }
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        return new_list;
    }

    int main () 
    {

        Node* head1 = NULL;
        Node* head2 = NULL; 
        
        append(head1, 1);
        append(head1, 2);
        append(head1, 9);
        append(head2, 6);
        append(head2, 3);
        append(head2, 5);
        // 921 + 536 = 1457
        Node* result = addTwoNumbers(head1, head2); // Skip the dummy nodes

        printNode(result); // Print the result

        return 0;
    }