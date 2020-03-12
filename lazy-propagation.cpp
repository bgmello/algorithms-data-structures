#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
typedef long long ll;
ll st[4*N],lz[4*N];
void update(int n,int l, int r, int i, int j, ll val){

if(lz[n]!=0){
    st[n]+=lz[n]*(r-l+1);
    if(l!=r){
        lz[2*n]+=lz[n];
        lz[2*n+1]+=lz[n];
    }
    lz[n]=0;
}
if(l>j || r<i || i>j)return;
if(i<=l && r<=j){
    st[n]+=val*(r-l+1);
    if(l!=r){
        lz[2*n]+=val;
        lz[2*n+1]+=val;
    }
    lz[n]=0;
}
else {
    update(2*n,l,(l+r)/2,i,j,val);
    update(2*n+1,(l+r)/2+1,r,i,j,val);
    st[n]=st[2*n]+st[2*n+1];
}
}
ll query(int n,int l, int r, int i, int j){
if(lz[n]!=0){
    st[n]+=lz[n]*(r-l+1);
    if(l!=r){
        lz[2*n]+=lz[n];
        lz[2*n+1]+=lz[n];
    }
    lz[n]=0;
}
if(j<l || r<i)return 0;
if(i<=l && r<=j)return st[n];
else {
    return query(2*n,l,(l+r)/2,i,j)+query(2*n+1,(l+r)/2+1,r,i,j);
}
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n,c;
        memset(lz,0,sizeof lz);
        memset(st,0,sizeof st);
        scanf("%d %d", &n, &c);
        for (int i=1;i<=c;i++){
            ll a,b,d;
            scanf("%lld %lld %lld", &d, &a, &b);
            if(d==1){
                printf("%lld\n", query(1,1,n,a,b));
            }
            else{
                    ll v;
                scanf("%lld", &v);
            update(1,1,n,a,b,v);
            }
        }
    }
return 0;
}
