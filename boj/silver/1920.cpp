#include <iostream>
#include <algorithm>
#include <vector>
#define T 1
#define F 0

using namespace std;

int main() {
    cin.tie(NULL);
	ios::sync_with_stdio(false);

    int n,m, st, ed, tmp;
    vector<int> v;

    cin >> n;
    while(n-- > 0){
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    cin >> m;
    while(m-- > 0){
        int res = F;
        st = 0;
        ed = v.size()-1;

        cin >> tmp;

        while(st <= ed){
            int mid = (st + ed)/2;

            if(v[mid]==tmp){
                res = T;
                break;
            }
            else if(v[mid] > tmp){
                ed = mid-1;
            }
            else if(v[mid] < tmp){
                st = mid +1;
            }
        }

        cout << res << '\n';
    }
}