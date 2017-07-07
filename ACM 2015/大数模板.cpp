#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


struct BigInteger{
	static const int BASE = 100000000;
	static const int WIDTH = 8;
	vector<int> s;

	BigInteger(long long num = 0) { *this = num; }
	BigInteger& operator = (long long);
	BigInteger& operator = (string&);

	BigInteger operator + (BigInteger &b);   
	BigInteger operator - (BigInteger &b);   
	BigInteger operator * (BigInteger &b);
	BigInteger operator / (int b);   
	int operator % (int b);

	bool operator < (const BigInteger &b) const;  
	bool operator > (const BigInteger &b) const;
	bool operator <= (const BigInteger &b) const;
	bool operator >= (const BigInteger &b) const;
	bool operator != (const BigInteger &b) const;
	bool operator == (const BigInteger &b) const;
};

BigInteger& BigInteger::operator = (long long num){
	s.clear();
	do{
		s.push_back(num % BASE);
		num /= BASE;
	} while (num > 0);
	return *this;
}

BigInteger& BigInteger::operator = (string &str){
	s.clear();
	int x, len = (str.length() - 1) / WIDTH + 1;
	for (int i = 0; i < len; ++i){
		int _end = str.length() - WIDTH*i;
		int start = max(0, _end - WIDTH);
		sscanf(str.substr(start, _end - start).c_str(), "%d", &x);
		s.push_back(x);
	}
	return *this;
}

BigInteger BigInteger::operator + (BigInteger &b){
	BigInteger c;
	c.s.clear();
	for (unsigned i = 0, g = 0;; ++i){
		if (g == 0 && i >= s.size() && i >= b.s.size()) break;
		int x = g;
		if (i < s.size()) x += s[i];
		if (i < b.s.size()) x += b.s[i];
		c.s.push_back(x % BASE);
		g = x / BASE;
	}
	return c;
}

BigInteger BigInteger::operator - (BigInteger &b){
	BigInteger c;
	c.s.clear();
	for (unsigned i = 0, g = 0;; ++i){   
		if (g == 0 && i >= s.size() && i >= b.s.size()) break;
		int x = g + s[i];
		if (i < b.s.size()) x -= b.s[i];
		if (x < 0) { c.s.push_back(BASE + x); g = -1; }
		else { c.s.push_back(x); g = 0; }
	}
	if (c.s.back() == 0) c.s.erase(c.s.end() - 1);
	return c;
}	

BigInteger BigInteger::operator * (BigInteger &b){
	BigInteger c;
	c.s.clear();
	c.s.resize(s.size() + b.s.size() - 1);
	long long g = 0;
	unsigned j;
	for (unsigned i = 0; i < s.size(); ++i){
		for (j = 0; j < b.s.size(); ++j){
			long long x = g + static_cast<long long>(s[i])*b.s[j] + c.s[i + j];
			c.s[i + j] = x % BASE;
			g = x / BASE;
		}
		if (g != 0){
			if (i + j + 1 > c.s.size()) c.s.resize(i + j + 1);
			c.s[i + j] += g;
			g = 0;
		}
	}
	return c;
}

BigInteger BigInteger::operator / (int b){
	BigInteger c;
	c.s.clear();
	c.s.resize(s.size());
	long long g = 0;
	for (int i = s.size() - 1; i >= 0; --i){
		c.s[i] = (g*BASE + s[i]) / b;
		g = g*BASE + s[i] - c.s[i] * b;
	}
	int clear_0 = s.size() - 1;    
	while (c.s[clear_0] == 0 && clear_0 > 0){
		c.s.erase(c.s.begin() + clear_0--);
	}
	return c;
}

int BigInteger::operator % (int b){
	int remainder = 0;  
	for (int i = s.size() - 1; i >= 0; --i){
		remainder = ((remainder*BASE) % b + s[i]) % b;
	}
	return remainder;
}

bool BigInteger::operator < (const BigInteger &b) const {
	if (s.size() != b.s.size()) return s.size() < b.s.size();
	for (int i = s.size() - 1; i >= 0; --i)
		if (s[i] != b.s[i]) return s[i] < b.s[i];
	return false;  //ПаµИ;
}
bool BigInteger::operator > (const BigInteger &b) const { return b < *this; }
bool BigInteger::operator <= (const BigInteger &b) const { return !(*this > b); }
bool BigInteger::operator >= (const BigInteger &b) const { return !(*this < b); }
bool BigInteger::operator != (const BigInteger &b) const { return (*this < b) || (*this > b); }
bool BigInteger::operator == (const BigInteger &b) const { return !(b < *this) && !(*this > b); }

ostream& operator << (ostream &out, const BigInteger &b){
	out << b.s.back();
	for (int i = b.s.size() - 2; i >= 0; --i){
		char buf[10];
		sprintf(buf, "%08d", b.s[i]);
		out << buf;
	}
	return out;
}
istream& operator >> (istream &in, BigInteger &b){
	string str;
	in >> str;
	b = str;
	return in;
}
BigInteger b[1010];

bool judge(BigInteger &a, BigInteger &b, BigInteger &c){
	if (a + b <= c) return false;
	if (c - a >= b) return false;
	if (c - b >= a) return false;
	return true;
}

int main()
{
	BigInteger a, b;
	string c, d;
	getline(cin, c);
	getline(cin, d);
	a = c;
	b = d;
	cout << a + b << endl;
	return 0;
}