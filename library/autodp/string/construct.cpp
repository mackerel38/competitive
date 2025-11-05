#include "autodp/template.hpp"
#include "autodp/matrix.hpp"

// 愚直
#include "autodp/string/naive.hpp"


// 遷移行列の係数を計算し，埋め込み用のコードを出力する．
void embed_coefs(int K) {
	vector<string> ss;

	vector<pii> piv_prv;

	repi(len, 0, INF) {
		dump("----------- len:", len, "--------------");

		// 長さ len の '0', ..., 'K-1' からなる文字列を ss に追加する．
		string s;
		function<void(int)> rf = [&](int i) {
			if (i == len) {
				ss.push_back(s);
				return;
			}

			rep(k, K) {
				s.push_back('0' + k);
				rf(i + 1);
				s.pop_back();
			}
		};
		rf(0);
		dump("ss:"); dump(ss);

		// (i,j) 成分が naive(ss[i] + ss[j]) であるような行列 mat を得る．
		int L = sz(ss);
		Matrix<mint> mat(L, L);
		rep(i, L) rep(j, L) mat[i][j] = naive(ss[i] + ss[j]);
		dump("mat:"); dump(mat);

		// mat に対して行基本変形を行いピボット位置のリスト piv を得る．
		auto piv = row_reduced_form(mat);
		dump("piv:"); dump(piv);

		// rank の更新がなかったら必要な情報は揃ったとみなして打ち切る．
		if (len > 0 && sz(piv) == sz(piv_prv) || len==LEN_LIM) {
			int R = sz(piv);
			
			// 選択した行と列をそれぞれ昇順に並べて is, js とする（0 始まり）
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
			string eb = "";
			eb += "#include \"autodp/template.hpp\"\n#include \"autodp/matrix.hpp\"\n#include \"autodp/string/naive.hpp\"\n";
			eb += "template <class VTYPE>\nVTYPE solve(const string& s) {\n";
			eb += "\tvector<vector<VTYPE>>matP_ume={";
			rep(i, R) {
				eb += "{";
				rep(j, R) eb += to_signed_string(P[i][j]) + ",";
				eb.pop_back();
				eb += "},";
			}
			eb.pop_back();
			eb += "};\n\tvector<vector<vector<VTYPE>>>mats_ume={";
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
			eb += "};\n\tint R = sz(matP_ume);\n\tint K = sz(mats_ume);\n\tMatrix<VTYPE> matP(matP_ume);\n\tvector<Matrix<VTYPE>> mats(K);\n\trep(k, K) mats[k] = Matrix<VTYPE>(mats_ume[k]);\n\tMatrix<VTYPE> mat(R);\n\trepe(c, s) mat = mat * mats[c - '0'];\n\tmat = mat * matP;\n\treturn mat[0][0];\n}\n\nint main() {\n}\n";
			cout << eb;
			exit(0);
		}

		piv_prv = move(piv);
	}
}


int main() {
//	input_from_file("input.txt");
//	output_to_file("output.txt");

	//【方法】
	// 愚直を書いて集めたデータをもとに遷移行列を復元する．

	embed_coefs(N);
}
