#include <cstring>

class Solution {
public:
    stack<char> st;
    string pairs[3] = {"()", "[]", "{}"};
    string prefix = "([{";
    
    bool isPair(char p, char q) {
        string temp;
        temp.push_back(p);
        temp.push_back(q);
        
        for(string pair : pairs) {
            if(pair == temp) return true;
        }
        
        return false;
    }
    
    bool isValid(string s) {
        bool ans = true;
        
        for(char ch : s) {
            if(prefix.find(ch) != -1) {
                st.push(ch);
                continue;
            }
            
            char top = st.empty() ? ' ' : st.top();
             
            if(isPair(top, ch)) {
                st.pop();
            }
            else {
                break;
            }
        }
        
        if(!st.empty()) {
            ans = false;
        }
        
        return ans;
    }
};