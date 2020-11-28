#include <iostream>
#include <unordered_map>
#define MAX 200001
using namespace std;

int root[MAX];
int count[MAX];
int depth[MAX]; //union by rank

void init(int n){
    for(int i=1; i<=n; i++){
        root[i] = i;
        depth[i] = 0;
        count[i] = 1;
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

int do_union(int x, int y){
    int result;
    x = find(x);
    y = find(y);

    if(x==y) return count[x];

    if(depth[x] < depth[y]){
        root[x] = y;
        count[y] += count[x];
        result = count[y];
    }
    else{
        root[y] = x;
        count[x] += count[y];
        result = count[x];

        if(depth[x] == depth[y]){
            depth[x]++;
        }
    }

    return result;
}

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int t;
    cin >> t;

    while(t-- > 0){
        int f, pt = 1;
        unordered_map<string, int> map;
        cin >> f;
        init(f*2);

        while(f-- > 0){
            string friend1, friend2;
            cin >> friend1 >> friend2;

            if(map.find(friend1) == map.end()){
                map[friend1] = pt++;
            }
            if(map.find(friend2) == map.end()){
                map[friend2] = pt++;
            }

            cout << do_union(map[friend1], map[friend2]) << '\n';
        }
    }
}