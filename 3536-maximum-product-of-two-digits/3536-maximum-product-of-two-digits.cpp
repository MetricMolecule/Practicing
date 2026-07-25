class Solution {
public:
    int maxProduct(int n) {
        string s= to_string(n);
        vector<int> list;
        for(char c : s){
            int digit=c-'0';
            list.push_back(digit);
        }
        
        sort(list.begin(),list.end());
        int x=list.size();
        return list[x-1]*list[x-2];
    }
};