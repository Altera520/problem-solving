#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

/*
case
>> 1 5 2 10 -99 7 5


      | max_heap        | min_heap   |
      |-----------------|------------|
(0,0) |             [1] |            |
(1,0) |             [1] | [5]        |
(1,1) |          [1][2] | [5]        |
(2,1) |          [1][2] | [5][10]    |
(2,2) |     [-99][1][2] | [5][10]    |
(3,2) |     [-99][1][2] | [5][7][10] |
(3,3) |  [-99][1][2][5] | [5][7][10] |

*/


int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);

    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int n, tmp;

    cin >> n;
    for(int i=1; i<=n; i++) {
        int left, right;
        cin >> tmp;

        //max heap크기는 min_heap과 같거나 1 더큼
        if(max_heap.size() > min_heap.size()){
            min_heap.push(tmp);
        }
        else{
            max_heap.push(tmp);
        }

        //max_heap의 top은 min_heap top보다 작거나 같음
        if(!max_heap.empty() && !min_heap.empty() && max_heap.top() > min_heap.top()){
            int max_top = max_heap.top();
            int min_top = min_heap.top();

            max_heap.pop();
            min_heap.pop();

            max_heap.push(min_top);
            min_heap.push(max_top);
        }

        cout << max_heap.top() << '\n';
    }
}