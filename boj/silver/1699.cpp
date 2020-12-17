#include <iostream>
#define LEN 100001
#define INF 1e9

using namespace std;

int main() {
    int d[LEN];
    int n;

    cin >> n;

    d[1] = 1;
    d[2] = 2;
    for(int i=3; i<=n; i++){
        d[i] = INF;
        for(int j=1; j*j <= i; j++){
            /*
            j=1, j ~ i, d(i) = d(j) + d(i-j) 는 시간초과 발생

            j=1, j*j ~ i d(i) = min(d(i, d(i-j*j) + d(j*j)))로 압축
            */
            d[i] = min(d[i], d[i-j*j]+1);
        }
    }

    cout << d[n];
}