class Solution {
public:
    string smallestSubsequence(string s) {
        // storing last appearance of a character in the string in the map, so that we dont see duplicated
        unordered_map<char,int> last;
        for(int i=0;i<s.size();i++){
            last[s[i]]=i;
        }
        unordered_map<char,bool> visited;
        stack<char> st;
        
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(visited[c]==true) continue;
            // if we see a character greater than the current character of string,
            // we remove it from top and maintin monotonousity and mark as not visited
            while(!st.empty() && st.top()>c && last[st.top()]>i){
                visited[st.top()]=false;
                st.pop();
            }
            // we push an element and mark it as visited
            st.push(c);
            visited[c]=true;
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};