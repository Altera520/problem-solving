#include <vector>
#include <iostream>
#define MUL 4
#define  PRINT 2

using namespace std;

vector<long long> tree;

long long init(int st, int ed, int node, vector<long long> &dataset){
    if(st == ed){
        return tree[node] = dataset[st];
    }

    int mid = (st + ed)/2;

    //합산 수행
    return tree[node] = init(st, mid, node * 2, dataset) + init(mid+1, ed, node * 2+1, dataset);
}

long long sum(int st, int ed, int node, int left, int right){

    //범위 밖에 있다면
    if(left > ed || st > right){
        return 0;
    }

    //범위 내에 있다면
    if(left <= st && ed <= right){
        return tree[node];
    }

    int mid = (st + ed)/2;

    //합산 수행
    return sum(st, mid, node * 2, left, right) + sum(mid+1, ed, node * 2+1, left, right);

}

void update(int st, int ed, int node, int idx, long long value){

    //범위 밖에 있다면
    if(idx > ed || st > idx){
        return;
    }

    tree[node] += value;

    if(st == ed){
        return;
    }

    int mid = (st+ed)/2;
    update(st, mid, node * 2, idx, value);
    update(mid+1, ed, node * 2 + 1, idx, value);
}


int main()
{
    vector<long long> dataset;
    int n, m, k, sz;
    cin >> n >> m >> k;

    sz = n;
    dataset.resize(sz+1);
    tree.resize(sz * MUL+1);

    for (int i = 1; i <= n; ++i) {
        cin >> dataset[i];
    }

    init(1, sz, 1, dataset);

    for (int i = 0; i < m+k; ++i) {
        int a, b;
        long long c;

        cin >> a >> b >> c;

        if(a==PRINT){
            cout << sum(1, sz, 1, b,c) << endl;
        }
        else{
            update(1, sz, 1, b, c - dataset[b]);
            dataset[b] = c;
        }
    }

}