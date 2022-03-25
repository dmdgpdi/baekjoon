#include<iostream>
#include<queue>

using namespace std;

int board[1003][1003];
int vis_s[1003][1003];
int vis_f[1003][1003];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	int r;
	cin >> r;

	for (int l = 0; l < r; l++) {
		int row, col;
		cin >> row >> col;
		queue<pair<int, int>>qs, qf;

		for (int i = 0; i < col; i++) {
			fill(vis_f[i], vis_f[i] + row, 0);
			fill(vis_s[i], vis_s[i] + row, 0);
		}

		for (int i = 0; i < col; i++) {
			for (int j = 0; j < row; j++) {
				char c;
				cin >> c;

				if (c == '#') {
					board[i][j] = -1;
				}
				else {
					if (c == '@') {
						vis_s[i][j] = 1;
						qs.push({ i,j });
					}
					else if (c == '*') {
						vis_f[i][j] = 1;
						qf.push({ i,j });
					}
					board[i][j] = 0;
				}
			}
		}

		while (!qf.empty())
		{
			pair<int,int> cur = qf.front(); qf.pop();
			for (int i = 0; i < 4; i++) {
				int nx = cur.first + dx[i];
				int ny = cur.second + dy[i];

				if (nx < 0 || nx >= col || ny < 0 || ny >= row)
					continue;
				if (board[nx][ny] == -1 || vis_f[nx][ny]>0)
					continue;

				qf.push({ nx,ny });
				vis_f[nx][ny] = vis_f[cur.first][cur.second] + 1;
			}

		}

		bool check = false;

		while (!qs.empty() && (!check))
		{
			pair<int, int> cur = qs.front(); qs.pop();
			for (int i = 0; i < 4; i++) {
				int nx = cur.first + dx[i];
				int ny = cur.second + dy[i];

				if (nx < 0 || nx >= col || ny < 0 || ny >= row) {
					cout << vis_s[cur.first][cur.second] << endl;
					check = true;
					break;
				}
				if (board[nx][ny] == -1 || vis_s[nx][ny]>0)
					continue;
				if (vis_f[nx][ny] != 0 && vis_f[nx][ny] <= vis_s[cur.first][cur.second] + 1)
					continue;

				qs.push({ nx,ny });
				vis_s[nx][ny] = vis_s[cur.first][cur.second] + 1;
			}

		}
		if (!check)
			cout << "IMPOSSIBLE" << endl;

	}
}