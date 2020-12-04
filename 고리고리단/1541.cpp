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


int main() {
	string str;
	cin >> str;

	int num = 0;
	int ans = 0;
	int flag = 1;

	for (char c : str) {
		if (c == '+') {
			ans += num;
			num = 0;
		}
		else if (c == '-') {
			flag = -1;
			ans += num;

			num = 0;
		}
		else {
			num = num * 10 + (c - '0')*flag;
		}
	}

	ans += num;

	printf("%d\n", ans);

	return 0;
}