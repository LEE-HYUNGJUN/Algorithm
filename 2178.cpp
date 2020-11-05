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

int dr[4] = { -1,1,0,0 }; //»óÇÏÁÂ¿ì
int dc[4] = { 0,0,-1,1 };
int arr[101][101];
int darr[101][101];
int check[101][101];
int cnt = 0, num = 0;
int n, m;

void bfs(int r, int c)
{
	queue<pair<int, int>> q;
	q.push(make_pair(r, c));
	darr[r][c] = ++cnt;
	check[r][c] = 1;

	while (!q.empty())
	{
		r = q.front().first;
		c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if ((0 <= nr && nr < n) && (0 <= nc && nc < m)) {
				if (check[nr][nc] == 0 && arr[nr][nc] == 1) 
				{
					q.push(make_pair(nr, nc));
					check[nr][nc] = 1;
					darr[nr][nc] = darr[r][c] + 1;
				}
			}
		}
	}
}
int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	bfs(0, 0);
	printf("%d\n", darr[n - 1][m - 1]);
	
	return 0;
}