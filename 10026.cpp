#include<iostream>
#include<queue>

using namespace std;

char board[101][101];
int	 visit[101][101];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int counter = 0;
int n;

void bfs(int x, int y) {
	queue<pair<int, int>>q;
	q.push({x,y});
	visit[x][y] = 1;
	char target = board[x][y];

	while (!q.empty()) {
		pair<int, int>cur = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (nx < 0 || nx>=n || ny < 0 || ny>=n)
				continue;
			if (board[nx][ny] != target || visit[nx][ny] == 1)
				continue;

			q.push({ nx,ny });
			visit[nx][ny] = 1;
		}
	}
	counter++;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j] == 0) {
				bfs(i, j);
			}
		}
	}

	const int num1 = counter;
	counter = 0;

	for (int i = 0; i < n; i++) {
		fill(visit[i], visit[i] + n, 0);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 'G') {
				board[i][j] = 'R';
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j] == 0) {
				bfs(i, j);
			}
		}
	}

	const int num2 = counter;

	cout << num1 << " " << num2 << endl;


}