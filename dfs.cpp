#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N=100000;
int vis[N]={};
vector<int> adj[N];
void dfs(int u){
if (vis[u])return;
vis[u]=1;
for (int i=0;i<adj[u].size();i++){
    dfs(adj[u][i]);
}
}

int main()
{
    int n,m,a,b,p,s;
    scanf("%d %d %d %d", &n, &m, &p, &s);
    for (int i=1;i<=m;i++){
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(p);
    if (vis[s]!=0)printf("ok");
    else printf("n");
    return 0;
}
