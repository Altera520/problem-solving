#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    
    stack<int> st;
    
    for(int i=0; i < prices.size(); i++){
        
        while(!st.empty() && prices[st.top()] > prices[i]){
            prices[st.top()] = i - st.top();
            st.pop();
        }
        
        st.push(i);
    }
    
    while(!st.empty()){
        prices[st.top()] = prices.size() - st.top() -1;
        st.pop();
    }
    
    return prices;
}