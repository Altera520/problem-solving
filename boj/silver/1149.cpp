#include <iostream>
#include <vector>
#define LEN 1001
#define MIN 1000*1000+1

using namespace std;

int main() {
    int arr[LEN][3] ={0};
    int val[LEN][3] ={0};
    int answer = MIN;

    int n;
    cin >> n;
    
    for(int i=1; i<=n; i++){
        for(int j=0; j<3; j++){
            cin >> arr[i][j];
        }
    }

    val[1][0] = arr[1][0]; //R
    val[1][1] = arr[1][1]; //G
    val[1][2] = arr[1][2]; //B

    for(int i=2; i<=n; i++){
        for(int j=0; j<3; j++){
            int tmp = MIN;
            for(int k=0; k<3; k++){
                if(j!=k && val[i-1][k] < tmp){
                    tmp = val[i-1][k];
                }
            }

            //d[i][0] = min(d[i-1][1], d[i-1][2]) + a[i][0]
            //d[i][1] = min(d[i-1][0], d[i-1][2]) + a[i][1]
            //d[i][2] = min(d[i-1][0], d[i-1][1]) + a[i][2]
            val[i][j] = arr[i][j] + tmp;
        }
    }

    for(int j=0; j<3; j++){
        answer = min(answer, val[n][j]);
    }

    cout << answer;
}