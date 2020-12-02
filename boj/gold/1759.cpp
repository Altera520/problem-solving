#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check[15] = {false};
vector<string> result;
vector<char> dataset;
string collection = "aeiou";

void permutation(int c, int l, vector<char> &temp){

    if(l==0){
        string str = "";
        int cnt = 0;
        for(char ch : temp){
            int idx = collection.find(ch);
            if(idx >= 0 && idx < 5){
                cnt++;
            }
            str += ch;
        }

        if(cnt >=1 && temp.size()-cnt >= 2){
            result.push_back(str);
        }
    }

    for(int i=0; i<c; i++){

        if(!check[i]){
            if(temp.size()>0 && temp[temp.size()-1] >= dataset[i]) continue;

            temp.push_back(dataset[i]);
            check[i] = true;

            permutation(c, l-1, temp);

            temp.pop_back();
            check[i] = false;
        }
    }
}

int main() {
    int l, c;
    vector<char> temp;
    cin >> l >> c;

    for(int i=0; i<c; i++){
        char temp;
        cin >> temp;
        dataset.push_back(temp);
    }

    permutation(c,l,temp);

    sort(result.begin(), result.end());

    for(auto str : result){
        cout << str << endl;
    }
}