class Solution {
public:
    int find(int node, vector<int>& parent){
        if(parent[node]==node) return node;
        else return parent[node]=find(parent[node],parent);
    }
    void onion(int u, int v, vector<int>& parent){
        int x= find(u, parent);
        int y= find(v, parent);
        if(x!=y){
            parent[y]=x;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string,int> owners;
        vector<int> parent(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        // DSU
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(owners.find(accounts[i][j]) == owners.end()){
                    owners[accounts[i][j]]=i;
                }
                else{
                    onion(i, owners[accounts[i][j]], parent);
                }
            }
        }
        // reconstruction to make leaderwise;
        map<int, set<string>> groups;
        for(int i=0;i<n;i++){
            int leader = find(i,parent);
            for(int j=1;j<accounts[i].size();j++){
                groups[leader].insert(accounts[i][j]);
            }
        }
        // building the answer vector
        vector<vector<string>> ans;
        for(auto it : groups){
            int leader=it.first;
            // account vector for every account
            vector<string> account;
            account.push_back(accounts[leader][0]);
            for(auto email : it.second){
                account.push_back(email);
            }
            ans.push_back(account);
        }
        return ans;
    }
};