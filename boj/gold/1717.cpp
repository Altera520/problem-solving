#include <iostream>
#define MAX 1000001
using namespace std;

int root[MAX];
int depth[MAX]; //union by rank

void init(int n){
    for(int i=0; i<=n; i++){
        root[i] = i;
        depth[i] = 0;
    }
}

int find(int node){
    if(root[node] == node){
        return node;
    }
    else{
        return root[node] = find(root[node]); //path compression, O(logN)
    }
}

void do_union(int x, int y){
    x = find(x);
    y = find(y);

    if(x==y) return;

    if(depth[x] < depth[y]){
        root[x] = y;
    }
    else{
        root[y] = x;

        if(depth[x] == depth[y]){
            depth[x]++;
        }
    }
}

int main() {
    cin.tie(NULL);
	cin.sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    init(n);

    while(m-- > 0){
        int op, x, y;
        cin >> op >> x >> y;

        if(op==0){
            do_union(x,y);
        }
        else{
            cout << (find(x) == find(y) ? "YES" : "NO") << '\n';
        }
    }
}