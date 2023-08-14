#include<bits/stdc++.h>
using namespace std;

// DP table
// ROWS=s
// COLS=p

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.length();
        int m=p.length();
        int **dp=new int*[m+1];
        for(int i=0;i<=m;i++){
            dp[i]=new int[n+1]{};
        }
        
        // first fill last row
        dp[m][n]=1; //all others 0
        
        // the fill last col
        for(int i=m-1;i>=0;i--){
            if(p[i]=='*'){
                dp[i][n]=dp[i+1][n];
            }
            // all others 0
        }

        // fill rest from bottom right to left
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(p[i]=='*'){
                    dp[i][j]=dp[i+1][j]||dp[i][j+1];
                }else if(p[i]=='?'){
                    dp[i][j]=dp[i+1][j+1];
                }else{
                    if(p[i]==s[j]){
                        dp[i][j]=dp[i+1][j+1];
                    }
                    // else 0
                }
            }
        }

        return dp[0][0];
    }
};