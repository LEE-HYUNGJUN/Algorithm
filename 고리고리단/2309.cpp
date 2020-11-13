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
	int arr[9],sum=0;
	int ans1=0, ans2=0;
	
	for (int i = 0; i < 9; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
	}

	sort(arr, arr + 9);
	
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (i == j)
				continue;
			if (sum - arr[i] - arr[j] == 100) {
				ans1 = i;
				ans2 = j;
				break;
			}
		}
	}
	for (int i = 0; i < 9; i++) {
		if (i == ans1 || i == ans2)
			continue;
		printf("%d\n", arr[i]);
	}
	return 0;
}