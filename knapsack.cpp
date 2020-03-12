#include <iostream>

using namespace std;

const int N=100;
int w[N],v[N];
int dp[N][N];

int knapsack(int n,int t){
for (int i=1;i<=n;i++){
    for (int j=0;j<=t;j++){
        if (i==0){
            if(w[i]<=j)dp[i][j]=v[i];
            else dp[i][j]=0;
        }
        else {
            if(w[i]<=j)dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
            else dp[i][j]=dp[i-1][j];
        }
    }
}
return dp[n][t];
}

int main()
{
    
    return 0;
}

