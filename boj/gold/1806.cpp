#include <iostream>
#include <vector>
#define INF 1e9

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v;
    int n, s;
    long long sum = 0;
    int ans = INF, len = 0, st = 0, ed = 0;

    cin >> n >> s;
    v.resize(n);

    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    while (ed <= n) {

        if (sum >= s) { // 부분합이 s 이상인 경우 start 요소 감산, start 증가
            sum -= v[st++];
            len--;
        } else if (sum < s) { // 부분합이 s 미만인 경우 end 증가, end 요소 가산
            sum += v[ed++];
            len++;
        } 

        // find
        if (sum >= s) {
            ans = min(len, ans);
        }
    }

    if (ans == INF) {
        cout << 0;
    } else {
        cout << ans;
    }
}