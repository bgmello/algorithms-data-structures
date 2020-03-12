#include <stdio.h>

bool prime(long long int n){
for (long long int i=2;i*i<=n;i++){
        if (n%i==0){
            return false;
        }
    }
    return true;
}

int main()
{
    long long int p;
    scanf("%lld", &p);
    if (prime(p))printf("Prime\n");
    else printf("Composite");
    return 0;
}
