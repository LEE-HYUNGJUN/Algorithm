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

vector <vector<int>> adj;
int check_bfs[101];
int n, m, v;
int cnt = 0;

void bfs(int v)
{
	queue<int> q;
	q.push(v);
	check_bfs[v] = 1;

	while (!q.empty()) {
		v = q.front();
		q.pop();
		cnt++;

		for (int i = 0; i < adj[v].size(); i++) {
			if (check_bfs[adj[v][i]] == 0){
				q.push(adj[v][i]);
				check_bfs[adj[v][i]] = 1;
			}
		}
	}
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	adj.resize(n + 1);

	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
		sort(adj[i].begin(), adj[i].end());

	bfs(1);
	printf("%d\n", cnt-1);
	return 0;
}