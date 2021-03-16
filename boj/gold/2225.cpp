#include <iostream>
#include <vector>
#define MOD 1e9
#define LEN 201

using namespace std;

int d[LEN][LEN];

//nPr
int permutaion(int n, int r) {
    if(d[n][r] != 0) {
        return d[n][r];
    }

    for(int i = 0; i <= n; i++) {
        int surplus = n - i;
        if(surplus < 0) {
            continue;
        }

        d[n][r] = (d[n][r] + permutaion(surplus, r - 1)) % (int)MOD;
    }

    return d[n][r];
}

int main() {
    int n, k;
    cin >> n >> k;

    for(int i = 0; i <= n; i++) {
        d[i][1] = 1;
    }

    cout << permutaion(n, k);
}