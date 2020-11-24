#include <iostream>
#include <vector>
#define MOD_VAL 1000000000
using namespace std;


int main() {
    int n;
    long long answer = 0;
    vector<int> num = vector<int>(10,1);
    vector<int> temp = vector<int>(10,0);
    cin >> n;

    for(int i=2; i<=n; i++){
        for(int j=0; j<=9; j++){
            int low = j-1;
            int high = j+1;

            if(low==0){
                temp[0] = num[1];
            }

            if(low>=1){
                temp[low] = (temp[low] + num[j]) % MOD_VAL;
            }
            if(high<=9){
                temp[high] = (temp[high] + num[j]) % MOD_VAL;
            }
        }
        for(int j=0; j<=9; j++){
            num[j] = temp[j];
            temp[j] = 0;
        }
    }

    for(int i=1; i<=9; i++){
        answer = (answer + num[i]) % MOD_VAL;
    }

    cout << answer;
}