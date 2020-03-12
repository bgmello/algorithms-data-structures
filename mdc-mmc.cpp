#include <stdio.h>

long long int mdc(long long int n, long long int m){
long long int r;
while(m){
    r=n%m;
    n=m;
    m=r;
}
return n;
}

long long int mmc(long long int n, long long int m){
return m*n/mdc(n,m);
}

int main()
{
long long int a,b;
scanf("%lld %lld", &a, &b);
printf("mdc = %lld\nmmc = %lld\n", mdc(a,b), mmc(a,b));
    return 0;
}
