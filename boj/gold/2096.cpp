#include <iostream>
#include <vector>
#define LEN 100001
#define MAX 0
#define MIN 1
#define INF 1e9

using namespace std;

int main() {
    int n;
    int arr[LEN][3];
    int d[2][3][2] = {0};
    int dx[] = {-1, 0, 1};
    pair<int, int> ans = {0, INF}; // max, min

    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < 3; i++) {
        d[1][i][MAX] = arr[n][i];
        d[1][i][MIN] = arr[n][i];
    }

    for(int i = n - 1; i > 0; i--) {
        for(int j = 0; j < 3; j++) {
            pair<int, int> tmp = {0, INF};

            for(int k = 0; k < 3; k++) {
                int nx = dx[k] + j;

                if(nx < 0 || nx > 2) {
                    continue;
                }

                tmp.first = max(tmp.first, d[1][nx][MAX]);
                tmp.second = min(tmp.second, d[1][nx][MIN]);
            }

            d[0][j][MAX] = tmp.first + arr[i][j];
            d[0][j][MIN] = tmp.second+ arr[i][j];
        }
        for(int j = 0; j < 3; j++) {
            d[1][j][MAX] = d[0][j][MAX];
            d[1][j][MIN] = d[0][j][MIN];
        }
    }

    for(int i = 0; i < 3; i++) {
        ans.first = max(d[1][i][MAX], ans.first);
        ans.second = min(d[1][i][MIN], ans.second);
    }

    cout << ans.first << ' ' << ans.second;
}