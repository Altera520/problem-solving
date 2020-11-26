#include <iostream>
#include <vector>
#define LEN 100001
using namespace std;

int post_order[LEN];
int in_order[LEN]; 
int dic[LEN];

void div(
    int in_st, 
    int in_ed, 
    int post_st, 
    int post_ed
    ) {

    // end conclusion
    if(in_st > in_ed || post_st > post_ed) return;

    // tree root (post-order)
    int r = post_order[post_ed]; 

    // root location (in-order)
    int r_loc = dic[r];

    // division location (post-order)
    int d_loc = r_loc - in_st;

    cout << r << ' '; //print

    div(in_st, r_loc-1, post_st, post_st + d_loc - 1); //left
    div(r_loc+1, in_ed, post_st + d_loc, post_ed - 1); //right
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> in_order[i];
        dic[in_order[i]] = i;
    }
    for(int i=0; i<n; i++){
        cin >> post_order[i];
    }

    div(0, n-1, 0, n-1);

}