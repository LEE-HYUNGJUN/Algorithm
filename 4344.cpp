#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, s, m;
int main()
{
	int t;
	int arr[1001] = { 0, };
	scanf("%d", &t);

	while (t--) {
		int n;
		double average = 0;
		double sum = 0;
		int cnt = 0;
		scanf("%d", &n);

		for (int i = 1; i <= n; i++) {
			scanf("%d", &arr[i]);
		}
		for (int i = 1; i <= n; i++) {
			sum += arr[i];
		}
		average = sum / (double)n;

		for (int i = 1; i <= n; i++) {
			if (arr[i] > average)
				cnt++;
		}
		printf("%0.3f%%\n", ((double)cnt / (double)n) * 100);
	}


	return 0;
}