#include <cstdio>
#include <iostream>
#include <string>
#include <queue>
#include <deque>

using namespace std;
typedef pair < int, int > par;
#define INF 100000000
//arreglo de vectores de pares
vector < par > g[101];

int N, E, T, n_conecciones;
int distancia[101];

int dijkstra(int src ){
    //dijkstra
    priority_queue < par > cola;
    for( int i = 1; i <= N; i++ ) 
        distancia[i] = INF;

    cola.push( par(src, 0));
    distancia[src] =0;
    int from, to, t, cost;

    while( !cola.empty() ){
        from = cola.top().first;
        cost = cola.top().second;
        cola.pop();

        if( distancia[from] == cost && distancia[from] <= T)
        for( int i = 0; i < (int) g[from].size(); i++ ){
            to = g[from][i].first;//a donde va
            t = g[from][i].second;//
            if( distancia[from] + t < distancia[to]){
                distancia[to] = distancia[from] + t;
                cola.push(par(to, distancia[to]));
            }
        }
    }

    int ratitas = 0;
    for( int i = 1; i <= N; i++ )
        if( distancia[i] <= T )
            ratitas += 1;
    return ratitas;
}
int main(){

    int n_casos, from, to, t;
    scanf("%d", &n_casos);
    while(n_casos--){

        cin>>N>>E>>T;
        cin>>n_conecciones;

        for( int i = 0; i < n_conecciones; i++ ){
            cin>>from>>to>>t;
            scanf("%d %d %d", &from, &to, &t);
            g[to].push_back( par(from, t) );
        }

    cout<<dijkstra(E)<<endl;
    if(n_casos)
        puts("");
    for( int i = 1; i <= N; i++ )
        g[i].clear();
    }

	return 0;
}
