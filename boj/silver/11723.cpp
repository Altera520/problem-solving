#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

typedef void (*CmdFunction)(void); // function pointer type
unordered_map<string, CmdFunction> commands;
int set;

int input(){
    int value;
    cin >> value;
    return value;
}

void add(){
    set = set | (1 << input());
}

void remove(){
    set = set & ~(1 << input());
}

void check(){
    int res = (set & (1 << input())) > 0 ? 1 : 0;
    cout << res << '\n';
}

void toggle(){
    set = set ^ (1 << input());
}

void all(){
    set = ~(set & 0);
}

void empty(){
    set = set & 0;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int m;
    commands["add"] = add;
    commands["remove"] = remove;
    commands["check"] = check;
    commands["toggle"] = toggle;
    commands["all"] = all;
    commands["empty"] = empty;

    cin >> m;

    while(m-- > 0){
        string cmd;
        cin >> cmd;
        commands[cmd]();
    }
}