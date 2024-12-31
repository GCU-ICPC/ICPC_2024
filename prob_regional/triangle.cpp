#include <bits/stdc++.h>
using namespace std;

vector<pair<long long, long long>> posi_AB;
vector<pair<long long, long long>> posi_BC;
vector<pair<long long, long long>> posi_CA;

long long gcd(long long a, long long b) {
    if (a == 0) {
        return b;
    }
    else {
        return gcd(b%a, a);
    }
}

bool cmp(pair<long long, long long>&a, pair<string, long long>&b) {
    return a.second <= b.second;
}

vector<pair<long long, long long>> get(pair<long long, long long> gradient, long long x1, long long y1, long long x2, long long y2) {
    vector<pair<long long, long long>> posi_k;
    
    if (gradient.first * gradient.second < 0) {
        if (x1 < x2) {
            long long cur_x = x1 + abs(gradient.second);
            long long cur_y = y1 + -1 * abs(gradient.first);
            while (true) {
                if (cur_x >= x2 && cur_y >= y2) {
                    break;
                }
                else {
                    posi_k.push_back({cur_x, cur_y});
                    cur_x += abs(gradient.second);
                    cur_y += -1 * abs(gradient.first);
                }
            }
        }
        else {
            long long cur_x = x2 + abs(gradient.second);
            long long cur_y = y2 + -1 * abs(gradient.first);
            while (true) {
                if (cur_x >= x1 && cur_y >= y1) {
                    break;
                }
                else {
                    posi_k.push_back({cur_x, cur_y});
                    cur_x += abs(gradient.second);
                    cur_y += -1 * abs(gradient.first);
                }
            }
        }
    }
    else if (gradient.first * gradient.second > 0) {
        if (x1 < x2) {
            long long cur_x = x1 + abs(gradient.second);
            long long cur_y = y1 + abs(gradient.first);
            while (true) {
                if (cur_x >= x2) {
                    break;
                }
                else {
                    posi_k.push_back({cur_x, cur_y});
                    cur_x += abs(gradient.second);
                    cur_y += abs(gradient.first);
                }
            }
        }
        else {
            long long cur_x = x2 + abs(gradient.second);
            long long cur_y = y2 + abs(gradient.first);
            while (true) {
                if (cur_x >= x1) {
                    break;
                }
                else {
                    posi_k.push_back({cur_x, cur_y});
                    cur_x += abs(gradient.second);
                    cur_y += abs(gradient.first);
                }
            }
        }
    }
    else {
        if (gradient.first == 0) {
            if (x1 < x2) {
                long long cur_x = x1 + abs(gradient.second);
                long long cur_y = y1;
                while (true) {
                    if (cur_x >= x2) {
                        break;
                    }
                    else {
                        posi_k.push_back({cur_x, cur_y});
                        cur_x += abs(gradient.second);
                    }
                }
            }
            else {
                long long cur_x = x2 + abs(gradient.second);
                long long cur_y = y2;
                while (true) {
                    if (cur_x >= x1) {
                        break;
                    }
                    else {
                        posi_k.push_back({cur_x, cur_y});
                        cur_x += abs(gradient.second);
                    }
                }
            }
        }
        else if (gradient.second == 0) {
            if (y1 < y2) {
                long long cur_x = x1;
                long long cur_y = y1 + abs(gradient.first);
                while (true) {
                    if (cur_y >= y2) {
                        break;
                    }
                    else {
                        posi_k.push_back({cur_x, cur_y});
                        cur_y += abs(gradient.first);
                    }
                }
            }
            else {
                long long cur_x = x2;
                long long cur_y = y2 + abs(gradient.first);
                while (true) {
                    if (cur_y >= y1) {
                        break;
                    }
                    else {
                        posi_k.push_back({cur_x, cur_y});
                        cur_y += abs(gradient.first);
                    }
                }
            }
        }
    }
    return posi_k;
}

int ccw(pair<long long, long long> p1, pair<long long, long long> p2, pair<long long, long long> p3) {
    int val = (p2.second-p1.second) * (p3.first - p2.first) - (p2.first - p1.first) * (p3.second - p2.second);
    return (val > 0) ? 1 : (val < 0) ? -1 : 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    long long x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    
    vector<pair<long long, long long>> for_sort;
    for_sort.push_back({x1, y1});
    for_sort.push_back({x2, y2});
    for_sort.push_back({x3, y3});
    
    int token = ccw(for_sort[0], for_sort[1], for_sort[2]);
    
    if (token == -1) {}
    else if (token == 1) {
        long long temp_x, temp_y;
        temp_x = y3;
        temp_y = y3;
        x3 = x2;
        y3 = y2;
        x2 = temp_x;
        y2 = temp_y;
    }
    
    pair<long long, long long> gradient_AB = {(y1-y2) / gcd(x1-x2, y1-y2), (x1-x2) / gcd(x1-x2, y1-y2)};
    pair<long long, long long> gradient_BC = {(y2-y3) / gcd(x2-x3, y2-y3), (x2-x3) / gcd(x2-x3, y2-y3)};
    pair<long long, long long> gradient_CA = {(y3-y1) / gcd(x3-x1, y3-y1), (x3-x1) / gcd(x3-x1, y3-y1)};
    
    posi_AB = get(gradient_AB, x1, y1, x2, y2);
    posi_BC = get(gradient_BC, x2, y2, x3, y3);
    posi_CA = get(gradient_CA, x1, y1, x3, y3);
    
    if (posi_AB.empty() || posi_BC.empty() || posi_CA.empty()) {
        cout << -1;
        return 0;
    }
    
    long long max = -1;
    long long min = 0x7f7f7f7f;
    for (int i = 0; i < posi_AB.size(); i++) {
        for (int j=0; j < posi_BC.size(); j++) {
            for (int k = 0; k < posi_CA.size(); k++) {
                x1 = posi_AB[i].first;
                y1 = posi_AB[i].second;
                x2 = posi_BC[j].first;
                y2 = posi_BC[j].second;
                x3 = posi_CA[k].first;
                y3 = posi_CA[k].second;
                
                long long l1 = sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
                long long l2 = sqrt(pow(x2-x3, 2) + pow(y2-y3, 2));
                long long l3 = sqrt(pow(x1-x3, 2) + pow(y1-y3, 2));
                
                long long arr[3] = {l1, l2, l3};
                
                long long max_arr = 0;
                
                for(int p = 0; p < 3; p++) {
                    if (arr[max_arr] < arr[p]) {
                        max_arr = p;
                    }
                }
                
                if (max_arr == 0) {
                    if (arr[max_arr] >= arr[1] + arr[2]) {
                        cout << -1;
                        return 0;
                    }
                }
                else if (max_arr == 1) {
                    if (arr[max_arr] >= arr[0] + arr[2]) {
                        cout << -1;
                        return 0;
                    }
                }
                else {
                    if (arr[max_arr] >= arr[1] + arr[0]) {
                        cout << -1;
                        return 0;
                    }
                }
                
                long long S = (x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1);
                
                if (S > max) {
                    max = S;
                }
                
                if (S < min) {
                    min = S;
                }
            }
        }
    }
    
    if (max == -1 || min == 0x7f7f7f7f) {
        cout << -1;
        return 0;
    }
    cout << max << ' ' << min;
}
