class Solution {
public:

    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n=board.size();
        const int mod=1e9+7;
        vector<char> numlist={'1','2','3','4','5','6','7','8','9'};
        // dp states -> i,j,sum,count of sum
        vector<vector<int>> d1(n,vector<int>(n,-1));
        vector<vector<int>> d2(n, vector<int>(n,0));
        d1[n-1][n-1]=0;
        d2[n-1][n-1]=1;
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(board[i][j]=='X') continue;

                if(i == n-1 && j == n-1) continue;

                int best=-1;
                long long count=0;
                if(i+1<n && d1[i+1][j]!=-1){
                    if(d1[i+1][j]>best){
                        best=d1[i+1][j];
                        count=d2[i+1][j];
                    }else if(d1[i+1][j]==best){
                        count= (count+d2[i+1][j])%mod;
                    }
                }
                if(j+1<n && d1[i][j+1]!=-1){
                    if(d1[i][j+1]>best){
                        best=d1[i][j+1];
                        count=d2[i][j+1];
                    }else if(d1[i][j+1]==best){
                        count= (count+d2[i][j+1])%mod;
                    }
                }
                if(i+1<n && j+1<n && d1[i+1][j+1]!=-1){
                    if(d1[i+1][j+1]>best){
                        best=d1[i+1][j+1];
                        count=d2[i+1][j+1];
                    }else if(d1[i+1][j+1]==best){
                        count= (count+d2[i+1][j+1])%mod;
                    }
                }
                if(best==-1) continue;
                int val=0;
                if(board[i][j] != 'E' && board[i][j] != 'S')
                    val = board[i][j] - '0';

                d1[i][j] = best + val;
                d2[i][j] = count % mod;
            }
        }
        if(d1[0][0]==-1) return {0,0};
        return {d1[0][0],d2[0][0]};
    }
};