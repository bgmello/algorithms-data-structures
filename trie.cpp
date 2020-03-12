#include <bits/stdc++.h>
using namespace std;

struct Node{
struct Node* filhos[26];
bool fim;
};
/*
Funcao que cria outro no com vetor de ponteiros filhos igual a null e fim igual a falso
*/
Node* getNode(){
Node* pNode=new Node;
pNode->fim=false;
for(int i=0;i<26;i++)
    pNode->filhos[i]=NULL;
return pNode;
}
void insere(Node *root,string key){
Node* ptr=root;// ponteiro que aponta para o comeco
for (int i=0;i<key.length();i++){
   int j=key[i]-'a';
    if(ptr->filhos[j]==NULL){//se o filho for nulo
        ptr->filhos[j]=getNode();//cria o ponteiro para o filho dele
    }
    ptr=ptr->filhos[j];//ponteiro vai para o filho
}
ptr->fim=true;//dizemos que e fim
}
bool procura(Node *root,string key){
Node *ptr=root;
for (int i=0;i<key.length();i++){
    int j=key[i]-'a';
    if(ptr->filhos[j]==NULL){// se ele nao tiver mais filhos e a string ainda nao tiver acabado
        return false;
    }
    ptr=ptr->filhos[j];//ponteiro vai para o filho
}
if(ptr!=NULL && ptr->fim==true)return true;//se o filho nao for nulo e for fim retorna verdadeiro
return false;
}
int main()
{
int n;
scanf("%d", &n);
Node* root=getNode();
for(int i=1;i<=n;i++){
    getchar();
    string s;
    cin >> s;
    insere(root,s);
}
int m;
scanf("%d", &m);
for (int i=1;i<=m;i++){
    getchar();
    string s;
    cin >> s;
    if(procura(root,s))printf("YES\n");
    else printf("NO\n");
}

    return 0;
}
