#include<iostream>
#include<queue>

using namespace std;

int board[1000][1000];
int visit[1000][1000];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int col, row;
	int value = 0;
	bool check = false;

	cin >> row >> col;

	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			cin >> board[i][j];
			visit[i][j] = -1;
		}
	}

	queue<pair<int, int>>q;

	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			if (board[i][j] == 1) {
				q.push({ i,j });
				visit[i][j] = 0;
			}
			else {
				check = true;
			}
		}
	}

	if (check == false) {
		cout <<0 << endl;
		return 0;
	}

	while (!q.empty())
	{
		pair<int, int> cur = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx < 0 || nx >= col || ny < 0 || ny >= row) {
				continue;
			}
			if (board[nx][ny] == -1 || visit[nx][ny] > -1)
				continue;

			visit[nx][ny] = visit[cur.first][cur.second]+1;
			q.push({ nx,ny });
			value = visit[cur.first][cur.second] + 1;
		}

	}

	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			if (visit[i][j] == -1 && board[i][j] != -1) {
				cout << -1 << endl;
				return 0;
			}
		}
	}

	cout << value << endl;

}
