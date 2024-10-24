
### 1. **파일 입출력 (File I/O)**

```cpp
#include <fstream>
#include <iostream>
using namespace std;

int main() {
    // 파일에 쓰기
    ofstream outFile("output.txt");
    outFile << "lets go gpt" << endl;
    outFile.close();

    // 한 줄씩 읽기
    ifstream inFile("output.txt");
    string line;
    while (getline(inFile, line)) {
        cout << "한줄씩읽기 : " << line << endl;
    }

    inFile.clear();  // 파일 상태 초기화
    inFile.seekg(0);  // 파일 포인터 처음으로 이동

    // 한 단어씩 읽기
    string word;
    while (inFile >> word) {
        cout << "Word: " << word << endl;
    }

    inFile.close();
    return 0;
}
```

### 2. **Convex Hull (Graham's Scan)**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Point { int x, y; };

// 반시계 방향 확인
int ccw(Point a, Point b, Point c) {
    return (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
}

// Convex Hull 계산
vector<Point> convexHull(vector<Point>& p) {
    sort(p.begin(), p.end(), [](Point a, Point b) { return a.x < b.x || (a.x == b.x && a.y < b.y); });
    vector<Point> h;
    for (int i = 0; i < p.size(); i++) {
        while (h.size() >= 2 && ccw(h[h.size() - 2], h.back(), p[i]) <= 0) h.pop_back();
        h.push_back(p[i]);
    }
    return h;
}
```

### 3. **CCW (선분 교차 알고리즘)**

```cpp
#include <iostream>
using namespace std;
struct Point { int x, y; };

// CCW 함수 (선분 교차 판별)
int ccw(Point a, Point b, Point c) {
    int val = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
    return (val > 0) ? 1 : (val < 0) ? -1 : 0;
}

// 두 선분이 교차하는지 확인
bool doIntersect(Point p1, Point q1, Point p2, Point q2) {
    int o1 = ccw(p1, q1, p2);
    int o2 = ccw(p1, q1, q2);
    int o3 = ccw(p2, q2, p1);
    int o4 = ccw(p2, q2, q1);
    return (o1 != o2 && o3 != o4);
}

int main() {
    Point p1 = {1, 1}, q1 = {10, 1}, p2 = {1, 2}, q2 = {10, 2};
    cout << (doIntersect(p1, q1, p2, q2) ? "Intersect" : "Do not intersect") << endl;
    return 0;
}
```

### 4. **아스키 코드 변환**

```cpp
#include <iostream>
using namespace std;

int main() {
    char c = 'A';
    cout << c - 65 << endl;  // 'A'는 65이므로 0 출력
    char d = 'B';
    cout << d - 65 << endl;  // 'B'는 66이므로 1 출력
    return 0;
}
```

### 5. **이진 트리 (Binary Tree)**

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// 전위 순회
void preOrder(Node* node) {
    if (!node) return;
    cout << node->data << " ";  // 노드 방문
    preOrder(node->left);       // 왼쪽
    preOrder(node->right);      // 오른쪽
}

int main() {
    Node* root = new Node(1);  // 루트
    root->left = new Node(2);  // 왼쪽 자식
    root->right = new Node(3);  // 오른쪽 자식
    preOrder(root);  // 전위 순회
    return 0;
}
```













