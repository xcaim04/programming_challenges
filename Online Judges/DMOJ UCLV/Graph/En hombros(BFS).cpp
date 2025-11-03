#include<bits/stdc++.h>
using namespace std ;

#define MAX 1000000

int n, m, b, e, p;
vector<int> v[MAX];

/*Declaraciones*/
int dist[MAX], dist2[MAX], dist3[MAX];
bool mark[MAX], mark2[MAX], mark3[MAX];
/*Declaraciones*/

void bfs(int node){
    queue<int>q;
    q.push(node);
    dist[node]=0;
    while(not q.empty()){
        int ac=q.front();
        q.pop();
        if(mark[ac])continue;
        mark[ac]=1;
        for(auto u: v[ac]){
            if(not mark[u]){
                if(dist[u]!=0){
                    dist[u]=min(dist[u],dist[ac]+b);
                    q.push(u);
                }
                else{
                    dist[u]=dist[ac]+b;
                    q.push(u);
                }
            }
        }
    }
}
void bfs2(int node){
    queue<int>q;
    q.push(node);
    dist2[node]=0;
    while(not q.empty()){
        int ac=q.front();
        q.pop();
        if(mark2[ac])continue;
        mark2[ac]=1;
        for(auto u: v[ac]){
            if(not mark2[u]){
                if(dist2[u]!=0){
                    dist2[u]=min(dist2[u],dist2[ac]+e);
                    q.push(u);
                }
                else{
                    dist2[u]=dist2[ac]+e;
                    q.push(u);
                }
            }
        }
    }
}
void bfs3(int node){
    queue<int>q;
    q.push(node);
    dist3[node]=0;
    while(not q.empty()){
        int ac=q.front();
        q.pop();
        if(mark3[ac])continue;
        mark3[ac]=1;
        for(auto u: v[ac]){
            if(not mark3[u]){
                if(dist3[u]!=0){
                    dist3[u]=min(dist3[u],dist3[ac]+p);
                    q.push(u);
                }
                else{
                    dist3[u]=dist3[ac]+p;
                    q.push(u);
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>b>>e>>p>>n>>m;
    for(int i=1;i<=m;i++){
        int a, b; cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    ///Tres bfs, uno para la de bessie, otro para la otra vaca, y otro para saber la distancia desde n hasta los demas campos vecinos
    bfs(1);
    bfs2(2);
    bfs3(n);
    //cout<<dist[n]<<" "<<dist2[n]<<" "<<dist3[n];
    int aux=1<<30;
    for(int i=1;i<=n;i++){
        aux=min(aux,min(dist[n]+dist2[n],dist[i]+dist2[i]+dist3[i])); ///Me tengo que quedar con el minimo
    }
    cout<<aux;
}

