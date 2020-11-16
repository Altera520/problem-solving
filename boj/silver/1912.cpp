#include <iostream>
#include <vector>
#define MIN -1001
using namespace std;

int main() {
    int n, answer = MIN;
    vector<int> v;
    v.push_back(MIN);

    cin >> n;

    //bottom-up
    // a(n) = max{a(n-1) + c(i), c(i)}
    for(int i=1; i<=n; i++) {
        int tmp;
        cin >> tmp;

        v.push_back(max(tmp + v[i-1], tmp));
        if(answer < v[i]){
            answer = v[i];
        }
    }

    cout << answer;
}