#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<assert.h>
namespace wcc
{
	class string
	{
	public:
		//string()
		//	:_str(new char[1])
		//{
		//	_str[0] = '\0';
		//	_size = 0;
		//	_capacity = 1;
		//}
		//string(char* str)
		//	//strlen不会将'\0'算作有效字符
		//	:_str(new char[strlen(str)] + 1)
		//{
		//	//strcpy也会将'\0'拷过去
		//	strcpy(_str, str);
		//}

		string(const char* str = "")
		{
			if (str == nullptr)
			{
				//assert(false)会直接报错
				assert(false);
				return;
			}
			_capacity = _size = strlen(str);
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		//string (const string& s)
		//	:_str(new char[strlen(s._str)+1])
		//{
		//	strcpy(_str, s._str);
		//}
		string(const string& s)
		{
			if (s._str == nullptr)
			{
				assert(false);
				return;
			}
			_capacity=_size = strlen(s._str);
			_str = new char[_capacity + 1];
			strcpy(_str, s._str);
		}

		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
				_size = _capacity = 0;
			}
		}

		string& operator=(const string s)
		{
			assert(s._str);

			char*tem = new char[strlen(s._str) + 1];
			strcpy(tem, s._str);
			delete[]_str;
			_str = tem;

			return *this;
		}

		size_t size()
		{
			return strlen(_str);
		}

		const char* C_str()
		{
			return _str;
		}

		char& operator[](size_t i)
		{
			assert(i < _size);
			return _str[i];
		}

		const char& operator[](size_t i)const
		{
			assert(i < _size);
			return _str[i];
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};

	//void test1()
	//{
	//	string s1("world");
	//	string s2 = s1;

	//	for (int i = 0; i < s1.size(); ++i)
	//	{
	//		cout << s1[i] << ' ';
	//	}
	//	cout << endl;

	//	for (int i = 0; i < s2.size(); ++i)
	//	{
	//		cout << s2[i] << ' ';
	//	}
	//	cout << endl;
	//}

	void test2()
	{
		string s1("hello");
		string s2 = " world";

		for (int i = 0; i < s1.size(); ++i)
		{
			cout << s1[i] << ' ';
		}
		cout << endl;

		for (int i = 0; i < s2.size(); ++i)
		{
			cout << s2[i] << ' ';
		}
		cout << endl;

		cout << s2.C_str();
	}
}
