#include<iostream>
#include<vector>
#include<string>
using namespace std;
class mare
{
public:
	vector<short> v;
	string s;
	mare()
	{
		v = { };
		s = "";
	}
	mare(vector<short> v)
	{
		this->v = v;
		transform(v);
	}
	mare(string s)
	{
		this->s = s;
		transform(s);
	}
	void transform(string s)
	{
		while (s.size())
		{
			v.insert(v.begin(), s[s.size()-1]-'0');
			s.pop_back();
		}
		//cou();
	}
	void transform(vector<short> v)
	{
		for (auto i : v)
		{
			s.push_back(i + '0');
		}
		//cou();
	}
	void cou()
	{
		for (auto i : v)
			cout << i;
		cout << endl;
		for (auto i : s)
			cout << i;
		cout << endl;
	}
	mare operator+(const mare& obji)
	{
		mare obj = obji;
		while (v.size() > obj.v.size())
			obj.v.insert(obj.v.begin(), 0);
		while (obj.v.size() < v.size())
			v.insert(v.begin(), 0);
		vector<short> res(v.size());
		for (int i = v.size() - 1; i >= 0; i--)
		{
			res[i] = v[i] + obj.v[i];
			if (res[i] >= 10 && i > 0)
			{
				res[i - 1]++;
				res[i] -= 10;
			}
		}
		if (res[0]>=10)
		{
			res[0] -= 10;
			res.insert(res.begin(), 1);
		}
		return res;
	}
	mare operator-(const mare& obji)
	{
		mare obj = obji;
		while (v.size() > obj.v.size())
			obj.v.insert(obj.v.begin(), 0);
		while (obj.v.size() < v.size())
			v.insert(v.begin(), 0);
		vector<short> res = v;
		if (maimare(v, obj.v))
		{  
			for (int i = v.size() - 1; i >= 0; i--)
			{
				res[i] -= obj.v[i];
				if (res[i] < 0)
					res[i] += 10, res[i - 1] -= 1;
			}
		}
		while (res.size() > 1 && res[res.size() - 1] == 0)
			res.pop_back();
		return res;
	}
	mare operator*(const mare& obji)
	{
		mare obj = obji;
		int t = v.size() + obj.v.size();
		vector<short> va(t), vb(t), p(t);
		for (int i = v.size() - 1; i >= 0; i--)
			va[v.size() - i - 1] = v[i];
		for (int i = obj.v.size() - 1; i >= 0; i--)
			vb[obj.v.size() - i - 1] = obj.v[i];
		for (int i = 0; i < v.size(); i++)
		{
			for (int j = 0; j < obj.v.size(); j++)
			{
				p[i + j] += va[i] * vb[j];
			}
		}
		int minte = 0;
		for (int i = 0; i < t; i++)
		{
			int s = minte + p[i];
			p[i] = s % 10;
			minte = s / 10;
		}
		if (p[t - 1] == 0)
			t--, p.pop_back();
		vector<short> p1(p.size());
		for (int i = 0; i < p.size(); i++)
		{
			p1[i] = p[p.size() - 1 - i];
		}
		return p1;
	}
	friend ostream& operator<<(ostream& os, mare obj)
	{
		for (int i = 0; i < obj.v.size(); i++)
		{
			os << obj.v[i];
		}
		return os;
	}
	bool maimare(vector<short> a, vector<short> b)
	{
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] > b[i]) return 1;
			if (a[i] < b[i]) return 0;
		}
		return 1;
	}
};
