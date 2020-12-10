#include <iostream>
#include <vector>
#define MAX 16;
using namespace std;

int n, ans = 0;
vector<int> col;

//유망한 위치인가?
bool possible(int cur){
    for(int i=1; i < cur; i++){
        //수직 검사
        if(col[i] == col[cur]) return false;

        //대각 검사
        if(abs(cur - i) == abs(col[cur] - col[i])) return false;
    }
    return true;
}

void dfs(int row){
    if(row > n){
        ans++;
        return;
    }

    for(int i=1; i<=n; i++){
        col[row] = i;

        if(possible(row)){
            dfs(row + 1);
        }
        else{
            col[row] = 0;
        }
    }
}

int main() {
    cin >> n;
    col.resize(n+1);

    for(int i=1; i<=n; i++){
        col[1] = i; //1,i부터 시작
        dfs(2);
    }

    cout << ans;
}