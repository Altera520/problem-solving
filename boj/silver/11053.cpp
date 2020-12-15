#include <iostream>
#include <vector>
#define LEN 1001

using namespace std;

int main() {
    int n, ans = 0;
    int d[LEN];
    int ls[LEN];

    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> ls[i];
    }

    for(int i=n; i>=1; i--){
        d[i] = 1;
        for(int j=i+1; j<=n; j++){
            if(ls[i] < ls[j]){
                d[i] = max(d[i], d[j]+1);
            }
        }

        ans = max(ans, d[i]);
    }

    cout << ans;
}