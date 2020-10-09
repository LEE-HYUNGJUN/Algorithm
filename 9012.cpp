#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;


bool Check(string str) {
	int len = (int)str.length();
	stack<char> s;

	for (int i = 0; i < len; i++) {
		char c = str[i];

		if (c == '(') {
			s.push(c);
		}
		else {
			if (s.empty()) {
				return false;
			}
			else{
				s.pop();
			}
		}
	}
	return s.empty();
}

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		string str;
		cin >> str;

		if (Check(str))
			printf("YES\n");
		else
			printf("NO\n");
	}
	
	return 0;
}