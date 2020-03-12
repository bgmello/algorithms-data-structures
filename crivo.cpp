#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<bool> v;


vector<long long int> u;

void crivo(long long int n)
{
    for (long long int i=1; i<=n; i++)
    {
        v.push_back(true);
    }
    for (long long int i=2; i<=n; i++)
    {
        if (v[i]==true)
        {
            u.push_back(i);
            for (long long int j=2*i; j<=n; j+=i)
            {
                v[j]=false;
            }
        }
    }
}

int main()
{
    long long int n;
    scanf("%lld", &n);
    crivo(n);
    for (long long int i=0; i<u.end()-u.begin(); i++)
    {
        printf("%lld\n", u[i]);
    }
    return 0;
}
