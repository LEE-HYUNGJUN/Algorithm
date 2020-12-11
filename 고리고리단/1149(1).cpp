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
int dp[1001][3], rgb[1001][3];
int r, g, b=0;
int R, G, B;

int main() {
	
	scanf("%d", &n);

	/*for (int i = 1; i <= n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &rgb[i][j]);
		}
	}
	for (int i = 0; i < 3; i++)
		dp[1][i] = rgb[1][i];
	for (int i = 2; i <= n; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + rgb[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + rgb[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + rgb[i][2];
	}
	printf("%d\n", min(min(dp[n][0],dp[n][1]),dp[n][2]));
	*/
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &R, &G, &B);

		R += min(g, b);
		G += min(r, b);
		B += min(r, g);

		r = R;
		g = G;
		b = B;
	}

	printf("%d\n", min(min(r, g), b));

	return 0;
}