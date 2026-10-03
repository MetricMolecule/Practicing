class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // we take three pointers, i, j, k
        // i-> end of num1
        // j-> end of num2
        // k-> end of entire num1 (m+n-1)
        int i=m-1;
        int j=n-1;
        int k=m+n-1;
        // process nums2 array, if greater put at the k'th position, goal is to put the greatest element at k'th position then move it a way back and look for second greatest and so on...
        while(j>=0){
            if(i<0 || nums2[j]>nums1[i]){
                nums1[k]=nums2[j];
                j--;
            }else{
                nums1[k]=nums1[i];
                i--;
            }
            k--;
        }
    }
};