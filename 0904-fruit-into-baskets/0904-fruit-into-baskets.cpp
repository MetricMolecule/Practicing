class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i=0;
        int j=0;
        int n=fruits.size();
        int maxlen=0;
        unordered_map<int,int> mpp;
        while(j<n){
            mpp[fruits[j]]++;
            while(mpp.size()>2){
                mpp[fruits[i]]--;
                if(mpp[fruits[i]]==0){
                    mpp.erase(fruits[i]);
                }
                i++;
            }
            j++;
            maxlen=max(maxlen,j-i);
        }
        return maxlen;
    }
};