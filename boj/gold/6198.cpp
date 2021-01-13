#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){
    int n;
    long long ans = 0, sum = 0;
    stack<pair<int,int>> st;
    cin >> n;

    for(int i=1; i <= n; i++){
        int h;
        cin >> h;

        while(!st.empty() && st.top().first <= h){
            ans += i - st.top().second - 1;
            st.pop();
        }

        st.push({h, i}); //height, index
    }

    int i = st.top().second;
    while(!st.empty()){
        long long val = i - st.top().second;
        ans += val + sum;
        sum += val;
        i = st.top().second;
        st.pop();
    }

    cout << ans;
}