#include<iostream>
#include<string>
using namespace std;

//class Date
//{
//	//friend istream& operator>>(istream& in, Date& d);
//	//friend ostream& operator<<(ostream& out, Date& d);
//public:
//	Date(size_t year = 0, size_t mon = 0,size_t day = 0):
//		_year(year),
//		_month(mon),
//		_day(day)
//	{
//	}
//
//	void display()
//	{
//		cout << _year << '-' << _month << '-' << _day << endl;
//	}
//
//	//// 成员函数，用于输出日期
//	//ostream& print(std::ostream& os) const {
//	//	os << _year << "-" << _month << "-" << _day;
//	//	return os; // 返回流对象以支持链式调用
//	//}
//
//	//// 成员函数，用于从输入流读取数据
//	//istream& read(istream& is) {
//	//	is >> _year >> _month >> _day;
//	//	return is; // 返回流对象以支持链式调用
//	//}
//
//	istream& in(istream& in)
//	{
//		in >> _year >> _month >> _day;
//		return in;
//	}
//
//	ostream& out(ostream& ou)
//	{
//		ou << _year << _month << _day;
//		return ou;
//	}
//private:
//	size_t _year;
//	size_t _month ;
//	size_t _day;
//};

//istream& operator>>(istream& in, Date& d)
//{
//	in >> d._year >> d._month >> d._day;
//	return in;
//}
//
//ostream& operator<<(ostream& out, Date& d)
//{
//	out<< d._year << '-' << d._month << '-' << d._day;
//	return out;
//}

//void test_in()
//{
//	Date d;
//	d.in(cin);
//	d.display();
//	d.out(cout);
//}

//int main()
//{
//	test_in();
//	return 0;
//}


//#include<iostream>
//#include<string>
//using namespace std;


//void test()
//{
//    char str = 'a';
//    int i = 0;
//    while (str <= 'z')
//    {
//        if (i == 13 && str != 'z')
//        {
//            cout << endl;
//            i = 0;
//        }
//        cout << str;
//        str++;
//        i++;
//    }
//    str = 'z';
//    while (str >= 'a')
//    {
//        if (i == 13 && str!= 'a')
//        {
//            cout << endl;
//            i = 0;
//        }
//        cout << str;
//        str--;
//        i++;
//    }
//
//    //abcdefghijklm
//    //nopqrstuvwxyz
//    //zyxwvutsrqpon
//    //mlkjihgfedcba
//}

//void test2()
//{
//    string s;
//    char str;
//    for (str = 'a'; str <= 'z'; str++)
//    {
//        s += str;
//        if (str == 'm' || str == 'z')
//            s += '\n';
//
//
//    }
//
//    for (char se = 'z'; se >= 'a'; se--)
//    {
//        s += se;
//        if (se == 'n')
//            s += '\n';
//    }
//    cout << s;
//}
//int main()
//{
//    //test();
//    test2();
//    return 0;
//}

//#include<cmath>
//
//void test_1101()
//{
//	string s1, s2;
//	cin >> s1 >> s2;
//	
//	int hour1 = stoi(s1.substr(0, 2));
//	int minute1 = stoi(s1.substr(3, 2));
//	int second1 = stoi(s1.substr(6, 2));
//
//	int hour2 = stoi(s2.substr(0, 2));
//	int minute2 = stoi(s2.substr(3, 2));
//	int second2 = stoi(s2.substr(6, 2));
//
//	//int out = abs(hour2 - hour1) * 3600 + abs(minute2 - minute1) * 60 + abs(second2 - second1);
//	int time1 = hour1 * 3600 + minute1 * 60 + second1;
//	int time2 = hour2 * 3600 + minute2 * 60 + second2;
//	cout << abs(time2-time1);
//}
//
//int main()
//{
//	test_1101();
//	return 0;


//void test_1115()
//{
//	string s;
//	cin >> s;
//
//	int sum = 0;
//	for (size_t i = 0; i < s.size(); ++i)
//	{
//		sum += s[i] - '0';
//	}
//	cout << sum;
//}
//
//int main()
//{
//	test_1115();
//	return 0;
//}

//void test_1134()
//{
//	string s;
//	cin >> s;
//
//	int size = s.size();
//	while (size)
//	{
//		if (s[0] == s[size - 1])
//		{
//			s = s.substr(0, size / 2);
//			size /= 2;		}
//		else
//			break;
//	}
//	cout << size;
//}
//

void test_1387()
{
	string s;
	getline(cin, s);
	
	for (size_t i = 0; i < s.size(); ++i)
	{//NS BFW, JAJSYX TK NRUTWYFSHJ FWJ YMJ WJXZQY TK YWNANFQ HFZXJX
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			if (s[i] >= 'F'&& s[i] <= 'Z')
				s[i] = s[i] - 5;
			else
				s[i] += 21;
		}
	}
	cout << s;

}

int main()
{
	//test_1134();
	test_1387();
	return 0;
}