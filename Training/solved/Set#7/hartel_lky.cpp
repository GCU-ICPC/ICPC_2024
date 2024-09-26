#include <bits/stdc++.h>
using namespace std;

int main() {
    int T = 0;
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        int arr[3651] = {0}; 
        int cnt = 0;
        int N = 0, P = 0; 
        
        cin >> N;
        cin >> P;
        
        for (int j = 0; j < P; j++) {
            int h = 0;
            cin >> h;
            
            int current = h;
            
            while (current <= N) {
                if (current % 7 != 6 && current % 7 != 0) {  
                    if (arr[current] == 0) {  
                        arr[current] = 1;
                        cnt++;
                    }
                }
                current += h;
            }
        }
        
        cout << cnt << '\n';
    }
    
    return 0;
}
