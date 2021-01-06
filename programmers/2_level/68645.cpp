#include <string>
#include <vector>
#define LEN 1001

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    int triangle[LEN][LEN] = {0};
    int dx[] = {0, 1, -1};
    int dy[] = {1, 0, -1};
    int dir = 0, x = 1, y = 0, cnt = 1;
    
    for(int i=n; i>0; i--){
        for(int j=i; j>0; j--){
            y = y + dy[dir];
            x = x + dx[dir];
            
            triangle[y][x] = cnt++;
            
        }
        dir = (dir + 1) % 3;
    }
    
    for(int i=1; i<=n; i++){    
        for(int j=1; j<=i; j++){
            answer.push_back(triangle[i][j]);
        }
    }
    
    return answer;
}