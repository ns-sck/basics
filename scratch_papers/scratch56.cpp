#pragma optimize("")
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int MOD = 1e9+7;
const int MAXN = 2e5 + 1;

vector<int> adj[MAXN];
int derinlikler[MAXN];

int32_t main() {
    ios;

    int node_sayisi;
    cin>>node_sayisi;
    for(int i=1; i<node_sayisi;i++){
        int parent;
        cin>>parent;
        adj[parent].push_back(i+1);
    }
    /*for (int i =1 ;i<= node_sayisi;i++) {
        cout << "Node " << i << ": ";
        for (int komsu: adj[i]) {
            cout << komsu << " ";
        }
        cout << endl;
    }
    */
    //deque
    //    curr_node, step
    int aranan_node;
    cin>>aranan_node;
    queue<pair<int,int>> q;

    q.push({1,0});

    while(!q.empty()){
        auto curr_element = q.front();
        q.pop();
        int curr_node = curr_element.first;
        int step = curr_element.second;
        derinlikler[curr_node] = step;
        for(int komsu: adj[curr_node]){
            q.push({komsu, step+1});
        }
    }
    cout<<derinlikler[aranan_node]<<endl;

    return 0;
}