#include <bits/stdc++.h>
#include <cctype>
using namespace std;

char arr[100][100];  
int m, n, k;

pair<int, int> horizontal(const string& word, int r, int c) { // 가로 탐색
    for (int i = 0; i < word.length(); i++) { // 정방향
        if (c + i >= n || arr[r][c + i] != word[i]) {
            break;
        }
        if (i == word.length() - 1) {
            return {r, c}; // 단어 시작 위치 반환
        }
    }
    
    for (int i = 0; i < word.length(); i++) { // 역방향
        if (c - i < 0 || arr[r][c - i] != word[i]) {
            break;
        }
        if (i == word.length() - 1) {
            return {r, c};
        }
    }
    
    return {-1, -1};  
}

pair<int, int> vertical(const string& word, int r, int c) { // 세로 탐색
    for (int i = 0; i < word.length(); i++) { // 정방향
        if (r + i >= m || arr[r + i][c] != word[i]) {
            break;
        }
        if (i == word.length() - 1) {
            return {r, c}; // 단어 시작 위치 반환
        }
    }
    
    for (int i = 0; i < word.length(); i++) { // 역방향
        if (r - i < 0 || arr[r - i][c] != word[i]) {
            break;
        }
        if (i == word.length() - 1) {
            return {r, c};
        }
    }
    
    return {-1, -1}; 
}

// pair<int, int> diagonal_right_up(const string& word, int r, int c) { // 오른쪽 위 대각선
//     for (int i = 0; i < word.length(); i++) { // 정방향
//         if (r - i < 0 || c + i >= n || arr[r - i][c + i] != word[i]) {
//             break;
//         }
//         if (i == word.length() - 1) {
//             return {r, c}; // 단어 시작 위치 반환
//         }
//     }
    
//     for (int i = 0; i < word.length(); i++) { // 역방향
//         if (r + i >= m || c - i < 0 || arr[r + i][c - i] != word[i]) {
//             break;
//         }
//         if (i == word.length() - 1) {
//             return {r, c};
//         }
//     }
    
//     return {-1, -1}; 
// }

// pair<int, int> diagonal_left_down(const string& word, int r, int c) { // 왼쪽 아래 대각선
//     for (int i = 0; i < word.length(); i++) { // 정방향
//         if (r + i >= m || c - i < 0 || arr[r + i][c - i] != word[i]) {
//             break;
//         }
//         if (i == word.length() - 1) { 
//             return {r, c};
//         }
//     }
    
//     for (int i = 0; i < word.length(); i++) { // 역방향
//         if (r - i < 0 || c + i >= n || arr[r - i][c + i] != word[i]) {
//             break;
//         }
//         if (i == word.length() - 1) {
//             return {r, c};
//         }
//     }
    
//     return {-1, -1}; 
// }

pair<int, int> diagonal_right_up(const string& word, int r, int c) {
    for (int i = 0; i < (int)word.length(); i++) { // 정방향
        if (r - i < 0 || c + i >= n || arr[r - i][c + i] != word[i]) {
            break;
        }
        if (i == (int)word.length() - 1) {
            return {r, c}; // 단어 시작 위치 반환
        }
    }
    
    for (int i = 0; i < (int)word.length(); i++) { // 역방향
        if (r + i >= m || c - i < 0 || arr[r + i][c - i] != word[i]) {
            break;
        }
        if (i == (int)word.length() - 1) {
            return {r, c};
        }
    }
    
    return {-1, -1};
}

pair<int, int> diagonal_left_down(const string& word, int r, int c) {
    for (int i = 0; i < (int)word.length(); i++) { // 정방향
        if (r + i >= m || c + i >= n || arr[r + i][c + i] != word[i]) {
            break;
        }
        if (i == (int)word.length() - 1) { 
            return {r, c};
        }
    }
    
    for (int i = 0; i < (int)word.length(); i++) { // 역방향
        if (r - i < 0 || c - i < 0 || arr[r - i][c - i] != word[i]) {
            break;
        }
        if (i == (int)word.length() - 1) {
            return {r, c};
        }
    }
    
    return {-1, -1};
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> m >> n;

        for (int j = 0; j < m; j++) {
            for (int p = 0; p < n; p++) {
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
                ch = std::tolower(ch);  // 입력 단어도 소문자로 변환
            }

            int token = 0;
            pair<int, int> pos;
            
            for (int r = 0; r < m; ++r) {
                for (int c = 0; c < n; ++c) {
                    if (arr[r][c] == word[0]) {  
                        if ((pos = horizontal(word, r, c)).first != -1 ||
                            (pos = vertical(word, r, c)).first != -1 ||
                            (pos = diagonal_right_up(word, r, c)).first != -1 ||
                            (pos = diagonal_left_down(word, r, c)).first != -1) {
                                
                            token = 1;
                            cout << pos.first + 1 << ' ' << pos.second + 1 << '\n';  // 좌표 출력
                            break;
                        }
                    }
                }
                
                if (token == 1) {
                    break; 
                }
            }

            if (token == 0) {
                cout << "Not Found\n"; 
            }
        }
    }

    return 0;
}
