#include <iostream>
using namespace std;

struct Node{

    char data;
    Node* next;
};
typedef Node list;

list* emptyList()
{
    Node* l = new Node;
    l->data = '\0';
    l->next = NULL;
    return l;
}

void add(list* l, char c)
{
    if (l->next == NULL && l->data == '\0') {
        l->data = c;
        return;
    }
    
    while (l->next) {
        l = l->next;
    }

    Node* new_node = new Node;
    new_node->next = NULL;
    new_node->data = c;
    l->next = new_node;
}

void deleteList(list* l) {

    Node* temp = l;
    while (l->next) {

        while (temp->next->next) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
        temp = l;
    }
    
    delete l;
}

void print(list* l)
{
    Node* temp = l;

    while(temp) { // dene
        
        cout << temp->data;
        temp = temp->next;
    }
    cout << '\n';
}

void addAll (list* l, const char* c)
{
    while (*c != '\0') {
        
        add(l, *(c++));
    }
}

void replace(list* l, char o, char n)
{   
    while(l->data != o) {
        l = l->next;
    }
    l->data = n;
}

list* split(list* l, char c)
{
    while (l->next) {
        if (l->next->data == c) {

            Node* temp = l->next->next;
            delete l->next;
            l->next = NULL;
            return temp;  
        }
        l = l->next;
    }
    return NULL;
}

int main ()
{
    list* l = emptyList();
    addAll(l, "istanbul teknik universitesi");
    list* k = l;
    
    do{
        
        l = split(k, ' ');
        replace(k, k->data, k->data-32);
        print(k);
        deleteList(k);
        k = l;

    }while(k!=NULL);


    return 0;
}