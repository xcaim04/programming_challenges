#include<bits/stdc++.h>
#define MAX 500010
using namespace std;

int n, m;
int ct = 0;
bool visited[MAX];
vector<int> v[MAX];

void dfs(int source){
   if(source == 0) return;
   if(visited[source]) return;
   visited[source] = true;

    for(auto u: v[source]){
        dfs(u);
    }
}

void clearVisited(){
    for(int i=1; i<=n; i++) visited[i] = false;
}


int main(){

    cin>>n>>m;

    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i=1; i<=n; i++){
        for(int j=0; j<v[i].size(); j++){
            int popped = v[i][j];
            v[i][j] = 0;
            clearVisited();
            dfs(1);

            v[i][j] = popped;

            for(int i=1; i<=n; i++){
                if(visited[i] == false){
                    ct++;
                    break;
                }
            }
        }
    }

    cout<<ct;
    
    return 0;
}
