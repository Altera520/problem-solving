#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    vector<int> v, dp;

    cin >> n;
    v.resize(n);
    dp.resize(n);

    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    dp[0] = v[0];
    if(n>1){
        dp[1] = max(v[1], v[1] + v[0]);
    } 
    if(n>2){
        dp[2] = v[2] + max(v[0], v[1]);
        dp[2] = max(dp[2], dp[1]);
    }

    for(int i=3; i<n; i++){
        //첫번째 점화식
        dp[i] = v[i] + max(dp[i-2], v[i-1] + dp[i-3]);

        //두번째 점화식(포도주를 두번 연속 안먹을 경우)
        dp[i] = max(dp[i], dp[i-1]);
    }

    cout << dp[n-1];
}