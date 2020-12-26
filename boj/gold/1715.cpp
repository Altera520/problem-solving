#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int main() {
    int n, merge = 0, ans = 0;
    vector<int> card;
    priority_queue<int, vector<int>, greater<int>> pq;

    cin >> n;
    card.resize(n + 1);

    for(int i=1; i<=n; i++){
        cin >> card[i];
        pq.push(card[i]);
    }

    while(!pq.empty()){
        int tmp = pq.top();
        merge += tmp;
        pq.pop();

        if(merge > tmp){
            ans += merge;
            pq.push(merge);
            merge = 0;
        }
    }

    cout << ans;
}