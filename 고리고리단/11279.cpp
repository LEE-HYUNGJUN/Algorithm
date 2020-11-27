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
priority_queue<int, vector<int>> pq;
int n, x;
int main() {
	scanf("%d", &n);

	while (n--) {
		scanf("%d", &x);
		if (x == 0) {
			if (pq.empty()) {
				printf("0\n");
			}
			else {
				printf("%d\n", pq.top());
				pq.pop();
			}
		}
		else {
			pq.push(x);
		}
	}


	return 0;
}