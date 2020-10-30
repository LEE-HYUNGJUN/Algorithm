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

int n, m;
int main() {

	map<int, int> map;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int k;
		scanf("%d", &k);
		map[k]++;
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int k;
		scanf("%d", &k);
		if (map[k])
			printf("1\n");
		else
			printf("0\n");
	}
	
	return 0;
}