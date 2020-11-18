#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n,m;
    vector<vector<int>> tree;
    vector<int> level, parrent;
    queue<int> q;

    cin >> n;

    tree.resize(n+1);
    level.resize(n+1);
    parrent.resize(n+1);

    //generate tree
    for(int i=1; i<n; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;

        tree[tmp1].push_back(tmp2);
        tree[tmp2].push_back(tmp1);
    }

    //get level and parrent
    q.push(1);
    level[1] = 1;
    
    while(!q.empty()){
        int elem = q.front();

        for(int node: tree[elem]){
            if(level[node]==0){
                q.push(node);
                level[node] = level[elem]+1;
                parrent[node] = elem;
            }
        }

        q.pop();
    }

    //LCA
    cin >> m;
    while(m-- > 0){
        int a, b;
        cin >> a >> b;

        while(a!=b){
            
            if(level[a] > level[b]){
                a = parrent[a];
                
            }
            else if(level[a] < level[b]){
                b = parrent[b];
                
            }
            else{
                a = parrent[a];
                b = parrent[b];
            }
        }

        cout << a << endl;
    }
}