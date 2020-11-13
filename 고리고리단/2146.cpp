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

int n;
int k = 2;
int ans = 987654321;
int arr[101][101];
int dist[101][101];
int check[101][101];

int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };

// bfs,dfs 둘 다 상관없음
void dfs(int r, int c) {
	queue<pair<int, int>> dq;
	dq.push(make_pair(r, c));
	arr[r][c] = k;
	check[r][c] = 1;

	while (!dq.empty()) {
		r = dq.front().first;
		c = dq.front().second;
		dq.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			/*if ((0 <= nr && nr < n) && (0 <= nc && nc < n)) {
				if (check[nr][nc] == 0 && arr[nr][nc] == 1)
					dfs(nr, nc);
			}*/
			if ((0 <= nr && nr < n) && (0 <= nc && nc < n)) {
				if (arr[nr][nc] == 1 && check[nr][nc] == 0) {
					check[nr][nc] = 1;
					arr[nr][nc] = k;
					dq.push(make_pair(nr, nc));
				}
			}
		}
	}
}

void bfs(int k) {
	queue<pair<int, int>> q;
	memset(dist, -1, sizeof(dist));
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == k) {
				q.push(make_pair(i, j));
				dist[i][j] = 0;
			}
		}
	}
	

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			/*if ((0 <= nr && nr < n) && (0 <= nc && nc < n)) {
				if (arr[nr][nc] == 0) {
					q.push(make_pair(nr, nc));
					arr[nr][nc] = arr[r][c];
					dist[nr][nc] = dist[r][c] + 1;
				}
				else if (arr[nr][nc] != arr[r][c] && dist[r][c] + dist[nr][nc] <ans) {
					ans = dist[r][c] + dist[nr][nc];
				}
			}*/

			if ((nr < 0 || nr >= n) || (nc < 0 || nc >= n))
				continue;
			// 다른 섬에 도착했을경우의 최소거리 지정
			if (arr[nr][nc] && arr[nr][nc] != k) {
				if (ans > dist[r][c])
					ans = dist[r][c];
				return;
			}
			// 섬 끝에서 이동하는 경우
			if (arr[nr][nc] == 0 && dist[nr][nc] == -1) {
				q.push(make_pair(nr, nc));
				dist[nr][nc] = dist[r][c] + 1;
			}

		}
			
	}
}

int main() {
	scanf("%d", &n);

	memset(arr, 0, sizeof(arr));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1) {
				dfs(i, j);
				k++;
			}
		}
	}

	for (int i = 2; i < k; i++) {
		bfs(i);
	}

	printf("%d\n", ans);
	
	return 0;
}
