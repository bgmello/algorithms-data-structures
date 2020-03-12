#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N=100010,INFINITO=999999999;
vector<pii> vizinhos[N];
int processado[N]={};
int distancia[N];
int n;

void Dijkstra(int S){

	for(int i = 1;i <= n;i++) distancia[i] = INFINITO;
	distancia[S] = 0;

	priority_queue< pii, vector<pii>, greater<pii> > fila;
	fila.push( pii(distancia[S], S) );
	while(true){

		int davez = -1;
		int menor = INFINITO;

		while(!fila.empty()){

			int atual = fila.top().second;
			fila.pop();

			if(!processado[atual]){
				davez = atual;
				break;
			}

		}

		if(davez == -1) break;

		processado[davez] = true;

		for(int i = 0;i < (int)vizinhos[davez].size();i++){

			int dist  = vizinhos[davez][i].first;
			int atual = vizinhos[davez][i].second;

			if( distancia[atual] > distancia[davez] + dist ){
				distancia[atual] = distancia[davez] + dist;
				fila.push( pii(distancia[atual], atual) );
		}
	}

}}


int main()
{
    int k;
    scanf("%d %d", &n, &k);
    for (int i=1;i<=k;i++){
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);
        vizinhos[a].push_back(make_pair(c,b));
        vizinhos[b].push_back(make_pair(c,a));
    }
    int x,y;
    scanf("%d %d", &x, &y);
    Dijkstra(x);
    printf("%d\n", distancia[y]);

    return 0;
}
