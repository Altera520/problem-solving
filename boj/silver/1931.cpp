#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> &t, pair<int, int> &u){
    if(t.second == u.second) return t.first < u.first;
    return t.second < u.second;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, ans = 0, ed = 0;
    vector<pair<int, int>> conf;

    cin >> n;
    for(int i=0; i<n; i++){
        int from, to;
        cin >> from >> to;
        conf.push_back({from, to});
    }

    sort(conf.begin(), conf.end(), cmp);

    for(int i=0; i<n; i++){
        if(ed <= conf[i].first){
            ed = conf[i].second;
            ans++;
        }
    }

    cout << ans;
}