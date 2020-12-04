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
int n, arr[1001];

int main() {
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);

	int max = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > max + 1) {
			break;
		}
		max += arr[i];
	}
	printf("%d\n", max + 1);
	return 0;
}