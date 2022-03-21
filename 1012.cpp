#include<iostream>
#include<queue>

using namespace std;

int board[50][50];
int visit[50][50];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int row, col;
int count = 0;

void bfs( int i, int j) {
	if (visit[i][j] == 1)
		return;
	else {
		//cout << i << " " << j << endl;
		queue<pair<int, int>>q;
		q.push({ i,j });
		visit[i][j] = 1;

		while (!q.empty()) {
			pair<int, int> cur = q.front(); q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = cur.first + dx[i];
				int ny = cur.second + dy[i];

				if (nx < 0 || nx >= col || ny < 0 || ny >= row)
					continue;
				if (visit[nx][ny] == 1 || board[nx][ny] == 0)
					continue;

				visit[nx][ny] = 1;
				q.push({ nx,ny });
			}
		}
		::count++;
	}
}

int main() {
	int repet, x,y,k;

	cin >> repet;

	for (int i = 0; i < repet; i++) {
		cin >> row >> col >> k;
		for (int j = 0; j < k; j++) {
			cin >> x >> y;
			board[y][x] = 1;
		}

		for (int j = 0; j < col; j++) {
			for (int t = 0; t < row; t++) {
				if (board[j][t] == 1) {
					bfs(j, t);
				}
			}
		}

		cout << ::count << endl;
		::count = 0;
		for (int j = 0; j < col; j++) {
			fill(board[j], board[j] + row, 0);
			fill(visit[j], visit[j] + row, 0);
		}
	}
}