#include <iostream>
#include <vector>
#define LEN 91

using namespace std;

int main() {
    long long d[LEN][2] = {0}; //1,0
    int n;

    cin >> n;

    d[1][1] = 1;
    d[2][0] = 1;

    for(int i=3; i<=n; i++){
        d[i][0] = d[i-1][0] + d[i-1][1];
        d[i][1] = d[i-1][0];
    }

    cout << d[n][0] + d[n][1];
}