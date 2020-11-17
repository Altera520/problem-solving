#include <iostream>
#include <vector>
#define LEN 301

using namespace std;

int main() {
    int n;
    int stair[LEN];
    int d[LEN];
    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> stair[i];
    }

    d[1] = stair[1];
    d[2] = max(stair[2] + d[1], stair[2]);
    d[3] = max(stair[2] + stair[3], d[1] + stair[3]);

    for(int i=4; i<=n; i++){
        //d[i] = max(d[i-3] + stair[i-1] + stair[i], d[i-2] + stair[i])
        d[i] = max(d[i-3] + stair[i-1] + stair[i], d[i-2] + stair[i]);
    }

    cout << d[n];
}