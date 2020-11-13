#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
#include <map>

using namespace std;

int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };
int arr[51][51];
int check[51][51];
int t, m, n, k;
int cnt = 0;

void bfs(int r, int c) {
	queue<pair<int, int>> q;
	q.push(make_pair(r, c));
	check[r][c] = 1;


	while (!q.empty()) {
		r = q.front().first;
		c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if ((0 <= nr && nr < n) && (0 <= nc && nc < m))
			{
				if (check[nr][nc] == 0 && arr[nr][nc] == 1) {
					q.push(make_pair(nr, nc));
					check[nr][nc] = 1;
				}
			}
		}
	}
	cnt++;
}
int main() {

	scanf("%d", &t);

	while (t--) {
		scanf("%d %d %d", &m, &n, &k);
		for (int i = 0; i < 51; i++) {
			for (int j = 0; j < 51; j++) {
				check[i][j] = 0;
				arr[i][j] = 0;
			}
		}
		for (int i = 0; i < k; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			arr[b][a] = 1;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 1 && check[i][j] == 0)
					bfs(i, j);
			}
		}
		printf("%d\n", cnt);
		cnt = 0;
	}


	return 0;
}