#include <bits/stdc++.h>
using namespace std;

const int N=100010;

struct aresta{
int x,y,t;
};
int pai[N];
aresta mst[N],v[N];
bool f(aresta a, aresta b){return a.t < b.t;}
int find(int a){
if (a==pai[a])return a;
return pai[a]=find(pai[a]);
}

void unite(int a,int b){
    a=find(a);
    b=find(b);
pai[b]=a;
}

int main(){
int n,m,tam=1;
scanf("%d %d", &n, &m);
for (int i=1;i<=n;i++)pai[i]=i;
for (int i=1;i<=m;i++){
    cin >> v[i].x >> v[i].y >> v[i].t;
}
sort(v+1,v+m+1,f);

for (int i=1;i<=m;i++){
    if(find(v[i].x)!=find(v[i].y)){
        unite(v[i].x,v[i].y);
        mst[tam]=v[i];
        tam++;
    }
}
for (int i=1;i<n;i++){
cout << mst[i].x << " " << mst[i].y << " " << mst[i].t << endl;
}
}
