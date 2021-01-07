#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int x, int y) { 
    return x % y == 0 ? y : gcd(y, x % y); 
}

int main(){
    int n, g, ans = 0;
    vector<int> tree;
    vector<int> ls;

    cin >> n;
    while(n-- > 0){
        int tmp;
        cin >> tmp;
        tree.push_back(tmp);
    }

    // 정렬
    sort(tree.begin(), tree.end());

    // 현재 나무와 다음 나무의 위치 차이 계산
    for(int i=0; i < tree.size()-1; i++){
        int gap = tree[i+1] - tree[i];
        ls.push_back(gap);
    }

    // 최대공약수 도출
    g = ls[0];
    for(int i=0; i < ls.size()-1; i++){
        g = gcd(g, ls[i+1]);
    }

    // 필요한 나무수 산출
    for(int gap : ls){
        ans += gap / g - 1;
    }
    

    cout << ans;
}