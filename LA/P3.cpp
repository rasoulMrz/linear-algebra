//#include<iostream>
//#include<vector>
//#include<math.h>
//
//
//using namespace std;
//
//using Vec = vector<double>;
//using Vecs = vector<vector<double>>;
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
//Vecs T(Vecs v)
//{
//	Vecs ans(v[0].size());
//	for (int j = 0; j < v.size(); ++j)
//	{
//		for (int i = 0; i < v[j].size(); ++i)
//		{
//			ans[i].push_back(v[j][i]);
//		}
//	}
//	return ans;
//}
//
//
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
//ostream& operator << (ostream& os, Vecs v)
//{
//	
//	for (int i = 0; i < v.size(); ++i)
//	{
//		os << v[i] << endl;
//	}
//	return os;
//}
//
//Vec operator +(Vec v1, Vec v2)
//{
//	if (v1.size() > v2.size())
//	{
//		v2 = extend(v2, v1.size());
//	}
//	else if (v1.size() < v2.size())
//	{
//		v1 = extend(v1, v2.size());
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
//	if (v1.size() > v2.size())
//	{
//		v2 = extend(v2, v1.size());
//	}
//	else if (v1.size() < v2.size())
//	{
//		v1 = extend(v1, v2.size());
//	}
//	Vec ans;
//	for (int i = 0; i < v1.size(); ++i)
//	{
//		ans.push_back(v1[i] - v2[i]);
//	}
//	return ans;
//}
//
//
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
//	if (v1.size() > v2.size())
//	{
//		v2 = extend(v2, v1.size());
//	}
//	else if (v1.size() < v2.size())
//	{
//		v1 = extend(v1, v2.size());
//	}
//	double ans = 0;
//	for (int i = 0; i < v1.size(); ++i)
//	{
//		ans += (v1[i] * v2[i]);
//	}
//	return ans;
//}
//
//Vecs operator *(Vecs v1, Vecs v2)
//{
//	Vecs ans(v1.size());
//	v2 = T(v2);
//
//	for (int i = 0; i < v1.size(); ++i)
//	{
//		for (int j = 0; j < v2.size(); ++j)
//		{
//			ans[i].push_back(v1[i]*v2[j]);
//		}
//	}
//	return ans;
//}
//
//
//
//double proj(Vec v, Vec v1)
//{
//	return (v*v1) / (v1*v1);
//}
//
//
//
//
//bool gram(Vec v, Vecs& grams, Vecs& gramC, Vecs& ans)//returns true if v is independent
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
//		c = extend(Vec(), grams.size() - 1);
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
//Vecs P2(Vec& I, Vecs& ans)
//{
//	Vecs v, grams, gramC;
//	
//	int n, k;
//	
//
//	cin >> k;
//	cin >> n;
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
//	for (int i = 0; i < grams.size(); ++i)
//	{
//		grams[i] = extend(grams[i], n);
//	}
//	for (int i = 0; i < gramC.size(); ++i)
//	{
//		gramC[i] = extend(gramC[i], grams.size());
//	}
//	for (int i = 0; i < ans.size(); ++i)
//	{
//		ans[i] = extend(ans[i], v[0].size());
//	}
//	return v;
//}
//
//bool checkNS(Vec& b, Vec indeps, Vecs C)
//{
//	
//	int li = 0;
//	for (int i = 0; i < b.size(); ++i)
//	{
//		if (li >= indeps.size() ||  i != indeps[li])
//		{
//			
//			int tmp = (extend(C[i],b.size())*b);
//			if (tmp - b[i] > DBL_EPSILON || b[i] - tmp > DBL_EPSILON)
//				return true;
//			b.erase(b.begin() + i);
//		}
//		else { ++li; }
//	}
//	return false;
//}
//
//void QR(Vecs A,Vecs& Q,Vecs& R)
//{
//	A = T(A);
//	Q.push_back((1 / sqrt(A[0] * A[0])) * A[0]);
//	Q[0] = extend(Q[0], A[0].size());
//	for (int i = 1; i < A.size(); ++i)
//	{
//		Q.push_back(Vec());
//		Q[i] = A[i];
//		for (int j = 0; j < i; ++j)
//		{
//			double p = proj(Q[i], Q[j]);
//			Q[i] =  Q[i] - p * Q[j];
//		}
//		
//		if(Q[i]*Q[i] > DBL_EPSILON)
//			Q[i] = ((1 / sqrt(Q[i] * Q[i]))*Q[i]);
//		
//		
//		Q[i] = extend(Q[i], A[0].size());
//	}
//	
//	R = Q * T(A);
//	Q = T(Q);
//}
//
//Vecs inverse(Vecs v)
//{
//	Vecs ans(v.size());
//	
//	for (int j = 0; j < v.size(); ++j)
//	{
//		for (int i = 0; i < j; ++i)
//		{
//			double tmp = 0;
//			for (int jj = 0; jj < j;++jj)
//			{
//				tmp += v[j][jj] * ans[jj][i];
//			}
//			ans[j].push_back( ((-1 * tmp) / (v[j][j])));
//		}
//		if(v[j][j]*v[j][j] > DBL_EPSILON)
//			ans[j].push_back(1 / v[j][j]);
//		else
//			ans[j].push_back(0);
//		ans[j] = extend(ans[j], v[0].size());
//	}return ans;
//}
//
//
//
//
//
//int main()
//{
//	Vec indeps;
//	Vecs A, C;
//	A = P2(indeps, C);
//	int k = A.size();
//	int n = A[0].size();
//	Vec b(k);
//	for (int i = 0; i < k; ++i)
//	{
//		cin >> b[i];
//	}
//	if (checkNS(b,indeps, C))
//	{
//		cout << "No solution" << endl; return 0;
//	}if (indeps.size() < A[0].size())
//	{
//		for (int i = 0; i < A.size();++i)
//		{
//			while (indeps.size() < A[i].size())
//			{
//				A[i].pop_back();
//			}
//		}
//
//		cout << "Many solution" << endl;
//	}
//	else
//	{
//		cout << "Unique solution" << endl;
//	}
//
//	Vecs newA;
//	for (int i = 0; i < indeps.size();++i)
//	{
//		newA.push_back(A[indeps[i]]);
//	}
//	Vecs Q, R;
//	
//	QR(newA,Q,R);
//	
//	//R = T(R);
//	Vecs B; B.push_back(b); B = T(B);
//	Vecs inv = T(inverse(T(R)));
//
//	
//	cout << extend(T((inv*T(Q))*B)[0],n);
//	
//
//	return 0;
//}
