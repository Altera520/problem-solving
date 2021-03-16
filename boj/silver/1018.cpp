#include <iostream>
#include <vector>
#include <cmath>
#define INF 1e9

using namespace std;

vector<string> arr;
char pattern[] = {'B', 'W'};
int n, m, ans = INF;

int calc(int idx, int x, int y){
    int result = 0;

    for(int i = y; i < y + 8; i++) {
        int temp = idx;
        for(int j = x; j < x + 8; j++) {
            if(arr[i][j] != pattern[temp]) {
                result++;
            }
            temp = abs(temp - 1);
        }    
        idx = abs(idx - 1);
    }

    return result;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        arr.push_back(temp);
    }

    for(int y = 0; y <= n - 8; y++) {
        for(int x = 0; x <= m - 8; x++) {
            int temp = min(calc(0, x, y), calc(1, x, y));
            ans = min(ans, temp);
        }
    }
    cout << ans;
}