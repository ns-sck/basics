#include <iostream>
using namespace std;

struct Student{
    
    string name;
    int *grades;
    Student *next;
};

struct StudentList{

    Student *head;
    void create();
    void add(Student *newptr);
    void print();
};

void StudentList::create()
{
    head=NULL;

}

void StudentList::add(Student* newptr)
{
    Student *n=new Student();
    *n=*newptr;
    if(head==NULL){
    head=n;
    return;
    }
    n->next=head;
    head=n;
}

void StudentList::print()
{   
    while(head) {
    
    cout << head->name;
    for (int i = 0; i < 3; i++) {

        cout << head->grades[i];
    }
    cout << '\n';
    head = head->next;    
    }
}


int main ()
{

    StudentList sl;
    sl.create();

    string name="Ali"; int grades[]={20,50,80};
    Student newnode={name,grades,NULL};
    /*A1*/sl.add(&newnode);

    name="Veli"; grades[0]=100; grades[1]=100; grades[2]=100;
    newnode.grades=grades; newnode.name=name;
    /*A2*/sl.add(&newnode);

    char name2[]="mehmet"; newnode.name=name2;
    /*A3*/sl.add(&newnode);

    sl.print();

    return 0;
}