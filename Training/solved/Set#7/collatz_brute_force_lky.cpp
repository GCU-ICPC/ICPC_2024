#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll cal(ll n) {
    ll length = 1;  
    
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
        } 
        
        else {
            n = 3 * n + 1;
        }
        
        length++;
    }
    
    return length; 
}

ll find_max (ll n, ll m) {
    if (n > m) {
        swap(n, m);  // n이 m보다 클수도 있음 (조건 X)
    }
    
    ll max_length = 0;
    
    for (ll i = n; i <= m; i++) {
        max_length = max(max_length, cal(i));
    }
    
    return max_length;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0); 
    
    ll n, m;

    while (cin >> n >> m) {
        ll result = find_max(n, m);
        cout << n << " " << m << " " << result << '\n';
    }

    return 0;
}
