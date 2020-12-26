#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<pair<int, vector<pair<int,int>>>> album;

bool cmp(pair<int, vector<pair<int,int>>> &t, pair<int, vector<pair<int,int>>> &u){
    return t.first > u.first;
}

bool cmp_album(pair<int,int> &t, pair<int,int> &u){
    if(t.first == u.first){
        return t.second < u.second;
    }
    return t.first > u.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    album.resize(100);
    int pt = 0;
    
    unordered_map<string, int> dic;
    
    // 장르 이름별 해싱
    for(string title : genres){
        if(dic.find(title) == dic.end()){
            dic[title] = pt++;
        }
    }
    
    // 장르별 분류
    for(int i=0; i<plays.size(); i++){
        int index = dic[genres[i]];
        album[index].first += plays[i];
        album[index].second.push_back({plays[i], i});
    }
    
    // 장르별 정렬
    sort(album.begin(), album.end(), cmp);
    
    //앨범 수록
    for(pair<int, vector<pair<int, int>>> item : album){
        //장르내 정렬
        sort(item.second.begin(), item.second.end(), cmp_album);
        
        //수록
        int k = item.second.size();
        int size = min(2, k);
        for(int i=0; i < size; i++){
            answer.push_back(item.second[i].second);
        }
    }
    
    return answer;
}