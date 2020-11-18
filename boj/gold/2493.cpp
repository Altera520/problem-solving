#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int n;
    vector<int> tw;
    stack<pair<int,int>> st;
    cin >> n;
    tw.resize(n+1);

    for(int i=1; i<=n; i++){
        cin >> tw[i];
    }

    st.push({tw[n],n});
    for(int i=n-1; i>=1; i--){

        if(!st.empty() && st.top().first > tw[i]){
            st.push({tw[i],i});
        }
        else{
            while(!st.empty() && st.top().first <= tw[i]){
                tw[st.top().second] = i;
                st.pop();
            }
            st.push({tw[i],i});
        }
    }

    while(!st.empty()){
        tw[st.top().second] = 0;
        st.pop();
    }

    for(int i=1; i<=n; i++){
        cout << tw[i] << ' ';
    }
}