class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();

        //calculatin nse
        stack<int> st1;
        vector<int> nse(n);
        for(int i=n-1;i>=0;i--){
            while(!st1.empty() && heights[st1.top()]>=heights[i]){
                st1.pop();
            }
            if(st1.empty()) nse[i]=n;
            else nse[i]=st1.top();
            st1.push(i);
        }

        //calculating pse;
        stack<int> st2;
        vector<int> pse(n);
        for(int i=0;i<n;i++){
            while(!st2.empty() && heights[st2.top()]>=heights[i]){
                st2.pop();
            }
            if(st2.empty()) pse[i]=-1;
            else pse[i]=st2.top();
            st2.push(i);
        }
        
        vector<int> width(n);
        int area=0;
        for(int i=0;i<n;i++){
            //width is distance between next smaller and prev smaller for a set height
            width[i] = nse[i]-pse[i]-1; 
        }
        for(int i=0;i<n;i++){
            area = max(area,heights[i]*width[i]);
        }
        
        return area;
    }
};