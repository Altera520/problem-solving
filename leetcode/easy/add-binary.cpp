class Solution {
public:
    
    int convert(char ch) {
        return ch - '0';
    }
    
    string addBinary(string a, string b) {
        
        long len = abs((long)(a.length() - b.length()));
        string ans;
        int carry = 0;
        
        if(len > 0) {
            string temp(len, '0');    
            if(len + a.length() == b.length()) {
                a = temp + a;
            }
            else {
                b = temp + b;
            }
        }
        
        for(int i = a.length() - 1; i >= 0; i--) {
            int sum = carry + convert(a[i]) + convert(b[i]);
            int out = sum % 2;
            carry = sum / 2;
            ans.push_back(out + '0');
        }
        
        if(carry != 0) ans.push_back('1');
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};