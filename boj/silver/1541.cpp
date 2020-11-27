#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    int loc = 0;
    int answer = 0;
    bool flag = false;

    cin >> str;
    str += '-';

    for(int i=0; i<str.length(); i++){
        if(str[i] == '-' || str[i] == '+'){
            int tmp = stoi(str.substr(loc, i-loc));
            loc = i+1;

            if(flag){
                answer -= tmp;
            }
            else{
                if(str[i] == '-') flag = true;
                answer += tmp;
            }
        }
    }

    cout << answer;
}