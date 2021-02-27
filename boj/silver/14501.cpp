#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, ans = 0;
    vector<int> d;
    vector<pair<int, int>> table;

    cin >> n;
    d.resize(n + 1);
    table.resize(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> table[i].first;
        cin >> table[i].second;
    }

    for(int i = n; i >= 0; i--){
        if(table[i].first + i - 1 > n) continue;

        int val = 0;
        for(int j = table[i].first + i; j <= n; j++){
            val = max(d[j], val);
        }

        d[i] = table[i].second + val;
    }

    for(int i = 1; i <= n; i++){
        ans = max(d[i], ans);
    }

    cout << ans;
}