#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>

using namespace std;
typedef vector<int> VI;
typedef pair<int, int> II;
typedef vector<vector<pair<int, int> > > VVP;
#define FOR( i, L, U ) for(int i=(int)L ; i<=(int)U ; i++ )
#define FORD( i, U, L ) for(int i=(int)U ; i>=(int)L ; i-- )
#define INF INT_MAX


int nodos, aristas;
VI dist;
priority_queue<II, vector<II>, greater<II> > pq;
VVP grafo;

void dijkstra(int src)
{
    dist = VI(nodos, INF);
    int a,b,c,d;
    dist[src] = 0;

    pq.push(II(0,src));

    while( !pq.empty() ) {
        a = pq.top().second;
        d = pq.top().first;
        pq.pop();
        if(d==dist[a])/* if true then update a now and other occurences of a in pq
                        at this moment never will be updated*/
            FOR(i, 0, grafo[a].size()-1) {

                b = grafo[a][i].first;
                c = grafo[a][i].second;
                if( dist[a] + c < dist[b] ) {
                    dist[b] = dist[a] + c;
                    pq.push(II(dist[b],b));
                }
            }
    }
}
int main()
{

    int st, en, w,n_casos, cs=1;
    int inicio, fin;
    scanf("%d", &n_casos);
    while(n_casos--){
        cin >> nodos >> aristas >> inicio >> fin;
        grafo = VVP(nodos);
        FOR(i, 1, aristas) {
            cin >> st >> en >> w;
            grafo[st].push_back(II(en,w));
            grafo[en].push_back(II(st,w));
        }
        dijkstra(inicio);
        cout<<"Case #: "<<cs++;
        if(dist[fin]==INF)
            cout<<"unreachable"<<endl;
        else cout<<dist[fin]<<endl;
    }
	return 0;
}
