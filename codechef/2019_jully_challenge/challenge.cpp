/*
    N cities;
    M roads;
    Non-eagerness E(u, d) = P(u) + Q(u)*d; u in [1..N];
    K special cities - connected subgraph; if any of road is destoyed, still stay connected subgraph;
    S roads at most constructed/repaired simultaneously;
    Road: U, V, L, A, B
        Conects cities U, V
        takes L days to repair
        Costs A + B*d if started to repair on day d (B>0)
    To constuct new road between u and v (only if no direct road existed)
        The cost is (E(u, d) + E(v, d)) * D(u, v)
        The time is D(u, v)
        D(u, v) - the shortest path

    Cost -> min

    Plan:
    X_i = d_i, e_i - idx of road to repair
    Y_j = d_j, u_j, v_j

    Cost = Sum_i (A_(e_i)+ B_(e_i) * d_i) + Sum_j ((E(u_j, d_j) + E(v_j, d_j)) * D(u_j, v_j)) -> min
    Constr:
        [d_i; d_i + L_i]; [d_j; d_j + D(u_j, v_j)] 
            have max intersection of S;
            the union has no holes;
            The K subgraph is 1-any-extra-connected

*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;



int main () {
    int N = 256, M, K, S = 16;
    cin >> N >> M >> K >> S;
    int Ks[K];
    for(int k = 0; k < K; k++)
    {
        cin >> Ks[k];
    }
    struct {
        int P;
        int Q;
    } Es[N];
    for(int i = 0; i < N; i++)
    {
        cin >> Es[i].P >> Es[i].Q;
    }
    struct {
        int U;
        int V;
        int L;
        int A;
        int B;
    } Roads[M];
    for(int i = 0; i < M; i++)
    {
        cin >> Roads[i].U >> Roads[i].V >> Roads[i].L >> Roads[i].A >> Roads[i].B;
    }
    return 0;
}