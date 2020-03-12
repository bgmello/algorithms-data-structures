#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<long long int> u;

void fatore(long long int n)
{
    for (long long int i=2;i<=n;i++){
        while(n%i==0){
            n/=i;
            u.push_back(i);
        }
    }
}

int main()
{
    long long int n;
    scanf("%lld", &n);
    fatore(n);
    for (long long int i=0; i<u.end()-u.begin(); i++)
    {
        printf("%lld\n", u[i]);
    }
    return 0;
}
