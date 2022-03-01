#include<iostream>
#include<queue>

using namespace std;

string board[100];
int visit[100][100];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

//col first row second

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<pair<int, int>>q;
	int row, col;

	cin >> col >> row;
	
	for (int i = 0; i < col; i++) {
			cin >> board[i];
	}
	for (int i = 0; i < col; i++) {
		fill(visit[i], visit[i] + row, -1);
	}

	visit[0][0] = 1;
	q.push({ 0,0 });
	
	while (!q.empty())
	{
		pair<int, int>cur = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (nx < 0 || nx >= col || ny < 0 || ny >= row)
				continue;
			if (board[nx][ny] != '1' || visit[nx][ny] != -1)
				continue;

			visit[nx][ny] = visit[cur.first][cur.second] + 1;
			q.push({ nx,ny });
		}

	}

	cout << ::visit[col-1][row-1] << endl;


}