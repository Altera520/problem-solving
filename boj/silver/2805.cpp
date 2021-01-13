#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, m, ed = 0, st = 0, ans = 0;
    vector<int> tree;

    cin >> n >> m;
    tree.resize(n);

    for(int i=0; i<n; i++){
        cin >> tree[i];
        ed = max(tree[i], ed);
    }

    while(st <= ed){
        int mid = (ed + st) / 2;
        long long sum = 0;

        for(int t : tree){
            sum = (long long)(sum + max(t - mid, 0));
        }

        if(sum >= m){
            ans = max(ans, mid);
            st = mid + 1;
        }
        else if(sum < m){
            ed = mid - 1;
        }
    }

    cout << ans;
}