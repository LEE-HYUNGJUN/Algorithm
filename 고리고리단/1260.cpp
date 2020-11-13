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

int n, m, v;
vector<vector<int>> adj;
int check_dfs[1001];
int check_bfs[1001];

void dfs(int u) {
	check_dfs[u] = 1;
	printf("%d ", u);
	for (int i = 0; i < adj[u].size(); i++)
	{
		if (check_dfs[adj[u][i]] == 0) {
			dfs(adj[u][i]);
		}
	}
}
void bfs(int u) {
	queue<int> q;
	q.push(u);
	check_bfs[u] = 1;

	while (!q.empty()) {
		u = q.front();
		printf("%d ", u);
		q.pop();

		for (int i = 0; i < adj[u].size(); i++)
		{
			if (check_bfs[adj[u][i]] == 0)
			{
				check_bfs[adj[u][i]] = 1;
				q.push(adj[u][i]);
			}
		}
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &v);
	adj.resize(n + 1);
	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for(int i=1;i<=n;i++)
	sort(adj[i].begin(), adj[i].end());

	dfs(v);
	printf("\n");
	bfs(v);
	return 0;
}