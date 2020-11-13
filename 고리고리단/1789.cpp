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

long long s;

int main() {
	/*map<long long, long long> map;
	
	long long cnt = 1;
	long long ans =0;
	long long result;*/

	int num = 1;
	int result = 0;
	long long sum = 0;

	cin >> s;
	//result = s;

	/*while (1) {
		result -= cnt;
		if (result !=0)
		{
			if (result < cnt) {
				result += cnt;
				map[cnt] = 0;
				cnt++;
			}
			else {
				map[cnt] = 1;
				cnt++;
				ans ++;
			}	
		}
		else {
			map[cnt] = 1;
			ans++;
			break;
		}
	}*/
	/*for (int i = 1; i <= cnt; i++) {
		if (map[i])
			ans++;
	}*/

	while (1)
	{
		sum += num;
		result++;
		if (sum > s)
		{
			result--;
			break;
		}
		num++;
	}

	printf("%d\n", result);

	return 0;
}