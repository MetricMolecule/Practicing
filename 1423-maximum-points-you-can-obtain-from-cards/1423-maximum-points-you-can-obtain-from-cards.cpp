class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum=0;
        for(int i=0;i<cardPoints.size();i++){
            sum+=cardPoints[i];
        }
        if(cardPoints.size()==k) return sum;
        
        int sum_f=0;
        int sum_b=0;
        for(int i=0;i<k;i++){
            sum_f+=cardPoints[i];
        } int ans=sum_f;
        for(int i=0;i<k;i++){
            sum_f= sum_f-cardPoints[k-i-1];
            sum_b= sum_b+cardPoints[cardPoints.size()-i-1];
            ans=max(ans,sum_f+sum_b);
        }return ans;
    }
};