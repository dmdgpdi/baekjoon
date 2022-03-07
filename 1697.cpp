#include<iostream>
#include<queue>

using namespace std;

int visit[100002];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;

	fill(visit, visit + 100001, -1);

	cin >> n >> k;

	queue<int>q;
	q.push(n);
	visit[n] = 0;

	while(visit[k] == -1)
	{
		int cur = q.front(); q.pop();

		for (int i : {cur - 1, cur + 1,  cur*2}) {
			if (i < 0 || i>100000)
				continue;
			if (visit[i] != -1)
				continue;

			visit[i] = visit[cur] + 1;
			q.push(i);
		}
	}

	cout << visit[k];
}