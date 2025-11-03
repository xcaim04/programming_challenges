#include<bits/stdc++.h>
using namespace std ;

#define int64 long long
#define all(x) x.begin(), x.end()
#define f first
#define s second
#define MAX 2001

int n, c, dad[MAX], len[MAX];
vector<pair<int64, pair<int, int>> > v;
vector<pair<int, int> >w;

void init() {for(int i=1;i<=n;i++) dad[i] = i;}
int Find(int x) {return (dad[x]!=x) ? (dad[x] = Find(dad[x])) : x; }
void unite(int a, int b){dad[Find(a)] = Find(b);}
bool same(int a, int b){return Find(a)==Find(b);}

int cont = 0;
int kruskall(){
    sort(v.begin(), v.end());
    init();
    int a, b;
    int64 sum = 0;
    for(auto u: v){
        a = Find(u.s.f);
        b = Find(u.s.s);
        if(!same(a, b)){
            sum += u.f;
            unite(a, b);
            if(cont==0){
                cont = 2;
            } else cont ++;
        }
    }
    return sum;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>c;
    for(int i=0;i<n;i++){
        int x, y; cin>>x>>y;
        w.push_back({x, y});
    }

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(i!=j){
                int64 res = ((w[i].f-w[j].f)*(w[i].f-w[j].f))+((w[i].s-w[j].s)*(w[i].s-w[j].s));
                if(res >= c and c != 0) v.push_back({res, {i, j}});
            }
        }
    }
    int sol = kruskall();
    if(cont==n) cout<<sol;
    else cout<<-1;

}