#include<iostream>
#include<queue>

using namespace std;

int board[303][303];
int visit[303][303];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int c, r;

int countBfs(int x,int y) {
	queue<pair<int, int>> cq;
	visit[x][y] = 1;
	cq.push({ x,y });

	while (!cq.empty())
	{
		pair<int, int>cur = cq.front(); cq.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (nx < 0 || nx >= c || ny < 0 || ny>=r)
				continue;
			if (board[nx][ny] == 0 || visit[nx][ny] > 0)
				continue;

			visit[nx][ny] = 1;
			cq.push({ nx,ny });

		}

	}

	return 0;
}

int main() {
	
	int num;
	bool check = true;
	int counter = 0;
	int repet = 0;

	cin >> c >> r;

	queue<pair<int, int>>q;

	for (int i = 0; i < c; i++) {
		for (int j = 0; j < r; j++) {
			cin >> num;
			board[i][j] = num;

			if (num == 0) {
				q.push({ i,j });
			}
		}
	}

	while (check) {
		for (int i = 0; i < c; i++) {
			for (int j = 0; j < r; j++) {
				if (board[i][j] > 0 && visit[i][j] == 0) {
					countBfs(i, j);
					counter++;
				}
			}
		}

		if (counter > 1)
			break;

		counter = 0;
		repet++;

		// 카운터가 2보다 크다면 반복할 필요 x

			//녹이기
		while (!q.empty())
		{
			pair<int, int>cur = q.front(); q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = cur.first + dx[i];
				int ny = cur.second + dy[i];

				if (nx < 0 || nx >= c || ny < 0 || ny >= r)
					continue;
				if (board[nx][ny] == 0)
					continue;

				board[nx][ny] = board[nx][ny] - 1;

			}
		}

		check = false; // 다 녹았는지.

		for (int i = 0; i < c; i++) {
			for (int j = 0; j < r; j++) {
				if (board[i][j] > 0) {
					check = true;
				}
				else {
					q.push({ i,j });
				}
			}
		}

		for (int i = 0; i < c; i++) {
			fill(visit[i], visit[i] + r, 0);
		}
		
		//cout << endl;
		//for (int i = 0; i < c; i++) {
		//	for (int j = 0; j < r; j++) {
		//		cout << board[i][j] << " ";
		//	}
		//	cout << endl;
		//}

	}


	if (counter > 1) {
		cout << repet << endl;
	}
	else if (check == false) {
		cout << 0 << endl;
	}
}