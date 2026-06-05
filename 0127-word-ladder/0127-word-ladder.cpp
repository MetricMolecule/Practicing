class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        q.push({beginWord,1});
        // set needed to check the alteration of a letter we do on beginWord is in wordList
        unordered_set<string> words(wordList.begin(),wordList.end());
        // BFS from start (beginWord)
        while(!q.empty()){
            pair<string,int> p = q.front();
            q.pop();
            string node = p.first;
            int len = p.second;
            if(node==endWord) return len;
            for(int i=0;i<node.size();i++){
                for(char ch='a';ch<='z';ch++){
                    char original=node[i];
                    node[i]=ch;
                    if(words.count(node)!=0){
                        q.push({node,len+1});
                        words.erase(node);
                    }
                    node[i]=original;
                }
            }
        }
        return 0;
    }
};