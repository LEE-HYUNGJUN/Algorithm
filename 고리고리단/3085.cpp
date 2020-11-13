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

using namespace std;

int ans = 0;
int n;
char arr[51][51];
bool visited[51][51];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int Candy() {
	int res = 0;
	int cnt = 0;
	char pre = '0';

	for (int i = 0; i < n; i++) {
		//행 검사
		cnt = 1;
		pre = arr[0][i];
		for (int j = 1; j < n; j++) {
			if (pre == arr[j][i])
				cnt++;
			else {
				res = max(res, cnt);
				pre = arr[j][i];
				cnt = 1;
			}
		}
		res = max(res, cnt);

		//열 검사
		cnt = 1;
		pre = arr[i][0];
		for (int j = 1; j < n; j++) {
			if (pre == arr[i][j])
				cnt++;
			else {
				res = max(res, cnt);
				pre = arr[i][j];
				cnt = 1;
			}
		}
		res = max(res, cnt);
	}
	return res;
}

int main() {
	
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	
	ans = 0;

	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			int tmp;

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || ny < 0 || nx >= n || ny >= n)
					continue;
				if (visited[x][y] == true) continue;

				//교환
				tmp = arr[x][y];
				arr[x][y] = arr[nx][ny];
				arr[nx][ny] = tmp;

				//최대 사탕개수 파악
				ans = max(ans, Candy());

				//원상복귀
				tmp = arr[x][y];
				arr[x][y] = arr[nx][ny];
				arr[nx][ny] = tmp;
			}
			
			visited[x][y] = true;

		}
	}
	printf("%d\n", ans);

	return 0;

}