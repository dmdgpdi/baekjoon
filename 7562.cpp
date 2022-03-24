#include<iostream>
#include<queue>

using namespace std;

int board[301][301];
int visit[301][301];

int dy[8] = { 1,1,-1,-1,2,2,-2,-2 };
int dx[8] = { 2,-2,2,-2,1,-1,1,-1 };

int main() {
	int repet;
	int size;

	cin >> repet;
	int x, y;

	queue<pair<int, int>>q;

	for (int i = 0; i < repet; i++) {
		cin >> size;
		cin >> x >> y;
		int result = 0;

		q.push({ x,y });

		for (int i = 0; i < size; i++) {
			fill(visit[i], visit[i] + size, -1);
		}

		visit[x][y] = 0;

		cin >> x >> y;

		while (!q.empty()) {
			pair<int, int> cur = q.front(); q.pop();

			for (int i = 0; i < 8; i++) {
				int nx = cur.first + dx[i];
				int ny = cur.second + dy[i];

				if (nx < 0 || nx >= size || ny < 0 || ny >= size)
					continue;
				if (visit[nx][ny] > -1)
					continue;

				visit[nx][ny] = visit[cur.first][cur.second] + 1;
				q.push({ nx,ny });
			}
		}
		cout << visit[x][y] << endl;

		
	}
}