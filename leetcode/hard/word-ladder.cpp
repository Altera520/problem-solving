class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<int>> dictionary;
        vector<vector<int>> map;
        queue<pair<int, int>> q; // node, level
        vector<bool> visit;
        int start, end = -1, ans = 0;
        
        wordList.push_back(beginWord);
        map.resize(wordList.size());
        visit.resize(wordList.size());
        
        // generate hash
        for(int i = 0; i < wordList.size(); i++) {
            if(wordList[i] == endWord) {
                end = i;
            }
            
            for(int j = 0; j < wordList[i].length(); j++) {
                string temp = wordList[i];
                temp.replace(j, 1, "*");
                
                if(dictionary.find(temp) == dictionary.end()) {
                    vector<int> v;
                    dictionary.insert({temp, v});
                }
                dictionary[temp].push_back(i);
            }
        }
        
        if(end == -1) {
            return ans;
        }
        
        // generate graph
        for(int i = 0; i < wordList.size(); i++) {
            
            for(int j = 0; j < wordList[i].length(); j++) {
                string temp = wordList[i];
                temp.replace(j, 1, "*");
                
                for(int node : dictionary[temp]) {
                    if(node == i) {
                        continue;
                    }
                    map[i].push_back(node);
                    map[node].push_back(i);
                }
            }
        }
        
        // bfs
        start = wordList.size() - 1;
        q.push({start, 1});
        visit[start] = true;
        
        while(!q.empty()) {
            pair<int ,int> current = q.front();
            q.pop();
            
            // is find ?
            if(current.first == end) {
                ans = current.second;
                break;
            }
            
            for(int next : map[current.first]) {
                if(visit[next]) {
                    continue;
                }
                
                q.push({next, current.second + 1});
                visit[next] = true;
            }
        }
        
        return ans;
    }
};