#include <iostream>
#include <vector>
#define INF 1e9
#define LEN 101

using namespace std;

int map[LEN][LEN];

void init(int vertex, int edge){

    for(int i=1; i<=vertex; i++){
        for(int j=1; j<=vertex; j++){
            map[i][j] = INF;
            if(i==j){
                map[i][j] = 0; //자기 자신은 0
            }
        }
    }

    for(int i=1; i <= edge; i++){
        int from, to, cost;
        cin >> from >> to >> cost;
        map[from][to] = min(map[from][to], cost);
    }
}

//O(V^3)
void floyd_warshall(int vertex){
    for(int k=1; k<=vertex; k++){ //step
        for(int from=1; from <= vertex; from++){
            for(int to=1; to <= vertex; to++){

                // from -> to와 from -> k -> to 중 최소값 선택 점화식
                map[from][to] = min(map[from][to], map[from][k] + map[k][to]);
            }
        }
    }
}


int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int vertex, edge;
    cin >> vertex >> edge;

    init(vertex, edge);
    floyd_warshall(vertex);

    for(int i=1; i<=vertex; i++){
        for(int j=1; j<=vertex; j++){
            if(map[i][j] == INF){
                map[i][j] = 0;
            }
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
}