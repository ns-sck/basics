#include <iostream>
using namespace std;

struct Node{

    char data;
    Node *next;
};

struct Stack{

    Node *head = NULL;
    void create();
    void close();
    void push(char);
    void pop();
    bool isempty();
    char top();
};

bool Stack::isempty(){
    if (head == NULL)
        return true;
    else
        return false;
}

void Stack::push(char newdata){

    Node *newnode = new Node;
    newnode->data = newdata;
    newnode->next = head;
    head = newnode;
}

void Stack::pop()
{
    Node *topnode;
    topnode = head;
    head = head->next;
    delete topnode;
}

char Stack::top()
{
    return head->data;
}

void removeduplicates(Stack& st)
{
    Stack temp;

    while (!st.isempty()) {
        
        if (temp.isempty()) {
            temp.push(st.top());
            st.pop();
            continue;
        }
        if (st.top() == temp.top())
            st.pop();
        else {
            temp.push(st.top());
            st.pop();
        }
    }

    while (!temp.isempty()) {

        st.push(temp.top());
        temp.pop();
    }
}

void print(Stack st)
{
    Stack temp = st;
    while(!temp.isempty()) {
        
        cout << temp.top();
        temp.pop();
    }
}

int main ()
{

    // a a a a b b c d d y
    Stack st;
    st.push('y');
    st.push('d');
    st.push('d');
    st.push('c');
    st.push('b');
    st.push('b');
    st.push('a');
    st.push('a');
    st.push('a');
    st.push('a');


    removeduplicates(st);

    print(st);

    return 0;
}