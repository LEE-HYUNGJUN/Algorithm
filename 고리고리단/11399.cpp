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
vector<int> v;
int arr[1001];
int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int k;
		scanf("%d", &k);
		v.push_back(k);
	}
	sort(v.begin(), v.end());

	int cnt = v[0];
	arr[0] = v[0];
	for (int i = 1; i < n; i++) {
		cnt += v[i];
		arr[i] = cnt;
	}
	cnt = 0;
	for (int i = 0; i < n; i++) {
		cnt += arr[i];
	}

	printf("%d\n", cnt);
	return 0;
}