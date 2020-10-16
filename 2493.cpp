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

int main() {
	int tc,k;
	stack<pair<int, int>> st;
	scanf("%d", &tc);

	for (int i = 1; i <= tc; i++) {
		scanf("%d", &k);
		while (!st.empty()) {

			if (st.top().second > k) {
				printf("%d ", st.top().first);
				break;
			}
			st.pop();
		}
		if (st.empty()) {
			printf("0 ");
		}
		st.push({ i,k });
	}

	return 0;
}