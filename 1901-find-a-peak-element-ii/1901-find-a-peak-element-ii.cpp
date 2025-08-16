class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int left=-1;
        int right=-1;
        int low=0;
        int high = mat[0].size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            int maxrow=0;
            for(int i=0;i<mat.size();i++){
                if (mat[i][mid] > mat[maxrow][mid]) {
                maxrow = i;
            }
            }int left  = (mid - 1 >= 0) ? mat[maxrow][mid - 1] : -1;
            int right = (mid + 1 < (int)mat[0].size()) ? mat[maxrow][mid + 1] : -1;
            if(mat[maxrow][mid]> left && mat[maxrow][mid]>right){
                return {maxrow,mid};
            }else if(mat[maxrow][mid]< left && mat[maxrow][mid]>right){
                high=mid-1;
            }else low=mid+1;
        }return {-1,-1};
    }
};