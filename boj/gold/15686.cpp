#include <iostream>
#include <vector>
#define INF 1e9

using namespace std;

vector<pair<int,int>> chicken;
vector<pair<int,int>> home;
vector<int> table;
int ans = INF;

int get_distance(){
    int c_dist = 0;

    for(pair<int,int> h : home){
        int hy = h.first;
        int hx = h.second;
        int dist = INF;

        for(int c : table){
            int cy = chicken[c].first;
            int cx = chicken[c].second;

            dist = min(abs(hy - cy) + abs(hx - cx), dist);
        }

        c_dist += dist;
    }

    return c_dist;
}

void comb(int n, int r, int index){ //nCr
    if(r == 0){
        ans = min(get_distance(), ans);
        return;
    }

    for(int i=index; i<n; i++){
        table.push_back(i);

        comb(n,r-1,i+1);

        table.pop_back();
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int tmp;
            cin >> tmp;
            if(tmp == 1) home.push_back({i,j}); //x,y
            else if(tmp == 2) chicken.push_back({i,j});
        }
    }

    comb(chicken.size(), m, 0);

    cout << ans;
}