// #include <bits/stdc++.h>
// #include <cctype>
// using namespace std;

// char arr[100][100];  
// int m, n, k;

// pair<int, int> horizontal(const string& word, int r, int c) { // 가로
//     for (int i = 0; i < word.length(); i++) {
//         if (c + i >= n || arr[r][c + i] != word[i]) {
//             return {-1, -1};  
//         }
//     }
    
//     return {r, c}; 
// }

// pair<int, int> orthogonal(const string& word, int r, int c) { // 세로
//     for (int i = 0; i < word.length(); i++) {
//         if (r + i >= m || arr[r + i][c] != word[i]) {
//             return {-1, -1}; 
//         }
//     }
    
//     return {r, c}; 
// }

// pair<int, int> diagonal_right_up(const string& word, int r, int c) { // 오른쪽 위 대각선
//     for (int i = 0; i < word.length(); i++) {
//         if (r - i < 0 || c + i >= n || arr[r - i][c + i] != word[i]) {
//             return {-1, -1};
//         }
//     }
    
//     return {r, c}; 
// }

// pair<int, int> diagonal_left_down(const string& word, int r, int c) { // 왼쪽 아래 대각선
//     for (int i = 0; i < word.length(); i++) {
//         if (r + i >= m || c - i < 0 || arr[r + i][c - i] != word[i]) {
//             return {-1, -1};
//         }
//     }
    
//     return {r, c}; 
// }


#include <bits/stdc++.h>
#include <cctype>
using namespace std;

char arr[100][100];  
int m, n, k;

pair<int, int> horizontal(const string& word, int r, int c) { // 가로
    for (int i = 0; i < word.length(); i++) { // 정방향
        if (c + i >= n || arr[r][c + i] != word[i]) {
            break;
        }
        if (i == word.length() - 1) {
            return {r, c}; 
        }
    }
    
    for (int i = 0; i < word.length(); i++) { // 역방향
        if (c - i < 0 || arr[r][c - i] != word[i]) {
            break;
        }
        if (i == word.length() - 1) {
            return {r, c - word.length() + 1};
        }
    }
    
    return {-1, -1};  
}

pair<int, int> orthogonal(const string& word, int r, int c) { // 세로
    for (int i = 0; i < word.length(); i++) { // 정방향
        if (r + i >= m || arr[r + i][c] != word[i]) {
            break;
        }
        if (i == word.length() - 1) {
            return {r, c}; 
        }
    }
    
    for (int i = 0; i < word.length(); i++) { // 역방향
        if (r - i < 0 || arr[r - i][c] != word[i]) {
            break;
        }
        if (i == word.length() - 1) {
            return {r - word.length() + 1, c};
        }
    }
    
    return {-1, -1}; 
}

pair<int, int> diagonal_right_up(const string& word, int r, int c) { // 오른쪽 위 대각선
    for (int i = 0; i < word.length(); i++) { // 정방향
        if (r - i < 0 || c + i >= n || arr[r - i][c + i] != word[i]) {
            break;
        }
        if (i == word.length() - 1) {
            return {r - word.length() + 1, c}; 
        }
    }
    
    for (int i = 0; i < word.length(); i++) { // 역방향
        if (r + i >= m || c - i < 0 || arr[r + i][c - i] != word[i]) {
            break;
        }
        if (i == word.length() - 1) {
            return {r + i, c - i}; 
        }
    }
    
    return {-1, -1}; 
}

pair<int, int> diagonal_left_down(const string& word, int r, int c) { // 왼쪽 아래 대각선
    for (int i = 0; i < word.length(); i++) { // 정방향
        if (r + i >= m || c - i < 0 || arr[r + i][c - i] != word[i]) {
            break;
        }
        if (i == word.length() - 1) { 
            return {r, c};
        }
    }
    
    for (int i = 0; i < word.length(); i++) { // 역방향
        if (r - i < 0 || c + i >= n || arr[r - i][c + i] != word[i]) {
            break;
        }
        if (i == word.length() - 1) {
            return {r - word.length() + 1, c + word.length() - 1};
        }
    }
    
    return {-1, -1}; 
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        // string line;
        // std::getline(std::cin, line); // 개행문자
        
        cin >> n >> m;

        for (int j = 0; j < n; j++) {
            for (int p = 0; p < m; p++) {
                char a;
                cin >> a;

                a = std::tolower(a);
                arr[j][p] = a;
            }
        }

        cin >> k;

        for (int j = 0; j < k; j++) {
            string word;
            cin >> word;

            for (char& ch : word) {
                ch = std::tolower(ch);  
            }

            int token = 0;
            
            pair<int, int> pos;
            for (int r = 0; r < m; ++r) {
                for (int c = 0; c < n; ++c) {
                    if (arr[r][c] == word[0]) { 
                        if ((pos = horizontal(word, r, c)).first != -1 ||
                            (pos = orthogonal(word, r, c)).first != -1 ||
                            (pos = diagonal_right_up(word, r, c)).first != -1 ||
                            (pos = diagonal_left_down(word, r, c)).first != -1) {
                                
                            token = 1;
                            cout << pos.first + 1 << ' ' << pos.second + 1 << '\n';
                            break;
                        }
                    }
                }
                
                if (token == 1) {
                    break; 
                }
            }

            // if (token == 0) {
            //     cout << "Not Found\n";
            // }
        }
    }

    return 0;
}
