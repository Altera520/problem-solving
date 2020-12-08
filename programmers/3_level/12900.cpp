#include <string>
#include <vector>
#define LEN 600001
#define MOD 1000000007

using namespace std;

int solution(int n) {
    int d[LEN];
    d[1] = 1;
    d[2] = 2;

    for(int i=3; i<=n; i++){
        d[i] = (d[i-1] + d[i-2]) % MOD;
    }

    return d[n];
}