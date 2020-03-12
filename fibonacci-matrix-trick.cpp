#include <bits/stdc++.h>

using namespace std;

long long int a[2][2],c[2][2],m;

long long int exp(long long int m){
long long int ans=1;
for (long long int i=1;i<=m;i++)ans*=2;
return ans;
}

void multi(long long int a[2][2], long long int c[2][2]){
  long long int b[2][2];

   b[0][0] = ((a[0][0]*c[0][0]) + (a[0][1]*c[1][0]))%exp(m);
   b[0][1] = ((a[0][0]*c[0][1]) + (a[0][1]*c[1][1]))%exp(m);
   b[1][0] = ((a[1][0]*c[0][0]) + (a[1][1]*c[1][0]))%exp(m);
   b[1][1] = ((a[1][0]*c[1][0]) + (a[1][1]*c[1][1]))%exp(m);
   a[0][0] = b[0][0]%exp(m);
   a[0][1] = b[0][1]%exp(m);
   a[1][0] = b[1][0]%exp(m);
   a[1][1] = b[1][1]%exp(m);
}
long long int fibonacci(long long int n){
   if(n == 1){
      a[0][0] = 1;
      a[0][1] = 1;
      a[1][0] = 1;
      a[1][1] = 0;
   }

   c[0][0] = 1;
   c[0][1] = 1;
   c[1][0] = 1;
   c[1][1] = 0;


   if(n != 1){
      fibonacci (n / 2);
      if(n %2 == 1){
         multi(a, a);
         multi(a, c);
      }else{
         multi(a, a);
      }
   }
   return a[0][0]%exp(m);
}


int main(){


long long int n;

while(scanf("%lld %lld", &n, &m)!=EOF){
printf("%lld\n", fibonacci(n-1)%exp(m));}


return 0;}
