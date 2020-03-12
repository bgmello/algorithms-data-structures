#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;
const int inf=1000000;
const int N=1010;
vector<int> adj[N],adjw[N];
int dist[N],vis[N];
int n;
void bellman_ford(int s){
for (int i=0;i<=n;i++)dist[i]=inf;
dist[s]=0;
for (int i=1;i<=n;i++){
    for (int j=1;j<=n;j++){
        for (int r=0;r<adj[j].size();r++){
            dist[j]=min(dist[j],dist[adj[j][r]]+adjw[j][r]);
        }
    }
}
}

int main()
{
        int m;
        scanf("%d %d", &n, &m);
        for (int j=1;j<=m;j++){
                int a,b,c;
        scanf("%d %d %d", &a, &b, &c);
            adj[a].push_back(b);
            adj[b].push_back(a);
            adjw[a].push_back(c);
            adjw[b].push_back(c);
        }
        int x,y;
        scanf("%d %d", &x, &y);
        bellman_ford(x);
        if(dist[y]!=inf)
        printf("%d\n", dist[y]);
        else printf("NO\n");
    

    return 0;
}
