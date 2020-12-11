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

int main()
{
	int N;
	scanf("%d", &N);

	int n3 = 0;
	int n5 = 0;

	while (N % 5 != 0 && N >= 0) {
		N -= 3;
		n3++;
	}

	if (N < 0)
	{
		printf("-1\n");
	}
	else {
		n5 = N / 5;
		cout << n3 + n5 << endl;
	}
	return 0;
}