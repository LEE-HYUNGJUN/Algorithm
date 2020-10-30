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

bool binary_search(int *arr, int len, int key) {
	int start = 0;
	int end = len - 1;
	int mid;

	while (end - start >= 0) {
		mid = (start + end) / 2;

		if (arr[mid] == key)
			return true;
		else if (arr[mid] > key)
			end = mid - 1;
		else
			start = mid + 1;
	}
	return false;
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	vector<string> v;
	vector<string> v_result;

	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	string str;
	for (int j = 0; j < m; j++) {
		cin >> str;

		if (binary_search(v.begin(), v.end(), str)) {
			v_result.push_back(str);
		}
	}

	sort(v_result.begin(), v_result.end());
	
	printf("%d\n", (int)v_result.size());
	for (int i = 0; i < v_result.size(); i++) {
		printf("%s\n", v_result[i].c_str());
	}
	return 0;
}