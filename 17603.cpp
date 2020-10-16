
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>
#include <string.h>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	stack<int> st;

	for (int i = 0; i < n; i++) {
		int h;
		scanf("%d", &h);
		st.push(h);
	}
	int max = -1;
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		int com = st.top();
		if (com > max) {
			cnt++;
			max = com;
		}
		st.pop();
	}

	printf("%d\n", cnt);

	return 0;
}