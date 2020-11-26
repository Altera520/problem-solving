#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct cmp{
    bool operator()(int target, int up){
        if(abs(target) == abs(up)) return target > up;
        else return abs(target) > abs(up);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<int, vector<int>, cmp> pq; //min-heap
    int n;
    cin >> n;

    while(n-- > 0){
        int tmp;
        cin >> tmp;

        if(tmp == 0){ // print and remove
            if(pq.empty()){
                cout << 0 << '\n';
            }
            else{
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else{ //insert
            pq.push(tmp);
        }
    }
}