#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

class Node {
    public: 
    Node* left;
    Node* right;
    int data;
    Node (int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void inorder(Node* root) {

    stack<Node*> st;
    Node* temp = root;

    while (temp || !st.empty()) {

        while (temp) {
            st.push(temp);
            temp = temp->left;
        }

        temp = st.top();
        st.pop();

        cout << temp->data << ' ';

        temp = temp->right;
    }
}

void postorder (Node* root) {

    stack<Node*>st1;
    stack<Node*>st2;

    st1.push(root);
    Node* temp;
    while (!st1.empty()) {

        temp = st1.top();
        st1.pop();
        st2.push(temp);

        if (temp->left) {
            st1.push(temp->left);
        }
        if (temp->right) {
            st1.push(temp->right);
        }
    } 

    while (!st2.empty()) {
        cout << st2.top()->data << ' ';
        st2.pop();
    }
}

void preorder(Node* root) {

    if (!root)
        return;
        
    stack<Node*> st;
    st.push(root);
    Node* temp = root;

    while (!st.empty()) {

        temp = st.top();    
        st.pop();

        cout << temp->data << ' ';
        if (temp->right)
            st.push(temp->right);
        if (temp->left)
            st.push(temp->left);
    }
}

string serialize(Node* root) {
    
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    pair<Node*, int> temp;
    int lvl = 0;
    vector<string> v;
    string ans = "";

    while (!q.empty()) {

        temp = q.front();
        q.pop();

        if (temp.second != lvl) {
            
            for (auto& s : v) {
                ans += s + ",";
            }
            v.erase(v.begin(), v.end());
            lvl++;
        }
        if (!temp.first) {

            v.push_back("null");
            continue;

        } else { 
            v.push_back(to_string(temp.first->data));
        }

        q.push({temp.first->left, lvl + 1});
        q.push({temp.first->right, lvl + 1});
    }
    ans.erase(ans.begin() + ans.length() - 1);

    while (ans.substr(ans.length() - 4, 4) == "null") {
        ans.erase(ans.length() - 5, 5);
    }
    return ans;
}

int main ()
{

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);    


    postorder(root);
    return 0;
}