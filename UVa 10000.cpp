#include <bits/stdc++.h>
using namespace std;

#define ll long long int

ll num_of_nodes, src;

list<ll> adj_list[110];
list<ll>::iterator it;
ll level[110];

void BFS_and_Levelling(ll src){

    queue<ll> q;

    level[src] = 0;
    q.push(src);

    while(!q.empty()){
        ll u = q.front();
        q.pop();

        for(it = adj_list[u].begin(); it != adj_list[u].end(); it++){
            ll v = *it;
            if(level[v] < level[u]+1){
                level[v] = level[u] + 1;
                q.push(v);
            }
        }

    }
}

int main(){
    ll kase = 0;
    bool first = true;

    while(1){

        scanf("%lld", &num_of_nodes);
        if(num_of_nodes == 0) break;

        scanf("%lld", &src);

        for(ll i = 0; i < 110; i++)
            adj_list[i].clear();

        ll u, v;
        while(1){
            scanf("%lld %lld", &u, &v);
            if(u == 0 && v == 0) break;
            adj_list[u].push_back(v);
        }

        memset(level, -1, sizeof(level));
        BFS_and_Levelling(src);

        ll anslevel = -1, stop;
        for(ll i = 1; i <= num_of_nodes; i++){
            if(level[i] > anslevel){
                anslevel = level[i];
                stop = i;
            }
        }

        //if(!first) printf("\n");
        //first = false;
        printf("Case %lld: The longest path from %lld has length %lld, finishing at %lld.\n", ++kase, src, anslevel, stop);
        printf("\n");

    } ///
}
