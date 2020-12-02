#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, s = 0, e = 0, sum = 0;
    int answer = 0;
    vector<int> seq;
    cin >> n >> m;

    seq.resize(n);
    for(int i=0; i<n; i++){
        cin >> seq[i];
    }

    //always [s <= e], O(n)
    while(true){
        if(sum >= m){
            sum -= seq[s++];
        }
        else if(e==n){
            break;
        }
        else{
            sum += seq[e++];
        }

        if(sum == m) answer++;
    }

    cout << answer;
}