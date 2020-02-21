//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//using Vec = vector<double>;
//using Vecs = vector<vector<double>>;
//ostream& operator << (ostream& os, Vec v)
//{
//	if (v.size())
//		os << v[0];
//	for (int i = 1; i < v.size(); ++i)
//	{
//		os << ' ' << v[i];
//	}
//	return os;
//}
//
//Vec operator +(Vec v1, Vec v2)
//{
//	if (v1.size() != v2.size())
//	{
//		throw exception();
//	}
//	Vec ans;
//	for (int i = 0; i < v1.size(); ++i)
//	{
//		ans.push_back(v1[i] + v2[i]);
//	}
//	return ans;
//}
//
//Vec operator -(Vec v1, Vec v2)
//{
//	if (v1.size() != v2.size())
//	{
//		
//		throw exception();
//	}
//	Vec ans;
//	for (int i = 0; i < v1.size(); ++i)
//	{
//		ans.push_back(v1[i] - v2[i]);
//	}
//	return ans;
//}
//
//Vec extend(Vec v, int s)
//{
//	Vec a = v;
//	while (a.size() < s)
//	{
//		a.push_back(0);
//	}
//	return a;
//}
//
//Vec operator *(double d, Vec v2)
//{
//	Vec ans;
//	for (int i = 0; i < v2.size(); ++i)
//	{
//		ans.push_back(d * v2[i]);
//	}
//	return ans;
//}
//
//
//
//
//double operator *(Vec v1, Vec v2)
//{
//	if (v1.size() != v2.size())
//	{
//		throw exception();
//	}
//	double ans = 0;
//	for (int i = 0; i < v1.size(); ++i)
//	{
//		ans += (v1[i] * v2[i]);
//	}
//	return ans;
//}
//
//int n, k;
//Vec I;
//
//Vecs get()
//{
//	Vecs v;
//
//	 cin >> k;
//	 cin >> n;
//
//	for (int i = 0; i<k; ++i)
//	{
//		Vec vec;
//		for (int j = 0; j < n; ++j)
//		{
//			double t; cin >> t;
//			vec.push_back(t);
//		}
//		v.push_back(vec);
//	}
//	return v;
//}
//
//double proj(Vec v, Vec v1)
//{
//	return (v*v1) / (v1*v1);
//}
//
//
//
//
//bool gram(Vec v,Vecs& grams, Vecs& gramC, Vecs& ans)//returns true if v is independent
//{
//	Vec c;
//	
//	for (int i = 0; i < grams.size() && (v*v) != 0; ++i)
//	{
//		double p = proj(v, grams[i]);
//		
//		v = v - p * grams[i];
//		c = extend(c, grams.size()) + extend(p*gramC[i], grams.size());
//	}
//
//	if (v*v > DBL_EPSILON)
//	{
//		grams.push_back(v);
//		Vec c1 = extend(c, grams.size());
//		c = extend(Vec(), grams.size()-1);
//		c.push_back(1);
//		
//		gramC.push_back((c - c1));
//		ans.push_back(c);
//		return true;
//	}
//	ans.push_back(c);
//	return false;
//}
//
//
//int main()
//{
//	Vecs v;
//
//	v = get();
//
//	Vecs gramC;
//	Vecs grams;
//	Vecs ans;
//
//	grams.push_back(v[0]);
//	Vec tmp = Vec(); tmp.push_back(1);
//	gramC.push_back(tmp);
//	ans.push_back(tmp);
//	I.push_back(0);
//
//	for (int i = 1; i < v.size(); ++i)
//	{
//		if (gram(v[i], grams, gramC, ans))
//			I.push_back(i);
//	}
//
//	cout << I << endl;
//	for (Vec i : ans)
//	{
//		cout << extend(i, I.size()) << endl;
//	}
//	return 0;
//}
