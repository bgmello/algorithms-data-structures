#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

const int N=1e5+5;
int v[N],aux[N];
int n;
void merge_sort(int ini,int fim)
{
    if (ini==fim)
        return;
    int tam=0;
    int i,j=(ini+fim)/2+1;
    merge_sort(ini,(ini+fim)/2);
    merge_sort((ini+fim)/2+1,fim);
    for (i=ini; i<=(ini+fim)/2; i++)
    {
        while(j<=fim && v[j]<v[i])
        {
            aux[tam]=v[j];
            tam++;
            j++;
        }
        aux[tam]=v[i];
        tam++;
    }
    while(j<=fim)
    {
        aux[tam]=v[j];
        tam++;
        j++;
    }
    for (i=ini; i<=fim; i++)
        v[i]=aux[i-ini];
}



int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &v[i]);
    }
    merge_sort(1,n);
    for (int i=1; i<=n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
    return 0;
}
