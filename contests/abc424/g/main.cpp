// ACL (AtCoder Library) を使った解法
// 仮定入力フォーマット:
// N M
// A1 A2 ... AN
// B1 C1
// ...
// BM CM
//
// コンパイル例:
// g++ -std=c++17 -O2 -I/path/to/acl/include solve.cpp
// （ACL ヘッダがインクルード可能な状態でコンパイルしてください）

#include <bits/stdc++.h>
#include "atcoder/maxflow"
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    if(!(cin >> N >> M)) return 0;
    vector<int> A(N);
    for(int i=0;i<N;i++) cin >> A[i];
    vector<int> B(M);
    vector<ll> C(M);
    ll sumC = 0;
    for(int j=0;j<M;j++){
        cin >> B[j] >> C[j];
        sumC += C[j];
    }

    // ノード割り当て
    // 0 = source (s)
    // 1..M = song nodes
    // 次に位置ノード (sum B_j 個)
    // 次に idol nodes (N 個)
    // 最後に sink (t)

    int s = 0;
    int song_start = 1;
    int song_end = song_start + M - 1;

    int total_positions = 0;
    for(int j=0;j<M;j++) total_positions += B[j];

    int pos_start = song_end + 1;
    int pos_end = pos_start + total_positions - 1;

    int idol_start = (total_positions>0 ? pos_end + 1 : song_end + 1);
    int idol_end = idol_start + N - 1;

    int t = idol_end + 1;

    int V = t + 1;

    atcoder::mf_graph<long long> mf(V);

    const long long INF = (long long)4e18;

    // s -> song (cap = Cj)
    for(int j=0;j<M;j++){
        int song_node = song_start + j;
        if(C[j] > 0) mf.add_edge(s, song_node, C[j]);
        // C[j] == 0 のときは辺を張る必要はない（張っても可）
    }

    // song -> positions (cap = INF), create position nodes sequentially
    vector<int> pos_idx_start_of_song(M);
    int cur_pos = pos_start;
    for(int j=0;j<M;j++){
        pos_idx_start_of_song[j] = cur_pos;
        for(int k=0;k<B[j];k++){
            int pos_node = cur_pos++;
            int song_node = song_start + j;
            mf.add_edge(song_node, pos_node, INF);
        }
    }
    // sanity
    if(cur_pos != (pos_start + total_positions)){
        // should not happen
    }

    // position -> each idol (cap = 1)
    // for each position node, connect to all idol nodes with capacity 1
    cur_pos = pos_start;
    for(int j=0;j<M;j++){
        for(int k=0;k<B[j];k++){
            int pos_node = cur_pos++;
            for(int i=0;i<N;i++){
                int idol_node = idol_start + i;
                mf.add_edge(pos_node, idol_node, 1);
            }
        }
    }

    // idol -> t (cap = A_i)
    for(int i=0;i<N;i++){
        int idol_node = idol_start + i;
        if(A[i] > 0) mf.add_edge(idol_node, t, A[i]);
        // A[i]==0 の場合は辺を張らない（張っても cap=0 で無意味）
    }

    long long maxf = mf.flow(s, t);
    long long ans = sumC - maxf;
    cout << ans << "\n";
    return 0;
}
