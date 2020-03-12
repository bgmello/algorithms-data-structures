#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<long long int> u;

void divisores(long long int n)
{
    for (long long int i=1;i<=n;i++){
        if(n%i==0){
            u.push_back(i);
        }
    }
}

int main()
{
    long long int n;
    scanf("%lld", &n);
    divisores(n);
    for (long long int i=0; i<u.end()-u.begin(); i++)
    {
        printf("%lld\n", u[i]);
    }
    printf("Quantidade=%lld\n", u.size());
    return 0;
}