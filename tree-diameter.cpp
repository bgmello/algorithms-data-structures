#include <iostream>
#include <bits/stdc++.h>

using namespace std;
const int N=100000;
int vis[N];
queue<int> q;
vector<int> adj[N];
void bfs(int x){
q.push(x);
vis[x]=1;
while(!q.empty()){
    int u=q.front();
    q.pop();
    for (int v:adj[u]){
        if (!vis[v]){

            vis[v]=vis[u]+1;
            q.push(v);
        }
    }
}
}

int main(){
int n,a,b,maior=0;
scanf("%d", &n);
for (int i=1;i<n;i++){
    scanf("%d %d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
}
bfs(1);
int t;
for (int i=1;i<=n;i++){
    if (vis[i]>maior){maior=vis[i];t=i;}
}
maior=0;
for (int i=1;i<=n;i++)vis[i]=0;
bfs(t);
for (int i=1;i<=n;i++){
    if (vis[i]>maior)maior=vis[i];
}
printf("%d\n", maior-1);
return 0;
}
