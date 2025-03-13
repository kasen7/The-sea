#include<iostream>
#include<string>
#include<cmath>
using namespace std;

//void test_1268()
//{
//	string s1, s2;
//	cin >> s1 >> s2;
//
//	int a1[250] = { 0 }, a2[250] = { 0 };
//	for (size_t i = 0; i < s1.size(); ++i)
//	{
//		a1[s1.size() - i - 1] = s1[i] - '0';
//	}
//
//	for (size_t i = 0; i < s2.size(); ++i)
//	{
//		a2[s2.size() - i - 1] = s2[i] - '0';
//	}
//
//	int a3[250] = { 0 };
//	bool jw = false;
//	int len = max(s1.size(), s2.size());
//	for(size_t i=0;i<len;++i)
//	{
//		a3[i] = a1[i] + a2[i] + a3[i];
//		if (a3[i] >= 10)
//		{
//			if (i == len - 1)
//				jw = true;
//			a3[i + 1]++;
//			a3[i] %= 10;
//		}
//	}
//
//	if (jw)
//		len++;
//
//	for (int i = len - 1; i >= 0; --i)
//	{
//		cout << a3[i];
//	}
//}

//void test_1269()
//{
//	string s1, s2;
//	bool jh = false;
//	cin >> s1 >> s2;
//
//	if (s1.size() < s2.size())
//	{
//		swap(s1, s2);
//		jh = true;
//	}
//	else if (s1 == s2)
//	{
//		cout << 0;
//		exit(0);
//	}
//
//	int a[250] = { 0 }, b[250] = { 0 }, c[250] = { 0 };
//	for (size_t i = 0; i < s1.size(); ++i)
//	{
//		a[s1.size() - 1 - i] = s1[i] - '0';
//	}
//	for (size_t i = 0; i < s2.size(); ++i)
//	{
//		b[s2.size() - 1 - i] = s2[i] - '0';
//	}
//
//	int len = max(s1.size(), s2.size());
//	bool jw = false;
//	for (int i = 0; i < len; ++i)
//	{
//		c[i] = a[i] - b[i] + c[i];
//		if (c[i] < 0)
//		{
//			if (i == len - 1)
//				jw = true;
//			c[i + 1]--;
//			c[i] += 10;
//		}
//
//		if (c[i] == 0 && i == len - 1)
//			jw = true;
//	}
//
//	if (jw)
//		len--;
//
//	if (jh)
//		cout << '-';
//	for (int i = len - 1; i >= 0; --i)
//	{
//		cout << c[i];
//	}
//}

void test_1287()
{
	string s1, s2;
	cin >> s1 >> s2;

	int len1 = s1.size(), len2 = s2.size();
	if (len1 == 1 && s1[0] == '0')
	{
		cout << 0;
	}
	else if (len2 == 1 && s2[0] == '0')
	{
		cout << 0;
	}

	int a[250] = { 0 }, b[250] = { 0 }, c[250] = { 0 };
	for (int i = 0; i < len1; ++i)
	{
		a[len1 - 1 - i] = s1[i] - '0';
	}
	for (int i = 0; i < len2; ++i)
	{
		b[len2 - 1 - i] = s2[i] - '0';
	}

	for (int i = 0; i < len1; ++i)
	{
		for (int j = 0; j < len2; ++j)
		{
			c[i + j] += a[i] * b[j];

			if (c[i + j] >= 10)
			{
				c[i + j + 1] += c[i + j] / 10;
				c[i + j] %= 10;
			}
		}
	}
	//bool cl = true;
	//int size = sizeof(c) / sizeof(c[0]);
	//for (int i = size-1; i >= 0; --i)
	//{
	//	if (c[i] != 0 && cl)
	//	{
	//		cout << c[i];
	//		cl = false;
	//	}
	//	else if (!cl)
	//		cout << c[i];
	//}
	int pos;
	for (int i = len1 + len2 - 1; i >= 0; --i)
	{
		if (c[i] != 0)
		{
			pos = i;
			break;
		}
	}

	for (int i = pos; i >= 0; --i)
	{
		cout << c[i];
	}
}

int main()
{
	////test_1268();
	////test_1269();
	test_1287();
	return 0;
}