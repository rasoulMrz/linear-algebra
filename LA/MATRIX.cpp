#include<iostream>
#include<vector>
#include<math.h>
#include "MATRIX.h"

Vec extend(Vec v, int s)
{
	Vec a = v;
	while (a.size() < s)
	{
		a.push_back(0);
	}
	return a;
}

Matrix I(int n)
{
	Matrix m;
	for (int i = 0; i < n; ++i)
	{
		Vec v;v = extend(v, n);
		v[i] = 1;
		m.push_back(v);
	}
	return m;
}

Matrix extend(Matrix mat,int rows, int cols)
{
	for (int i = 0; i < rows; ++i)
	{
		if (mat.size() == i)
		{
			mat.push_back(extend(Vec(),cols));
		}
		else
		{
			mat[i] = extend(mat[i], cols);
		}
	}
	return mat;
}

Matrix T(Matrix v)
{
	Matrix ans(v[0].size());
	for (int j = 0; j < v.size(); ++j)
	{
		for (int i = 0; i < v[j].size(); ++i)
		{
			ans[i].push_back(v[j][i]);
		}
	}
	return ans;
}


ostream& operator << (ostream& os, Vec v)
{
	if (v.size())
		os << v[0];
	for (int i = 1; i < v.size(); ++i)
	{
		os << ' ' << v[i];
	}
	return os;
}
ostream& operator << (ostream& os, Matrix v)
{

	for (int i = 0; i < v.size(); ++i)
	{
		os << v[i] << endl;
	}
	return os;
}

Vec operator +(Vec v1, Vec v2)
{
	if (v1.size() > v2.size())
	{
		v2 = extend(v2, v1.size());
	}
	else if (v1.size() < v2.size())
	{
		v1 = extend(v1, v2.size());
	}
	Vec ans;
	for (int i = 0; i < v1.size(); ++i)
	{
		ans.push_back(v1[i] + v2[i]);
	}
	return ans;
}

Vec operator -(Vec v1, Vec v2)
{
	if (v1.size() > v2.size())
	{
		v2 = extend(v2, v1.size());
	}
	else if (v1.size() < v2.size())
	{
		v1 = extend(v1, v2.size());
	}
	Vec ans;
	for (int i = 0; i < v1.size(); ++i)
	{
		ans.push_back(v1[i] - v2[i]);
	}
	return ans;
}



Vec operator *(double d, Vec v2)
{
	Vec ans;
	for (int i = 0; i < v2.size(); ++i)
	{
		ans.push_back(d * v2[i]);
	}
	return ans;
}




double operator *(Vec v1, Vec v2)
{
	if (v1.size() > v2.size())
	{
		v2 = extend(v2, v1.size());
	}
	else if (v1.size() < v2.size())
	{
		v1 = extend(v1, v2.size());
	}
	double ans = 0;
	for (int i = 0; i < v1.size(); ++i)
	{
		ans += (v1[i] * v2[i]);
	}
	return ans;
}

Matrix operator *(Matrix v1, Matrix v2)
{
	Matrix ans(v1.size());
	v2 = T(v2);

	for (int i = 0; i < v1.size(); ++i)
	{
		for (int j = 0; j < v2.size(); ++j)
		{
			ans[i].push_back(v1[i] * v2[j]);
		}
	}
	return ans;
}

double proj(Vec v, Vec v1)
{
	return (v*v1) / (v1*v1);
}

Matrix inverse(Matrix v)
{
	Matrix ans(v.size());

	for (int j = 0; j < v.size(); ++j)
	{
		for (int i = 0; i < j; ++i)
		{
			double tmp = 0;
			for (int jj = 0; jj < j; ++jj)
			{
				tmp += v[j][jj] * ans[jj][i];
			}
			ans[j].push_back(((-1 * tmp) / (v[j][j])));
		}
		if (v[j][j] * v[j][j] > DBL_EPSILON)
			ans[j].push_back(1 / v[j][j]);
		else
			ans[j].push_back(0);
		ans[j] = extend(ans[j], v[0].size());
	}return ans;
}
