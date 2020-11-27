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
priority_queue <long long, vector<long long>,greater<long long>> pq;
int n, m;
long long ans=0;


int main() {
	scanf("%d %d", &n, &m);
	
	while (n--) {
		int a;
		scanf("%d", &a);
		pq.push(a);
	}

	while (m--) {
		long long a = pq.top();
		pq.pop();
		long long b = pq.top();
		pq.pop();
		pq.push(a + b);
		pq.push(a + b);
	}
	while (!pq.empty()) {
		ans += pq.top();
		pq.pop();
	}
	printf("%lld\n", ans);
	return 0;
}