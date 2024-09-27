#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--) {
		int days;
		cin >> days;

		int parties;
		cin >> parties;

		vector<int> h;

		for (int i = 0; i < parties; i++) {
			int hartal;
			cin >> hartal;
			h.push_back(hartal);
		}

		set<int> s;
		for (int i = 0; i < parties; i++) {
			int idx = h[i]-1;
			while (idx < days) {
				s.insert(idx);
				idx += h[i];
			}
		}

		int ans = 0;
		for (auto it = s.begin(); it != s.end(); it++){
			if ((*it) % 7 == 5 || (*it) % 7 == 6) {
				continue;
			}
			ans++;
		}
		cout << ans << '\n';
	}
}
