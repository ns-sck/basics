/* @Author
Student Name : Enes Saçak
StudentID : 150210014
Date : 16.12.2023 */

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <time.h>
#include <stack>
#include <queue>
using namespace std;

class Employee {

    private:
        int id;
        int salary;
        int department;
    public:
        Employee(int, int, int);
        ~Employee();
        int get_id();
        int get_salary();
        int get_department();
        void set_salary(int);
        void set_id(int);
        void set_department(int);
};

class Node {

    private:    
        Employee* employee;
        Node* left;
        Node* right;
    public:
        Node(Employee*);
        ~Node();
        Employee* get_employee();
        void set_employee(Employee*);
        Node* get_left();
        Node* get_right();
        void set_left(Node*);
        void set_right(Node*);
};

class BinaryTree {
    
    private:
        Node* root;
        string out_str;
        int getHeight(Node* root);
    public:
        BinaryTree();
        void insert(Employee*);
        void remove(int id);
        void update(int id, int salary, int department);
        Employee *search(int id);
        int getHeight();
        void printToFile(ofstream &output_file);
        void printToConsole();
        Node* find_successor(Node* root);
};

Employee::Employee(int id, int salary, int department)
{
    this->id = id;
    this->salary = salary;
    this->department = department;
}

Employee::~Employee() {}

    // set this employee's id with given number
void Employee::set_id(int id) {this->id = id;}

    // set this employee's salary with given number
void Employee::set_salary(int salary) {this->salary = salary;}

    // set this employee's department with given number
void Employee::set_department(int department) {this->department = department;}

    // get this employee's id
int Employee::get_id() {return this->id;}

    // get this employee's salary
int Employee::get_salary() {return this->salary;}

    // get this employee's department
int Employee::get_department() {return this->department;}

    // ----------------------------------------------------------------------

Node::Node(Employee* employee) 
{
    this->employee = employee;
    this->left = nullptr;
    this->right = nullptr;
}

Node::~Node() {}

Employee* Node::get_employee() {return this->employee;}

void Node::set_employee(Employee* employee) {this->employee = employee;}

Node* Node::get_left() {return this->left;}

Node* Node::get_right() {return this->right;}

void Node::set_left(Node* left) {this->left = left;}

void Node::set_right(Node* right) {this->right = right;}

    // ----------------------------------------------------------------------

BinaryTree::BinaryTree() {this->root = nullptr;}

void BinaryTree::insert(Employee* new_emp)
{   
    // create new node with given employee
    Node* new_node = new Node(new_emp);
    // if there is empty, set it's root to new node
    if (!root) {
        root = new_node;
        return;
    }

    Node* current = root;
    Node* parent = nullptr;
    // find new node's place and it's parent 
    while (current) {
        parent = current;

        if (new_emp->get_id() < current->get_employee()->get_id()) {
            current = current->get_left();
        } else {
            current = current->get_right();
        }
    }
    // if smaller than parent, set left and vice versa
    if (new_emp->get_id() < parent->get_employee()->get_id()) {
        parent->set_left(new_node);
    } else {
        parent->set_right(new_node);
    }
}

void BinaryTree::remove(int id) {
    
    // if the tree is empty
    if (!root) {
        cout << "ERROR: There is no employee\n";
        return;
    }

    Node* current = root;
    Node* parent = nullptr;

    // Find the node to be removed and it's parent node
    while (current && current->get_employee()->get_id() != id) {
        parent = current;

        if (id < current->get_employee()->get_id()) {
            current = current->get_left();
        } else {
            current = current->get_right();
        }
    }

    // Check if the node with the given id was found
    if (!current) {
        cout << "ERROR: An invalid ID to delete\n";
        return;
    }

    // If current node has at most one child
    if (!current->get_left() || !current->get_right()) {
        Node* temp = (current->get_left()) ? current->get_left() : current->get_right();

        if (!parent) {
            root = temp;
        } else if (parent->get_left() == current) {
            parent->set_left(temp);
        } else {
            parent->set_right(temp);
        }
        current->set_employee(nullptr);
        delete current;
    // If current node has two children
    } else {
        // set successor to root of the right subtree of current node
        Node* successor_p = current;
        Node* successor = current->get_right();
        // if it is already the leftmost node of right subtree,
        // set current node's right as successor's right child
        if (!successor->get_left()) {
            // replace current node with successor
            current->set_employee(successor->get_employee());
            successor_p->set_right(successor->get_right());
        } else {
        // if not, find the leftmost node by going only left
            while (successor->get_left()) {
                successor_p = successor;
                successor = successor->get_left();
            }
            // replace current node with successor
            current->set_employee(successor->get_employee());
            // successor can have it's right subtree
            successor_p->set_left(successor->get_right());
        }
        successor->set_employee(nullptr);
        delete successor;
    }
}

void BinaryTree::update(int id, int salary, int department)
{   
    // search function returns the employee's address with given id
    Employee* toUpdate = search(id);
    // if search function returns null, there is no employee with given id
    if (!toUpdate) {
        cout << "ERROR: An invalid ID to update\n";
        return;
    }
    // change salary and department of the employee
    toUpdate->set_salary(salary);
    toUpdate->set_department(department);
}

Employee* BinaryTree::search(int id)
{
    // if the tree is empty, return nullptr
    if (!root)
        return nullptr;

    Node* temp = root;
    // search the employee with given id using bst logic
    while (temp && temp->get_employee()->get_id() != id) {

        if (id < temp->get_employee()->get_id()) {
            temp = temp->get_left();
        } else {
            temp = temp->get_right();
        }
    }
    // if found return temp, if not return nullptr
    return temp ? temp->get_employee() : nullptr;
}

int BinaryTree::getHeight()
{   
    if (!root) {
        return 0;
    }

    // Create a queue for level-order traversal
    queue<Node *> nodeQueue;
    nodeQueue.push(root);
    int depth = 0;

    // level order traversal
    while (!nodeQueue.empty()) {
        // number of nodes at the current level
        int levelSize = nodeQueue.size();

        // Process nodes at the current level
        for (int i = 0; i < levelSize; ++i) {
            Node *current = nodeQueue.front();
            nodeQueue.pop();

            // ennqueue left and right children if they exist
            if (current->get_left()) {
                nodeQueue.push(current->get_left());
            }
            if (current->get_right()) {
                nodeQueue.push(current->get_right());
            }
        }
        // increment the depth after processing a level
        ++depth;
    }

    return depth;
}

void BinaryTree::printToConsole()
{   
    cout << "P\n";
    if (!root)
        return;

    // use stack for preorder traversal
    stack<Node*> nodeStack;
    nodeStack.push(root);

    while (!nodeStack.empty())
    {
        Node* current = nodeStack.top();
        nodeStack.pop();

        cout << current->get_employee()->get_id() << ';'
                  << current->get_employee()->get_salary() << ';'
                  << current->get_employee()->get_department() << '\n';

        // push right first, so pop it last
        if (current->get_right())
            nodeStack.push(current->get_right());

        if (current->get_left())
            nodeStack.push(current->get_left());
    }
}

void BinaryTree::printToFile(ofstream& output_file)
{   
    // print the header line
    output_file << "Employee_ID;Salary;Department\n";
    if (!root)
        return;

    Node* current = root;
    stack<Node*> nodeStack;

    // inorder traversal using stack
    while (current || !nodeStack.empty()) {

        while (current) {
            nodeStack.push(current);
            current = current->get_left();
        }

        current = nodeStack.top();
        nodeStack.pop();

        out_str += to_string(current->get_employee()->get_id()) + ';'
                    + to_string(current->get_employee()->get_salary()) + ';'
                    + to_string(current->get_employee()->get_department()) + '\n';

        current = current->get_right();
    }
    output_file << out_str;
}

int main (int argc, char** argv)
{   
    fstream read_file;
    string line, id, salary, department, operation;
    int maxEmployeeID = 0;
    BinaryTree bt = BinaryTree();

    read_file.open(argv[1]);
    // check the file is open or not
    if (!read_file.is_open()) {
        cout << "ERROR: File can not be opened!";
    }

    getline(read_file, line);
    while (getline(read_file, line)) {

        istringstream ss(line);
        getline(ss, id, ';');
        getline(ss, salary, ';');
        getline(ss, department);
        Employee* new_emp = new Employee(stoi(id), stoi(salary), stoi(department));
        bt.insert(new_emp);
        maxEmployeeID = max(maxEmployeeID, stoi(id));
    }

    maxEmployeeID++;
    read_file.close();
    // close the dataset file and open operations file
    read_file.open(argv[2]);

    if (!read_file.is_open()) {
        cout << "ERROR: File can not be opened!";
    }
    // read operation file and call functions related to it
    while(getline(read_file, line)) {

        istringstream ss_2(line);
        getline(ss_2, operation, ';');
        // call add function if the operation is ADD
        if (operation == "ADD") {
            
            getline(ss_2, salary, ';');
            getline(ss_2, department, '\r');
            // clock_t start = clock();
            Employee* new_emp = new Employee(maxEmployeeID++, stoi(salary), stoi(department));
            bt.insert(new_emp);
            // clock_t end = clock();
            // cout << "ADD: binary_tree_solution: " (double)(end - start) * 1000 / CLOCKS_PER_SEC << "milliseconds\n"
        }
        // call delete function if the operation is DELETE
        else if (operation == "DELETE") {

            getline(ss_2, id, '\r');
            // clock_t start = clock();
            bt.remove(stoi(id));
            // clock_t end = clock();
            // cout << "DELETE: binary_tree_solution: " << (double)(end - start) * 1000 / CLOCKS_PER_SEC << "milliseconds\n";
        }
        // call update function if the operation is UPDATE
        else if (operation == "UPDATE") {

            getline(ss_2, id, ';');
            getline(ss_2, salary, ';');
            getline(ss_2, department, '\r');
            // clock_t start = clock();
            bt.update(stoi(id), stoi(salary), stoi(department));
            // clock_t end = clock();
            // cout << "UPDATE: binary_tree_solution: " << (double)(end - start) * 1000 / CLOCKS_PER_SEC << "milliseconds\n";
        }
        // call printToConsole function if the operation is PRINT
        else if (operation == "PRINT\r" || operation == "PRINT") {
            bt.printToConsole();
        }
        // call getHeight function if the operation is HEIGHT
        else if (operation == "HEIGHT\r" || operation == "HEIGHT") {
            cout << "H " << bt.getHeight() << '\n';
        }
    }
    read_file.close();
    ofstream output_file("output.csv");
    bt.printToFile(output_file);
    output_file.close();
    return 0;
}