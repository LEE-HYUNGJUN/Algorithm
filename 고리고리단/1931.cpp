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
int com = 0;
vector <pair<int, int>> v;


int main() {
	scanf("%d", &tc);
	
	for(int i=0;i<tc;i++) {
		int first, second;
		scanf("%d %d", &first, &second);
		v.push_back({ second,first });
	}
	
	sort(v.begin(), v.end());

	int last = v[0].first;
	cnt = 1;
	for (int i = 1; i < tc; i++) {
		if (last <= v[i].second) {
			cnt++;
			last = v[i].first;
		}
	}
	printf("%d\n", cnt);
	/*for (int i = 0; i < tc; i++) {
		int m = v[i].second;
		cnt = 1;

		for (int j = i+1; j < tc; j++) {
			if (m <= v[j].first) {
				m = v[j].second;
				cnt++;
			}
		}
		if (cnt > com) {
			com = cnt;
		}
	}
	printf("%d\n", com);*/
	return 0;
}