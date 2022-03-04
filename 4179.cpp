#include<iostream>
#include<queue>

using namespace std;

string board[1000];
int visit1[1000][1000];
int visit2[1000][1000];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int col, row;

	cin >> col >> row;

	for (int i = 0; i < col; i++) {
		fill(visit1[i], visit1[i] + row, -1);
		fill(visit2[i], visit2[i] + row, -1);
	}

	for (int i = 0; i < col; i++) {
		cin >> board[i];
	}

	queue<pair<int, int>>q1;
	queue<pair<int, int>>q2;

	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			if (board[i][j] == 'F') {
				q1.push({ i,j });
				visit1[i][j] = 0;
			}
			else if (board[i][j] == 'J') {
				q2.push({ i,j });
				visit2[i][j] = 0;
			}
		}
	}

	

	while (!q1.empty()) {
		pair<int, int> cur = q1.front(); q1.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (nx < 0 || nx >= col || ny < 0 || ny >= row) {
				continue;
			}
			if (board[nx][ny] != '.' || visit1[nx][ny] > -1)
				continue;

			q1.push({ nx,ny });
			visit1[nx][ny] = visit1[cur.first][cur.second] + 1;
		}
	}

	while (!q2.empty()) {
		pair<int, int> cur = q2.front(); q2.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (nx < 0 || nx >= col || ny < 0 || ny >= row) {
				cout << visit2[cur.first][cur.second] + 1 << endl;
				return 0;
			}
			if(board[nx][ny] != '.' || visit2[nx][ny] > -1)
				continue;
			if (visit1[nx][ny] != -1 && visit1[nx][ny] <= visit2[cur.first][cur.second]+1)
				continue;

			q2.push({ nx,ny });
			visit2[nx][ny] = visit2[cur.first][cur.second] + 1;
		}
	}


		cout << "IMPOSSIBLE " << endl;
	
}