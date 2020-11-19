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

int tc;
int cnt;
vector<pair<int, int>> v;

int main() {
	scanf("%d", &tc);
	while (tc--) {
		int k;
		cnt = 1;
		scanf("%d", &k);

		for (int i = 0; i < k; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			v.push_back({ a,b });
		}
		sort(v.begin(), v.end());
		int m = v[0].second;

		for (int i = 1; i < k; i++) {
			if (v[i].second < m) {
				cnt++;
				m = v[i].second;
			}
		}
		printf("%d\n", cnt);
		v.erase(v.begin(),v.begin()+k);
	}
	return 0;
}