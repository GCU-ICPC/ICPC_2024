#include <bits/stdc++.h>
using namespace std;

int y = 0;

bool millar_rabin (int N, int t) {
    int alpha = 1, temp = N;
    
    while (temp != 1) {
        temp /= 2;
        alpha++;
    }
    
    int beta = N-1 / pow(2, alpha);
    for (int i = 1; i < t; i++) {
        int rand_num = int(N / 3);
        
        y = pow(rand_num, beta) % N;
        
        if (y != 1 and y != N - 1) {
            int j = 1;
            
            while (j <= alpha - 1 && j != N - 1) {
                y = pow(y, 2) % N;
                
                if (y == 1) {
                    return false;
                }
                
                j++;
            }
            
            if (y != N - 1) {
                return false;
            }
        }
    }
    
    return true;
}

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        
        if (millar_rabin(input) == true) {
            cout << "prime" << '\n';
        }
        
        else {
            cout << "not prime" << '\n';
        }
    }
    
    return 0;
}
