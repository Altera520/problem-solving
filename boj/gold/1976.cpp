#include <iostream>
#include <vector>
#define LEN 201
#define INF 1e9

using namespace std;

int map[LEN][LEN];

void floyd_warshall(int n){
    for(int k=1; k<=n; k++){
        for(int from=1; from<=n; from++){
            for(int to=1; to<=n; to++){
                map[from][to] = min(map[from][to], map[from][k] + map[k][to]);
            }
        }
    }
}

int main() {
    int n, m, from;
    string ans = "YES";
    vector<int> path;
    cin >> n >> m;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> map[i][j];
            if(i != j && map[i][j] == 0){
                map[i][j] = INF;
            }
        }
    }

    for(int i=1; i<=m; i++){
        int node;
        cin >> node;
        path.push_back(node);
    }

    floyd_warshall(n);

    from = path[0];
    for(int i = 1; i < m; i++){
        int to = path[i];
        if(map[from][to] == INF){
            ans = "NO";
            break;
        }
        from = to;
    }

    cout << ans;
}