#include <iostream>
#include <vector>
#define LEN 12

using namespace std;

int n;
int ans_max = -(1e9 + 1), ans_min = 1e9 + 1;
int digit[LEN] = {0};
int op_table[4]; //+, -, /, *
vector<int> stmt;

int calc(){
    int pt = 0;
    int val = digit[0];

    while(pt < stmt.size()){
        if(stmt[pt] == 0) val += digit[pt + 1];
        else if(stmt[pt] == 1) val -= digit[pt + 1];
        else if(stmt[pt] == 2) val *= digit[pt + 1];
        else val /= digit[pt + 1];
        pt++;
    }

    return val;
}

void make_stmt(int loc){
    if(loc == n) {
        int val = calc();
        ans_max = max(ans_max, val);
        ans_min = min(ans_min, val);
        return;
    }

    for(int k = 0; k < 4; k++) {
        if(op_table[k] == 0) continue;

        op_table[k]--;
        stmt.push_back(k);

        make_stmt(loc + 1);

        op_table[k]++;
        stmt.pop_back();
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> digit[i];
    }
    for(int i = 0; i < 4; i++){
        cin >> op_table[i];
    }

    make_stmt(1);

    cout << ans_max << endl;
    cout << ans_min;
}