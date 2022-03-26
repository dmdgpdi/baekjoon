#include<iostream>
#include<queue>
#include<tuple>
using namespace std;

char board[1001][1001];
int visit[1001][1001][2];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1,0,-1,0 };

int r, c;


int bfs() {
	queue<tuple<int, int, int>> q;
	q.push({ 0,0,0 });
	visit[0][0][0] = visit[0][0][1] = 1;

	while (!q.empty())
	{
		int x, y, wall;
		tie(x, y, wall) = q.front(); q.pop();

		if (x == c - 1 && y == r - 1) {
			return visit[x][y][wall];
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];


			if (nx < 0 || nx >= c || ny < 0 || ny >= r) {
				continue;
			}
			if (board[nx][ny] == '0' && visit[nx][ny][wall] == -1) {
				q.push({ nx,ny,wall });
				visit[nx][ny][wall] = visit[x][y][wall] + 1;
			}
			if (!(wall) && board[nx][ny] == '1' && visit[nx][ny][1] == -1) {
				q.push({ nx,ny,1 });
				visit[nx][ny][1] = visit[x][y][0] + 1;
			}


		}
	}
	return -1;

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> c >> r;

	for (int i = 0; i < c; i++) {
		for (int j = 0; j < r; j++) {
			cin >> board[i][j];
			visit[i][j][0] = visit[i][j][1] = -1;
		}
	}

	int result = bfs();
	cout << result << endl;
}
