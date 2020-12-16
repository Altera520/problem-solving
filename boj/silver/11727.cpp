#include <iostream>
#define LEN 1001
#define MOD 10007

using namespace std;

int main() {
    int d[LEN];
    int n;

    cin >> n;
    d[1] = 1;
    d[2] = 3;

    for(int i=3; i<=n; i++){
        d[i] = (d[i-1] + d[i-2]*2) % MOD;
    }

    cout << d[n];
}