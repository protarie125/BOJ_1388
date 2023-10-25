#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

int n, m;

vector<string> bd;
vvb visit;

void dfs(int i, int j) {
	auto st = stack<pii>{};
	st.push({ i, j });

	while (!st.empty()) {
		auto [y, x] = st.top();
		st.pop();

		//std::cout << "y, x = " << y << ", " << x << '\n';

		visit[y][x] = true;

		if ('|' == bd[y][x]) {
			if (y + 1 == n) {
				continue;
			}

			if (!visit[y + 1][x] && '|' == bd[y + 1][x]) {
				st.push({ y + 1, x });
			}
		}
		else if ('-' == bd[y][x]) {
			if (x + 1 == m) {
				continue;
			}

			if (!visit[y][x + 1] && '-' == bd[y][x + 1]) {
				st.push({ y, x + 1 });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> n >> m;

	bd = vector<string>(n);
	for (auto&& s : bd) {
		cin >> s;
	}

	visit = vvb(n, vb(m, false));

	auto ans = int{ 0 };
	for (auto i = 0; i < n; ++i) {
		for (auto j = 0; j < m; ++j) {
			if (visit[i][j]) {
				continue;
			}

			//std::cout << "i, j = " << i << ", " << j << '\n';

			dfs(i, j);

			++ans;
		}
	}

	cout << ans;

	return 0;
}