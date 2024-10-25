### 순서 ###
```
1. 파일 입출력 (File I/O)
2. Convex Hull (Graham's Scan)
3. CCW (선분 교차 알고리즘)
4. 아스키 코드 변환
5. 이진 트리 (Binary Tree)
6. Bfs
7. Dfs
8. Dijkstra
9. Union & Find
10. Prioirty Queue
11. Millar Rabin
12. Unorderd_map
13. Minimum Spanning Tree
14. Palindrome
15. Segment Tree
16. DP optimization
17. Merge sort
18. Swap
19. Vector
20. Suffix array
21.Basic arithmetic
22. KMP
```


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

### 6.  **BFS**
```cpp
#include <iostream>
#include <algorithm>
#include <cstring>
#include <deque>
using namespace std;
 
int n, k;
int dist[100001];
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
 
    cin >> n >> k;
    memset(dist, -1, sizeof dist);
 
    deque <int> dq; // 큐의 앞에 삽입하는 작업을 위해 deque를 사용한다.
    dq.push_back(n);
    dist[n] = 0;
 
    while (!dq.empty())
    {
        int v = dq.front(); dq.pop_front();
 
        if (v * 2 <= 100000 && dist[v * 2] == -1)
        {
            // 두 점 사이의 거리가 0이면 큐의 앞에 추가한다.
 
            dq.push_front(v * 2);
            dist[v * 2] = dist[v];
        }
 
        if (v - 1 >= 0 && dist[v - 1] == -1)
        {
            dq.push_back(v - 1);
            dist[v - 1] = dist[v] + 1;
        }
 
        if (v + 1 <= 100000 && dist[v + 1] == -1)
        {
            dq.push_back(v + 1);
            dist[v + 1] = dist[v] + 1;
        }
    }
 
    cout << dist[k];
}
```

### 7.  **DFS using recursion**
```cpp
#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v); //singly linked ,not bidirectional
}

void DFS(vector<int> adj[], int v, vector<bool> &vis)
{
    vis[v] = true;
    cout << v << " ";
    //for(int i=0;i<adj[v].size() ; i++)
    for (auto i : adj[v])
    {
        //if(!vis[adj[v][i]])
        if (vis[i] == false)
            DFS(adj, i, vis);
    }
}

int main()
{
    vector<int> adj[5];
    vector<bool> visited(5, false);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 3, 5);
    addEdge(adj, 4, 5);
    DFS(adj, 1, visited);
}
```
### 8.  **Dijkstra**
```cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

//다익스트라 알고리즘 with 사이클 (Dijkstra Algorithm) 
//1) 각 정점에 경로의 최소 길이 및 이전 정점 저장 
//알고리즘 (간선의 BFS 기반)
//1) 시작점을 선택한 뒤 간선을 큐에 넣는다.
//2) 큐에서 간선을 꺼내온 뒤 타겟 정점의 최소길이와 간선 가중치 + 이전 정점 최소길이를 비교한다.
//3) 클 경우 아무것도 다음 큐를 탐색한다. (이미 최소 경로가 존재)
//4) 작을 경우 최소경로 길이로 갱신한뒤 해당 정점의 간선들을 큐에 담고 2)로 돌아간다.
//5) 큐가 empty가 되면 종료한다.

//다익스트라의 단점 
//음수 사이클이 있는 그래프에서는 해결할 수 없다.
//this can't be used in cycle graph with minus value


class Edge{
public:
	int from;
	int to;
	int weight;
	Edge* next;
	Edge(){
		next = NULL;
		from = -1;
		to = 1;
		weight = -1;
	}
};
class Vert{
public:
	int index;
	Edge* adjList;
	int adjSize;
	int pathSize;
	int prevV;
	Vert(){
		index = -1;
		adjList = NULL;
		adjSize = 0;
		pathSize = ~(1 << 31);
		prevV = -1;
	}
};
class Graph{
public:
	int vSize;
	Vert *v;
	Graph(int vSize){
		v = new Vert[vSize];
		for (int i = 0; i < vSize; i++){
			v[i].index = i;
		}
	}
	vector<int> getMinimumIndex(int start, int end){
		vector<int> result;
		queue<Edge*> q;
		
		Vert* startv = &v[start];
		startv->pathSize = 0;
		
		Edge* e = startv->adjList;
		while (e != NULL){
			q.push(e);
			e = e->next;
		}
		int count = 0;
		while (q.empty() == false){
			count++;
			Edge* e = q.front();	//back()도 있으나 front가 push와 같이 사용됨
			q.pop();
			Vert* target = &v[e->to];
			Vert* fromV = &v[e->from];
			if (target->pathSize > (fromV->pathSize + e->weight)){
				target->prevV = e->from;
				target->pathSize = fromV->pathSize + e->weight;
				//목표 정점의 간선들을 큐에 담음
				Edge* adjE = target->adjList;
				while (adjE != NULL){
					if (adjE->to != e->from)
						q.push(adjE);
					adjE = adjE->next;
				}
			}
			else{
				//해당 경로는 더이상 진행하지 않음
			}
		}
		//이전 정점을 순회하면서 최단경로를 찾음
		int prev = v[end].prevV;
		if (prev != -1)
			result.push_back(end);
		while (prev != -1){
			result.push_back(prev);
			prev = v[prev].prevV;
		}
		cout << count << endl;
		return result;
	}
};
int main(){
	fstream f("다익스트라.txt");
	int testcase;
	f >> testcase;
	for (int i = 0; i < testcase; i++){
		int vSize, eSize;
		int start, end;
		f >> start >> end;
		f >> vSize >> eSize;
		Graph g(vSize);
		for (int j = 0; j < eSize; j++){
			Edge* e1 = new Edge();
			Edge* e2 = new Edge();
			int from, to, weight;
			f >> from >> to >> weight;
			e1->from = from;
			e1->to = to;
			e1->weight = weight;

			e2->from = to;
			e2->to = from;
			e2->weight = weight;
			if (g.v[from].adjList == NULL){
				g.v[from].adjList = e1;
			}
			else{
				Edge* t = g.v[from].adjList ;
				g.v[from].adjList = e1;
				e1->next = t;
			}
			g.v[from].adjSize++;
			if (g.v[to].adjList == NULL){
				g.v[to].adjList = e2;
			}
			else{
				Edge* t = g.v[to].adjList;
				g.v[to].adjList = e2;
				e2->next = t;
			}
			g.v[to].adjSize++;
		}
		vector<int> v = g.getMinimumIndex(start, end);
		vector<int>::reverse_iterator iter = v.rbegin();
		cout << "[시작] " << start << "  [종료] " << end << endl;
		for (; iter < v.rend(); iter++){

			cout << *iter << " -> ";

		}
		cout << "[가중치] " << g.v[v.front()].pathSize ;
		cout << endl;
	}
	return 0;
}
```

### 9.  **Union & Find**
```cpp
int find(int x) {
    if (parent[x] < 0) {
        return x;
    }
    
    parent[x] = find(parent[x]);
    return parent[x];
}

void union(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX == rootY) {
        return;
    }

    if (parent[rootY] * -1 < parent[rootX] * -1 ) {
        parent[rootX] += parent[rootY];
        parent[rootY] = rootX;
        return;
    }

    parent[rootY] += parent[rootX];
    parent[rootX] = rootY;
}
```

### 10.  **Priority Queue**
```cpp
#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
	// priority_queue<int> q;	// 내림차순 
	// priority_queue<int, vector<int>, less<int> > q;	// 내림차순
	priority_queue<int, vector<int>, greater<int> > q;	// 오름차순

	if (q.empty()) cout << "우선순위 큐가 비었습니다.\n";

	q.push(4);
	q.push(4);
	q.push(2);
	q.push(1);
	q.push(3);

	cout << "맨 위 : " << q.top() << "\n";


	cout << "나가는 순서 : ";
	while (!q.empty()) {
		cout << q.top() << " ";
		q.pop();
	}
	cout << "\n";

	return 0;
}
```

### 11. **Millar Rabin**
```cpp
namespace miller_rabin{ // O(logP)
	i64 mul(i64 x, i64 y, i64 mod){ return (__int128) x * y % mod; }
	i64 ipow(i64 x, i64 y, i64 p){
		i64 ret = 1, piv = x % p;
		while(y){
			if(y&1) ret = mul(ret, piv, p);
			piv = mul(piv, piv, p);
			y >>= 1;
		}
		return ret;
	}
	bool miller_rabin(i64 x, i64 a){
		if(x % a == 0) return 0;
		i64 d = x - 1;
		while(1){
			i64 tmp = ipow(a, d, x);
			if(d&1) return (tmp != 1 && tmp != x-1);
			else if(tmp == x-1) return 0;
			d >>= 1;
		}
	}
	bool isprime(i64 x){
		for(auto &i : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}){
			if(x == i) return 1;
			if(x > 40 && miller_rabin(x, i)) return 0;
		}
		if(x <= 40) return 0;
		return 1;
	}
}
```

### 12. **Unordered_map**
```cpp
// 오름차순
#include <iostream>
#include <unordered_map>
#include <string>
 
using namespace std;
 
unordered_map<string, int> hs;
 
int main()
{
    hs.insert(make_pair<string, int>("greec", 1));
    hs.insert(make_pair<string, int>("luna", 3));
    hs.insert(make_pair<string, int>("selly", 7));
    hs.insert(make_pair<string, int>("del", 5));
    hs.insert(make_pair<string, int>("suprem", 4));
    hs.insert(make_pair<string, int>("nord", 3));
    hs.insert(make_pair<string, int>("ding", 2));
    hs.insert(make_pair<string, int>("creek", 2));
    hs.insert(make_pair<string, int>("sua", 3));
 
    // element access with key
    cout << "element access" << endl;
    cout << hs["greec"] << endl;
    cout << hs["ding"] << endl;
    cout << hs["sua"] << endl;
    cout << hs["eeqq"] << endl;
    cout << endl;
 
    // add value with the same key
    cout << "insert with the same key" << endl;
    hs.insert(make_pair<string, int>("greec", 10));
    cout << hs["greec"] << endl;    // 1
    cout << endl;
    
    // update key with new value
    cout << "insert with the same key" << endl;
    auto iter = hs.find("greec");
    if (iter != hs.end())
    {
        hs.erase("greec");
    }
    hs.insert(make_pair<string, int>("greec", 10));
    cout << hs["greec"] << endl;    // 10
    cout << endl;
 
 
    // not ordered
    cout << "iterator in map" << endl;
    for(auto i=hs.begin(); i!=hs.end(); i++)
    {
        cout << i->first << ", " << i->second << endl; 
    }
    // key들이 정렬되어 있지 않
}

```

### 12-2. **value값을 기준으로 정렬**
```cpp
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(pair<string, int>& a, pair<string, int>& b)
{
    return a.second < b.second;
}

int main()
{
    unordered_map<string, int> map;

    map["a"] = 6;
    map["b"] = 1;
    map["c"] = 4;
    map["d"] = 8;

    vector<pair<string, int>> vec(map.begin(), map.end()); // map을 vector로 변경
    sort(vec.begin(), vec.end(), cmp);

    for (auto elem : vec)
    {
        cout << elem.first << endl;
    }
}
```

### 13.  **Minimum Spanning Tree**
```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
ll p[12000];
 
ll find(ll v)
{
    if (p[v] == v) return v;
    else return p[v] = find(p[v]);
}
 
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll v, e; cin >> v >> e;
    vector<pair<ll, pll>> graph;
    for (ll i = 1; i <= v; i++) p[i] = i;
    for (ll i = 0; i < e; i++)
    {
        ll u, v, w; cin >> u >> v >> w;
        graph.push_back({ w, { u, v } });
    }
    sort(graph.begin(), graph.end());
    ll ans = 0;
    for (ll i = 0; i < e; i++)
    {
        ll w = graph[i].first;
        ll u = graph[i].second.first;
        ll v = graph[i].second.second;
        u = find(u); v = find(v);
        if (u == v) continue;
        ans += w; p[u] = v;
    }
    cout << ans;
}
```

### 14.  **Palindrome**
```cpp
// C++ program to check whether the given string
// is palindrome or not using reverse() function
#include <bits/stdc++.h>
using namespace std;

void isPalindrome(string str) {
  
      // Stores the reverse of the string s
    string rev = str;

    // Reverse the string
    reverse(rev.begin(), rev.end());

    // If rev is equal to str
    if (str == rev)
        cout << "\"" << str
          << "\" is palindrome." << endl;
      
    // If rev is NOT equal to str
    else
        cout << "\"" << str
          << "\" is NOT palindrome." << endl;
}

int main() {
    
      // Checking if strings given strings are palindrome
    isPalindrome("ABCDCBA");
      isPalindrome("ABCD");

    return 0;
}
```

### 15. **Segement Tree**
```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
#define INF 1000000007
int h = 1;
int segTree[2500][2500];
 
void update(int x1, int y1, ll val)
{
    int i = x1 + h - 1, j = y1 + h - 1;
    segTree[i][j] = val;
    while (i > 1)
    {
        i /= 2;
        segTree[i][j] = segTree[i * 2][j] + segTree[i * 2 + 1][j];
    }
    while (j > 1)
    {
        i = x1 + h - 1;
        j /= 2;
        segTree[i][j] = segTree[i][j * 2] + segTree[i][j * 2 + 1];
        while (i > 1)
        {
            i /= 2;
            segTree[i][j] = segTree[i * 2][j] + segTree[i * 2 + 1][j];
        }
    }
    return;
}
 
int getY(int xptr, int yptr, int s, int e, int y1, int y2)
{
    if (y2 < s || e < y1) return 0;
    if (y1 <= s && e <= y2) return segTree[xptr][yptr];
    return getY(xptr, yptr * 2, s, (s + e) / 2, y1, y2)
        + getY(xptr, yptr * 2 + 1, (s + e) / 2 + 1, e, y1, y2);
}
 
int getX(int xptr, int s, int e, int x1, int x2, int y1, int y2)
{
    if (x2 < s || e < x1) return 0;
    if (x1 <= s && e <= x2) return getY(xptr, 1, 1, h, y1, y2);
    return getX(xptr * 2, s, (s + e) / 2, x1, x2, y1, y2)
        + getX(xptr * 2 + 1, (s + e) / 2 + 1, e, x1, x2, y1, y2);
}
 
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m; cin >> n >> m;
    while (h < n) h <<= 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int a; cin >> a;
            update(i, j, a);
        }
    }
    for (int i = 0; i < m; i++)
    {
        int w; cin >> w;
        if (w == 0)
        {
            int x, y, c; cin >> x >> y >> c;
            update(x, y, c);
        }
        else
        {
            int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
            cout << getX(1, 1, h, x1, x2, y1, y2) << "\n";
        }
    }
}
```

### 16. **dp_opt**
```cpp
/*
Conditions
1) DP 점화식 꼴
D[t][i]=min{k<i}(D[t?1][k]+C[k][i])
2) A[t][i]는 D[t][i]를 만족시키는 최소 k라 할 때 아래 부등식을 만족
A[t][i]≤A[t][i+1]
혹은 비용 C에 대해 C[a][c]+C[b][d]<=C[a][d]+C[b][c]
*/

void do_dp(int t, int s, int e, int p, int q) {
    // D[t][s], D[t][s+1], ..., D[t][e]를 계산하는 함수.
    // (여기서 가능한 k의 범위는 p~q 사이)
 
    if (s > e) return;
 
    int m = (s+e) >> 1;
    // 1. D[t][m]에 대해 가능한 답을 선형 시간에 계산
    D[t][m] = 2e9;
    for (int k=p;k<=q&&k<m;k++){
        int v = D[t-1][k] + C[k][m];
        if (D[t][m] > v)
            D[t][m] = v, K[t][m] = k;
    }
    // 2. D[t][s], ..., D[t][m-1]에 대해서 계산하기 위한 재귀 호출
    do_dp(t, s, m-1, p, K[t][m]);
    // 3. D[t][m+1], ..., D[t][e]에 대해서 계산하기 위한 재귀 호출
    do_dp(t, m+1, e, K[t][m], q);
 
    // 2, 3에 대해 가능한 k의 후보는 조건에 의해 줄어든다.
}
```

### 17. **merge sort**
```cpp
template <typename T>
bool default_compare(T a, T b) {
	return a < b;
}

template <typename T> void merge_sort(T* st, T* en, bool(*cmp)(T, T) = default_compare) {
	int N = en - st;
	if (N <= 1) return;

	int M = N / 2;
	merge_sort(st, st + M, cmp);
	merge_sort(st + M, en, cmp);

	T* u = new T[N + 1];

	int p1 = 0, p2 = M, p = 0;
	while (p1 < M && p2 < N) {
		if (cmp(st[p1], st[p2])) u[p++] = *(st + p1++);
		else u[p++] = *(st + p2++);
	}
	while (p1 < M) u[p++] = *(st + p1++);
	while (p2 < N) u[p++] = *(st + p2++);
	for (int i = 0; i < N; i++) *(st + i) = u[i];

	delete[] u;
	return;
}
```

### 18. **myswap**
```cpp
template <typename T> void myswap(T &a, T &b) {
	T tmp = a; a = b; b = tmp;
}
```

### 19. **vector**
```cpp
template <class T> class vector {
public:
	int sz, max_size;
	T* arr;
	vector<T>() {
		sz = 0;
		max_size = 4;
		arr = new T[max_size];
	}
	~vector<T>() { delete[] arr; }
	void push_back(T a) {
		if (sz == max_size) {
			T* tarr = new T[max_size + max_size];
			max_size += max_size;
			for (int i = 0; i < sz; i++) tarr[i] = arr[i];
			delete[] arr;
			arr = tarr;
		}
		arr[sz++] = a;
	}
	void pop_back() { if (sz > 0) sz--; }
	int size() { return sz; }
	bool empty() { return sz == 0; }
	void clear() { sz = 0; }
	T &operator[](int idx) { return arr[idx]; }
};
```
### 20. **suffix array**
```cpp
const int MAXN = 500005;
struct SuffixArray {
	/*
	m : number of alphabet, n : string length
	sa[] : 0 ~ n-1(th) suffix sorting number (starting from 1)
	h[] : adjenct sa's lcp(starting from 2)
	rank[] : 0~n-1(th) suffix's rank (starting from 0)
	ex) banana
	*suffix number
	banana	0
	anana	1
	nana	2
	ana		3
	na		4
	a		5
	*rank[]
	banana	3
	anana	2
	nana	5
	ana		1
	na		4
	a		0
	*sa[]
	a		5
	ana		3
	anana	1
	banana	0
	na		4
	nana	2
	*/
	int n, m, i, j, k, r[MAXN], sa[MAXN], rank[MAXN], h[MAXN], A[MAXN], B[MAXN], V[MAXN], S[MAXN], T;
	void read(char* S) {
		m = 27;
		for (i = 0; S[i]; i++) r[i] = S[i]-'a'+1;
		n = i;
	}
	inline bool cmp(int a, int b, int l) { return B[a] == B[b] && B[a+l] == B[b+l]; }
	void calcSuffixArray(int n) {
		int p;
		for (i = 0; i < m; i++) S[i] = 0;
		for (i = 0; i < n; i++) S[A[i] = r[i]]++;
		for (i = 1; i < m; i++) S[i]+=S[i-1];
		for (i = n-1; i >= 0; i--) sa[--S[A[i]]] = i;
		for (j = 1, p = 1; p<n; j <<= 1, m = p) {
			for (p = 0, i = n-j; i < n; i++) B[p++] = i;
			for (i = 0; i < n; i++) if(sa[i] >= j) B[p++] = sa[i]-j;
			for (i = 0; i < m; i++) S[i] = 0;
			for (i = 0; i < n; i++) S[V[i] = A[B[i]]]++;
			for (i = 1; i < m; i++) S[i]+=S[i-1];
			for (i = n-1; i >= 0; i--) sa[--S[V[i]]] = B[i];
			for (i = 0; i < n; i++) T=A[i],A[i]=B[i],B[i]=T;
			p = 1, A[sa[0]] = 0;
			for (i = 1; i < n; i++) A[sa[i]] = cmp(sa[i-1], sa[i], j) ? p-1 : p++;
		}
	}
	void calcLCP() {
		k = 0;
		for (i = 1; i <= n; i++) rank[sa[i]] = i;
		for (i = 0; i < n; h[rank[i++]] = k) for (k?k--:0, j = sa[rank[i]-1]; r[i+k] == r[j+k]; k++);
	}
	void solve() {
		calcSuffixArray(n+1);
		calcLCP();
		for (i = 1; i <= n; i++) printf("%d ",sa[i]);
		printf("\nx ");
		for (i = 2; i <= n; i++) printf("%d ",h[i]);
	}
} A;
int main() {
	char S[MAXN];
	fgets(S, MAXN, stdin);
	A.read(S); A.solve();
}
```

### 21. **basic arithmetic**
```cpp
typedef long long ll;
typedef unsigned long long ull;

// calculate lg2(a)
inline int lg2(ll a) {
    return 63 - __builtin_clzll(a);
}

// calculate the number of 1-bits
inline int bitcount(ll a) {
    return __builtin_popcountll(a);
}

// calculate ceil(a/b)
// |a|, |b| <= (2^63)-1 (does not dover -2^63)
ll ceildiv(ll a, ll b) {
    if (b < 0) return ceildiv(-a, -b);
    if (a < 0) return (-a) / b;
    return ((ull)a + (ull)b - 1ull) / b;
}

// calculate floor(a/b)
// |a|, |b| <= (2^63)-1 (does not cover -2^63)
ll floordiv(ll a, ll b) {
    if (b < 0) return floordiv(-a, -b);
    if (a >= 0) return a / b;
    return -(ll)(((ull)(-a) + b - 1) / b);
}

// calculate a*b % m
// x86-64 only
ll large_mod_mul(ll a, ll b, ll m) {
    return ll((__int128)a*(__int128)b%m);
}

// calculate a*b % m
// |m| < 2^62, x86 available
// O(logb)
ll large_mod_mul(ll a, ll b, ll m) {
    a %= m; b %= m; ll r = 0, v = a;
    while (b) {
        if (b&1) r = (r + v) % m;
        b >>= 1;
        v = (v << 1) % m;
    }
    return r;
}

// calculate n^k % m
ll modpow(ll n, ll k, ll m) {
    ll ret = 1;
    n %= m;
    while (k) {
        if (k & 1) ret = large_mod_mul(ret, n, m);
        n = large_mod_mul(n, n, m);
        k /= 2;
    }
    return ret;
}

// calculate gcd(a, b)
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

// find a pair (c, d) s.t. ac + bd = gcd(a, b)
pair<ll, ll> extended_gcd(ll a, ll b) {
    if (b == 0) return { 1, 0 };
    auto t = extended_gcd(b, a % b);
    return { t.second, t.first - t.second * (a / b) };
}

// find x in [0,m) s.t. ax === gcd(a, m) (mod m)
ll modinverse(ll a, ll m) {
    return (extended_gcd(a, m).first % m + m) % m;
}

// calculate modular inverse for 1 ~ n
void calc_range_modinv(int n, int mod, int ret[]) {
    ret[1] = 1;
    for (int i = 2; i <= n; ++i)
        ret[i] = (ll)(mod - mod/i) * ret[mod%i] % mod;
}
```

### 22. **kmp**
```cpp
vector<ll> MakeTable(string p)
{
    ll psize = p.size();
    vector<ll> table(psize, 0);
    ll j = 0;
    for (ll i = 1; i < psize; i++)
    {
        while (j != 0 && p[i] != p[j])
            j = table[j - 1];
        if (p[i] == p[j])
            table[i] = ++j;
    }
    return table;
}
 
void KMP(string t, string p)
{
    ll tsize = t.size(), psize = p.size();
    vector<ll> table = MakeTable(p);
    ll j = 0;
    for (ll i = 0; i < tsize; i++)
    {
        while (j != 0 && t[i] != p[j])
            j = table[j - 1];
        if (t[i] == p[j])
        {
            if (j == psize - 1)
            {
                ans++;
                pos.push_back(i - psize + 2);
                j = table[j];
            }
            else
                j++;
        }
    }
}
 
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    getline(cin, t);
    getline(cin, p);
    KMP(t, p);
    cout << ans << "\n";
    for (ll to : pos) cout << to << "\n";
}
```
