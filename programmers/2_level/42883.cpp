#include <string>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int st = 0;
    int ed = number.length() - k;
    
    for(int i = 0; i < ed; i++) {
        char max = '0';
        int max_index = st;
        
        for(int j = st; j <= number.length() - ed + i; j++) {
            char temp = number[j];
            if(temp > max) {
                max = temp;
                max_index = j;
            }
        }   
        
        answer += max;
        st = max_index + 1;
    }
    
    return answer;
}