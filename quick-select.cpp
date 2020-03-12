#include <bits/stdc++.h>

using namespace std;
const int N=2e5+5;
int v[N];
void quickselect(int l,int r,int k){
    if(l>=r)return;
int p=l;
for (int i=l+1;i<=r;i++){
    if(v[i]<v[p]){
        swap(v[p],v[p+1]);
       if(i!=p+1)swap(v[p],v[i]);
        p++;
    }
}
if(k==p)return;
if(k>=l && k<=p-1)
quicksort(l,p-1,k);
else
quicksort(p+1,r,k);
}
int main()
{
    int n,k;
    cin >> n >> k;
    for (int i=1;i<=n;i++)cin >> v[i];
    random_shuffle(v+1,v+n+1);
    quickselect(1,n,k);
   cout << v[k] << endl;
    return 0;
}
