#include<iostream>
#include<queue>
#include<string>

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

char board[26][26];
int visit[26][26];
int count = 0;
int n;

using namespace std;

int bfs(int x,int y) {
	queue<pair<int, int>>q;
	q.push({ x,y });
	::count++;
	visit[x][y] = 1;
	int size = 1;

	while (!q.empty()) {
		pair<int, int>cur = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.first + ::dx[i];
			int ny = cur.second + ::dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				continue;
			if (::board[nx][ny] == '0' || visit[nx][ny] > 0)
				continue;

			q.push({ nx,ny });
			visit[nx][ny] = 1;
			size++;
		}
	}

	return size;
}

int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> ::board[i];

	}

	priority_queue<int, vector<int>, greater<int>>pq;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (::board[i][j] == '1' && visit[i][j] == 0) {
				pq.push(bfs(i, j));
			}
		}
	}

	cout << ::count << endl;

	while (!pq.empty()) {
		cout << pq.top() << endl;
		pq.pop();
	}
}