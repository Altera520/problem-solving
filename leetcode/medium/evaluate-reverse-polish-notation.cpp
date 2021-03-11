class Solution {    
public:
    
    int add(int val1, int val2) {
        return val1 + val2;
    }

    int sub(int val1, int val2) {
        return val1 - val2;
    }

    int div(int val1, int val2) {
        return val1 / val2;
    }

    int mul(int val1, int val2) {
        return val1 * val2;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> digit;
        int ans = 0;
        
        for(string str : tokens) {
            
            if(str[0] - '0' >= 0 || str.length() >= 2) {
                int num = stoi(str);
                digit.push(num);
                continue;
            }
            
            int val1 = 0;
            int val2 = 0;
            int result = 0;
            
            if(!digit.empty()) {
                val2 = digit.top();
                digit.pop();    
            }
            if(!digit.empty()) {
                val1 = digit.top();
                digit.pop();    
            }
            
            if(str == "+") result = add(val1, val2);
            else if(str == "-") result = sub(val1, val2);
            else if(str == "*") result = mul(val1, val2);
            else if(str == "/") result = div(val1, val2);
            
            digit.push(result);
        }
        
        if(!digit.empty()) {
            ans = digit.top();  
        }
        return ans;
    }
};