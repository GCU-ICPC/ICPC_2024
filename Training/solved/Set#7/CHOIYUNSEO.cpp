#include <bits/stdc++.h>
using namespace std;

int a[100001][2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = n; i <= m; i++) {
		a[i][0] = i;
	}

	for (int i = n; i <= m; i++) {
		while (true) {
			if (a[i][0] == 1) {
				break;
			}

			if (a[i][0] % 2 == 0) {
				a[i][0] /= 2;
			}
			else {
				a[i][0] = a[i][0] * 3 + 1;
			}
			a[i][1]++;
		}
	}

	int ans = 0;
	for (int i = n; i <= m; i++) {
		ans = max(ans, a[i][1]);
	}
	cout << n << " " <<  m << " " << ans + 1;
}
