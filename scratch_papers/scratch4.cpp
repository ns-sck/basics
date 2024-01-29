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
    char pop();
    bool isempty();

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

char Stack::pop()
{   
    char temp = head->data;
    Node *topnode = head;
    head = head->next;
    delete topnode;
    return temp;
}

void removeduplicates(Stack& st)
{
    Stack temp;
    temp.push(st.pop());

    while (!st.isempty()) {
        
        char a = st.pop();
        char b = temp.pop();
        if (a == b) {
            temp.push(b);
        } else {
            temp.push(b);
            temp.push(a);
        }
    }

    while (!temp.isempty()) {

        st.push(temp.pop());
    }
}

// void removeduplicates(Stack & init_stack)
// {
//     Stack temp_stack;
//     char ch, previous;
//     ch = init_stack.pop();
//     previous = ch;
//     temp_stack.push(ch);
//     while (!init_stack.isempty()){

//         ch = init_stack.pop();
//         if (previous != ch) {

//             temp_stack.push(ch);
//             previous = ch;
//         }
//     }

//     while (!temp_stack.isempty()){

//         ch = temp_stack.pop();
//         init_stack.push(ch);
//     }
// }

void print(Stack st)
{
    Stack temp = st;
    while(!temp.isempty()) {
        
        cout << temp.pop();
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

    // char Text[9] = "Sandrine";
    // for(char *Ptr = Text; *Ptr != '\0'; ++Ptr)
    // cout << Ptr << endl;

    int a[10];
    int b[10];
    int*d = b;

    return 0;
}