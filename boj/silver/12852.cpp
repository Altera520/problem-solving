#include <iostream>
#define LEN 1000001
#define INF 1e9;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int d[LEN] = {0};
    d[0] = 0;

    cin >> n;

    for(int i=1; i<=n; i++){
        int div2 =  i%2==0 ? d[i/2] : INF;
        int div3 =  i%3==0 ? d[i/3] : INF;
        d[i] = min(d[i-1], min(div2, div3)) + 1;
    }

    cout << d[n] - 1 << '\n';
    cout << n << ' ';
    for(int i=n; i!=1; ){
        int val = d[i]-1;
        int ret;

        if(d[i-1] == val){
            ret = i - 1;
            i -= 1;
        }
        else if(i%2==0 && d[i/2] == val){
            ret = i / 2;
            i /= 2;
        }
        else if(i%3==0 && d[i/3] == val){
            ret = i / 3;
            i /= 3;
        }
        cout << ret << ' ';
    }
}