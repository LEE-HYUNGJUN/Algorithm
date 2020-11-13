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

map<char, int> m;
char arr[21][21];
int R, C;
int cnt = 1;
int dr[4] = {-1,1,0,0};
int dc[4] = {0,0,-1,1};

void dfs(int r, int c,int count) {
	m[arr[r][c]] = 1;

	if (cnt < count)
		cnt = count;

	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];

		if ((0 < nr && nr <= R) && (0 < nc && nc <= C)) {
			if (m[arr[nr][nc]] != 1) {
				m[arr[nr][nc]] = 1;
				dfs(nr, nc,count +1);
				m[arr[nr][nc]] = 0;
			}
		}
	}
	return;
}
int main() {
	scanf("%d %d", &R, &C);

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> arr[i][j];
		}
	}

	dfs(1, 1,1);

	printf("%d\n", cnt);
	return 0;
}