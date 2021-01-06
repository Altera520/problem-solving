#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int sum = 0;
    int n;
    vector<pair<int,int>> ls;
    priority_queue<int> pq;

    cin >> n;
    for(int i=0; i<n; i++){
        int dead, ramen;
        cin >> dead >> ramen;
        ls.push_back({dead, ramen});
    }

    sort(ls.begin(), ls.end());

    for(int i=0; i<n; i++){
        pq.push(-ls[i].second);

        // 데드라인이 전체 수행시간 미만이라면 보상의 수가 적은 것을 제외
        while(ls[i].first < pq.size()) pq.pop();
    }

    while(!pq.empty()){
        sum += -pq.top();
        pq.pop();
    }

    cout << sum;
}