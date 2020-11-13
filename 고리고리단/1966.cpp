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
	int t;
	scanf("%d",&t);
	while (t--) {
		/* 벡터 2개 이용
		int num, idx;
		scanf("%d", &num);
		scanf("%d", &idx);

		vector<int> import;
		vector<int> loc;
		int input;
		int result = 0;

		for (int i = 0; i < num; i++) {
			scanf("%d", &input);
			import.push_back(input);
			loc.push_back(input);
		}
		sort(loc.begin(), loc.end());
		int ptr = num - 1;

		for (int i = 0; ; i = (i + 1) % num) {
			if (import[i] == loc[ptr]) {
				ptr--;
				result++;
				if (i == idx)
					break;
			}
		}
		printf("%d\n", result);
	*/
		// 우선순위큐 이용
		int n, m, ans = 0;
		queue <pair<int, int>> q;

		priority_queue <int> pq; // 내림차순 정렬
		scanf("%d", &n);
		scanf("%d", &m);

		for (int i = 0; i < n; i++) {
			int import;
			scanf("%d", &import);
			q.push({ i,import });
			pq.push(import);
		}

			while (!q.empty()) {
			int loc = q.front().first; //위치
			int importance = q.front().second; //중요도
			q.pop();

			if (importance == pq.top()) { //중요도가 pq와 같을 경우
				pq.pop(); // pq에서 pop
				ans++; // 카운트해줌
				if (loc == m) { // 찾고자 하는 위치 같을 경우
					printf("%d\n", ans);
					break; 
				}
			}
			else { 
				q.push({ loc,importance });
			}
		}

	}
	
	return 0;
}