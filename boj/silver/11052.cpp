#include <iostream>
#define LEN 1001

using namespace std;

int main() {
    int d[LEN];
    int card[LEN];
    int n;

    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> card[i];
    }

    d[0] = 0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            d[i] = max(card[j] + d[i-j], d[i]);
        }
    }

    cout << d[n];
}