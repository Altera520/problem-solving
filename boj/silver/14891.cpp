#include <iostream>
#include <vector>

#define LEFT 6
#define RIGHT 2
#define FORWARD 1
#define REVERSE -1
#define N 0
#define S 1
#define COUNT 8

using namespace std;

vector<string> wheel;


void move(int index, int position) {
    if (position == FORWARD) {
        wheel[index] = wheel[index].substr(7, 1) + wheel[index].substr(0, 7);
    } else {
        wheel[index] = wheel[index].substr(1, 7) + wheel[index].substr(0, 1);
    }
}

void spin(int cur, int pos, int dir) {
    int r = cur + 1;
    int l = cur - 1;

    if(dir != RIGHT && r <= 4) {
        if(wheel[r][LEFT] != wheel[cur][RIGHT]) {
            spin(r, pos * -1, LEFT);
        }
    }
    if(dir != LEFT && l >= 1) {
        if(wheel[l][RIGHT] != wheel[cur][LEFT]) {
            spin(l, pos * -1, RIGHT);
        }
    }

    move(cur, pos);
}

int main() {
    int count, ans = 0, mul = 1;
    wheel.resize(5);
    
    for(int i = 1; i <= 4; i++) {
        cin >> wheel[i];
    }
    cin >> count;

    // operation
    while(count-- > 0) {
        int index, position;
        cin >> index >> position;

        spin(index, position, 0);
    }

    // calc
    for(int i = 1; i <= 4; i++) {
        ans += (wheel[i][0] - '0') * mul;
        mul *= 2;
    }

    cout << ans;

}