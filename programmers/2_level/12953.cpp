#include <string>
#include <vector>

using namespace std;

int gcd(int x, int y) { return x % y == 0 ? y : gcd(y, x % y); }

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int solution(vector<int> arr) {
    int answer = arr[0];
    
    for(int n : arr){
        answer = lcm(answer, n);
    }
    
    return answer;
}