#include <iostream> 
#include <string> 
#include <vector>
#include <cstdio>

using namespace std; 

vector<int> init(string pattern) { 
    int m = pattern.size();
    int j = 0; 
    vector<int> table(m, 0); 

    for(int i = 1; i < m ; i++) { 
        while(j > 0 && pattern[i] != pattern[j]) {
            j = table[j-1]; 
        }
        if(pattern[i] == pattern[j]) {
            j++;
            table[i] = j; 
        }
    } 

    return table;
} 

vector<int> kmp(string str, string pattern) { 
    vector<int> ans;
    vector<int> table = init(pattern);
    int n = str.size();
    int m = pattern.size(); 
    int j = 0;

    for(int i = 0 ; i < n ; i++){ 
        while(j > 0 && str[i] != pattern[j]) {
            j = table[j-1];  
        }
        if(str[i] == pattern[j]) {  
            if(j == m - 1){                 
                ans.push_back(i - m + 1); 
                j = table[j]; 
            } else { 
                j++;
            } 
        } 
    }
    
    return ans; 
} 

int main(){ 
    string str, pattern; 
    getline(cin, str);
    getline(cin, pattern);

    vector<int> matched = kmp(str, pattern); 

    cout << matched.size() << '\n';

    for(int pos : matched) {
        cout << (pos + 1) << ' ';
    }
}