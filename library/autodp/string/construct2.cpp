#include "autodp/template.hpp"
#include "autodp/matrix.hpp"

// 愚直
#include "autodp/string/naive.hpp"


void embed_coefs(int K, int len_max = INF, int LB_max = INF) {
    if (len_max == -1) len_max = INF;
    if (LB_max == -1) LB_max = INF;
	vector<string> ss{""};
	int idx = 0;

	vector<pii> piv_prv;

	repi(len, 0, INF) {
		dump("----------- len:", len, "--------------");

		int L = sz(ss); int LB = min(L, LB_max);
		dump("L:", L);
		
		// (i,j) 成分が naive(ss[i] + ss[j]) であるような行列 mat を得る．
		Matrix<mint> mat(L, LB);
		rep(i, L) rep(j, LB) mat[i][j] = naive(ss[i] + ss[j]);
		//dump("mat:"); dump(mat);

		// mat に対して行基本変形を行いピボット位置のリスト piv を得る．
		auto piv = row_reduced_form(mat);
		dump("piv:"); dump(piv);

		// rank の更新がなかったら必要な情報は揃ったとみなして打ち切る．
		if (len == len_max || (sz(piv) > 0 && sz(piv) == sz(piv_prv))) {
			int R = sz(piv);
			
			// 選択した行と列をそれぞれ昇順に並べて is, js とする（0 始まりのはず）
			vi is(R), js(R);
			rep(r, R) tie(is[r], js[r]) = piv[r];
			sort(all(js));

			// 基底の変換行列 P を得る．
			Matrix<mint> P(R, R);
			rep(i, R) rep(j, R) P[i][j] = naive(ss[is[i]] + ss[js[j]]);

			// P の逆行列 P_inv を得る．
			auto P_inv = inverse_matrix(P);

			// 各文字に対応する表現行列を得る．
			vector<Matrix<mint>> mats(K, Matrix<mint>(R, R));
			rep(k, K) {
				char c = '0' + k;
				rep(i, R) rep(j, R) mats[k][i][j] = naive(ss[is[i]] + c + ss[js[j]]);
				mats[k] = mats[k] * P_inv;
			}
						
			// 埋め込み用の文字列を出力する．
			auto to_signed_string = [](mint x) {
				int v = x.val();
				int mod = mint::mod();
				if (2 * v > mod) v -= mod;
				return to_string(v);
			};
			string eb = "#include \"autodp/template.hpp\"\n#include \"autodp/matrix.hpp\"\n#include \"autodp/string/naive.hpp\"\ntemplate <class VTYPE>\nVTYPE solve(const string& s) {\n\tconstexpr int DIM = ";
			eb += to_string(R);
			eb += ";\n";
			eb += "\tconstexpr int COL = ";
			eb += to_string(K);
			eb += ";\n";
			eb += "\tVTYPE matAs[COL][DIM][DIM] = {";		
			rep(k, K) {
				eb += "{";
				rep(i, R) {
					eb += "{";
					rep(j, R) eb += to_signed_string(mats[k][i][j]) + ",";
					eb.pop_back();
					eb += "},";
				}
				eb.pop_back();
				eb += "},";
			}
			eb.pop_back();
			eb += "};\n";
			eb += "\tVTYPE vecQ[DIM] = {";
			rep(i, R) eb += to_signed_string(P[i][0]) + ",";
			eb.pop_back();
			eb += "};\n\tarray<VTYPE, DIM> dp;dp[0] = 1;repi(i, 1, DIM - 1) {dp[i] = 0;}\n\tauto apply = [&](const array<VTYPE, DIM>& x, int col) {array<VTYPE, DIM> z;if (0 <= col && col < COL) {rep(j, DIM) {z[j] = 0;rep(i, DIM) z[j] += x[i] * matAs[col][i][j];}}else {rep(j, DIM) {z[j] = 0;rep(col, COL) rep(i, DIM) z[j] += x[i] * matAs[col][i][j];}}return z;};\n\trepe(c, s) {dp = apply(dp, c - '0');}\n\tVTYPE res = 0;rep(i, DIM) res += vecQ[i] * dp[i];\n\treturn res;\n}\n\nint main() {\n}\n";
			cout << eb;

			exit(0);
		}

		// 次に長い文字列たちを ss に追加する．
		int nidx = sz(ss);
		repi(i, idx, nidx - 1) rep(k, K) {
			ss.push_back(ss[i]);
			ss.back().push_back('0' + k);
		}
		idx = nidx;

		piv_prv = move(piv);
	}
}
int main() {
//	input_from_file("input.txt");
//	output_to_file("output.txt");

	//【方法】
	// 愚直を書いて集めたデータをもとに遷移行列を復元する．

	//【使い方】
	// 1. mint naive(文字列) を実装する．
	// 2. embed_coefs(文字の種類数); を実行する．
	// 3. 出力を solve() 内に貼る．
	// 4. auto dp = solve<答えの型>(文字列) で勝手に DP してくれる．
	
	embed_coefs(N, LEN_LIM, LB_LIM);
}