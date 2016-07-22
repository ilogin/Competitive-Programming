#include <bits/stdc++.h>
using namespace std;

class Time{
public:
	string whatTime(int seconds)
	{
		cin >> seconds;

		int h;
		int m;
		int rs;

		h = seconds/3600;

		stringstream ss;
		string ans;

		m = (seconds-(3600*h))/60;

		rs = seconds - h*3600 - m*60;

		ss << h << ':' << m << ':' << rs;
		ss >> ans;

		return ans;
	}
};