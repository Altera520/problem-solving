#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string a, const string b){
    return a.length() < b.length();
}

bool solution(vector<string> phone_book) {
    
    sort(phone_book.begin(), phone_book.end(), cmp);
    
    for(int i=0; i< phone_book.size(); i++){
        int sz = phone_book[i].length();
        
        for(int j=i+1; j<phone_book.size(); j++){
            if(phone_book[j].substr(0,sz) == phone_book[i]) return false;
        }
    }
    
    return true;
}