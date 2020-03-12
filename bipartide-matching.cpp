#include <bits/stdc++.h>

using namespace std;
const int N=2e5+5;
vector<int> adj[N];
int b[N],vis[N];
int match(int u){
if(vis[u])return 0;
vis[u]=1;
for (int i=0;i<adj[u].size();i++){
       int v=adj[u][i];
    if(b[v]==0 || !match(v)){
        b[v]=u;
        return 1;
    }
}
return 0;
}
int main()
{
    int n,m,p;
    scanf("%d %d %d", &n, &m, &p);
    for (int i=1;i<=p;i++){
        int a,b;
        scanf("%d %d", &a, &b);
        adj[2*a-1].push_back(2*b);
        adj[2*b].push_back(2*a-1);
    }
    int tot=0;
    for (int i=1;i<=2*n-1;i+=2){
        memset(vis,0,sizeof vis);
        tot+=match(i);
    }
    printf("%d\n", tot);
    return 0;
}
