#include <vector>
#include <unordered_map>
#include <iostream>
#define LEN 500001

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    unordered_map<int, int> map;
    map.reserve(LEN);
    int n;
    cin >> n;

    while(n-- > 0){
        int tmp;
        cin >> tmp;
        map[tmp]++;
    }

    cin >> n;
    while(n-- > 0){
        int tmp;
        cin >> tmp;
        cout << map[tmp] << ' ';
    }
}