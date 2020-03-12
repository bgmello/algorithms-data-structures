#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
const int N=100000;
int vis[N]={};
vector<int> adj[N];
queue<int> q;
void bfs(int x){
vis[x]=1;
q.push(x);
while(!q.empty()){
    x=q.front();
        q.pop();
    for (int i=0;i<adj[x].size();i++){
        if (vis[adj[x][i]]==0){
                vis[adj[x][i]]=vis[x]+1;
                q.push(adj[x][i]);
        }
    }
}
}

int main(){
int n,m,a,b;
scanf("%d %d", &n, &m);
for (int i=1;i<=m;i++){
    scanf("%d %d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
}
bfs(1);
for (int i=1;i<=n;i++){
    printf("%d = %d\n", i, vis[i]);
}

return 0;
}
