#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;

    for(int i=1; i<=n; i++){
        int tmp = n - i;
        int left = i - 1;
        int right = i + 1;

        if(tmp == 0 || tmp % (left + right) == 0) answer++;
    }


    return answer;
}