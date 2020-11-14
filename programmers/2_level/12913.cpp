#include <iostream>
#include <vector>
#define MAX 100001

using namespace std;

int memo[MAX][4] = {0};
bool visit[MAX][4] = {false};
int sz = 0;

int get_score(vector<vector<int> > &land, int n, int m){
    if(n == sz-1){
        return land[n][m];
    }
    else if(visit[n][m]){
        return memo[n][m];
    }
    else{
        int score = 0;
        for(int i=0; i<4; i++){
            if(i==m){
                continue;
            }
            else{
                score = max(score, land[n][m] + get_score(land, n+1, i));
            }
        }
        
        visit[n][m] = true;
        memo[n][m] = score;
        return score;
    }
}

int solution(vector<vector<int> > land)
{
    int score = 0;
    sz = land.size();
    
    for(int i=0; i<4; i++){
        score = max(score, get_score(land, 0, i));
    }

    return score;
}