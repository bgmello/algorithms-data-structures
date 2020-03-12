#include <bits/stdc++.h>

using namespace std;
const int N=1e5+5,LN=25;
typedef long long ll;
int st[N][LN];
int pa[N],h[N],n;
ll dist[N];
vector<int> adj[N],adjw[N];
void dfs(int u)
{
    for (int i=0; i<adj[u].size(); i++)
    {
        int v=adj[u][i];
        int w=adjw[u][i];
        if(v==pa[u])
            continue;
        if(h[v]==-1)
        {
            dist[v]=dist[u]+w;
            h[v]=h[u]+1;
            pa[v]=u;
            dfs(v);
        }
    }
}
void build_st()
{
    memset(st,-1,sizeof st);
    for (int i=1; i<=n; i++)
        st[i][0]=pa[i];
    for (int j=1; j<LN; j++)
    {
        for (int i=0; i<n; i++)
        {
            st[i][j]=st[st[i][j-1]][j-1];
        }
    }
}
int LCA(int u,int v)
{
    if(h[u]<h[v])
        swap(u,v);
    for (int i=LN-1; i>=0; i--)
    {
        if(h[u]-h[v]>=(1<<i))
            u=st[u][i];
    }
    if(u==v)
        return u;
    for (int i=LN-1; i>=0; i--)
    {
        if(st[u][i]!=-1 && st[u][i]!=st[v][i])
        {
            u=st[u][i];
            v=st[v][i];
        }
    }
    return st[u][0];
}
int main()
{
    while(scanf("%d", &n) && n!=0)
    {
        memset(h,-1,sizeof h);
        memset(pa,-1,sizeof pa);
        for (int i=0; i<n; i++)
            adj[i].clear(),adjw[i].clear();
        for (int i=1; i<n; i++)
        {
            int a,l;
            scanf("%d %d", &a, &l);
            adj[a].push_back(i);
            adj[i].push_back(a);
            adjw[a].push_back(l);
            adjw[i].push_back(l);
        }
        dfs(0);
        build_st();
        int q;
        scanf("%d", &q);
        for (int i=1; i<=q; i++)
        {
            int s,t;
            scanf("%d %d", &s, &t);
            printf("%lld ",dist[s]+dist[t]-2*dist[LCA(s,t)]);
        }
        printf("\n");
    }
    return 0;
}
