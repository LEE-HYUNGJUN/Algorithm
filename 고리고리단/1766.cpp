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

int n, m;
priority_queue <int, vector<int>, greater<int>> pq;
vector <vector<int>> v;
int arr[32001];
int main() {
	scanf("%d %d", &n, &m);
	v.resize(n + 1);

	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		arr[b]++;
	}

	for (int i = 1; i <= n; i++) {
		if (arr[i] == 0) {
			pq.push(i);
		}
	}
	while (!pq.empty()) {
		int top = pq.top();
		pq.pop();

		printf("%d ", top);
		
		for (int i = 0; i < v[top].size(); i++) {
			int next = v[top][i];
			arr[next]--;

			if (arr[next] == 0)
				pq.push(next);
		}
	}
	return 0;
}