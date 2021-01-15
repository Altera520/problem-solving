#include <iostream> 
#include <string> 
#include <vector>

using namespace std;

int n;
bool is_end = false;
string digit = "";

bool is_possible(){
    if(digit.length() == 1) return true;

    int s1 = digit.length() - 1;
    int s2 = digit.length() - 2;
    int len = 1;

    while(s2 >= 0){
        if(digit.substr(s1, len) == digit.substr(s2, len)){
            return false;
        }
        s1--;
        s2 -= 2;
        len++;
    }

    return true;
}

bool dfs(){
    if(digit.length() == n) {
        cout << digit;
        return true;
    }

    for(int i=1; i<=3; i++) {
        digit.push_back(i + '0');
        if(is_possible() && dfs()) {
            return true;
        }
        digit.pop_back();
    }

    return false;
}

int main(){ 
    cin >> n;

    dfs();
}