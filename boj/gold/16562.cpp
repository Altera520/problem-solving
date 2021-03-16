#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 10001

using namespace std;

int root[MAX];
int depth[MAX]; //union by rank

bool cmp(pair<int,int> &t, pair<int,int> &u) {
    return t.second < u.second;
}

void init(int n){
    for(int i=1; i<=n; i++){
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
    int n, m, k;
    int ans = 0, count = 1, src;
    vector<pair<int,int>> friends;

    // input
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        pair<int,int> temp; // index, money
        temp.first = i;
        cin >> temp.second;
        friends.push_back(temp);
    }

    init(n);
    while(m-- > 0) {
        int from, to;
        cin >> from >> to;
        do_union(from, to);
    }

    sort(friends.begin(), friends.end(), cmp);

    if(friends[0].second > k) {
        cout << "Oh no";
        return 0;
    }

    src = friends[0].first;
    ans += friends[0].second;
    k -= friends[0].second;

    for(int i = 1; i < n; i++) {
        int dest = friends[i].first;

        if(find(src) == find(dest)) {
            count++;
            continue;
        }
        if(friends[i].second > k) {
            continue;
        }

        do_union(src, dest);
        k -= friends[i].second;
        ans += friends[i].second;
        count++;
    }

    if(count != n) {
        cout << "Oh no";
    } else {
        cout << ans;
    }
}