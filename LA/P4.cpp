#include "MATRIX.h"


void swapCols(Matrix& mat, int i, int j)
{
	for (int c = 0; c < mat.size(); ++c)
	{
		swap(mat[c][i],mat[c][j]);
	}
}

void makeSquare(Matrix& A)
{
	while (A.size() < A[0].size())
	{
		for (int i = 0; i < A.size(); ++i)
		{
			A[i].pop_back();
		}
	}
}

// 0 : nosolution, 1 : otherwise
int LUP(Matrix& a,Vec& b, Matrix& l, Matrix& p)
{
	//initializing
	//p.clear(); l.clear();p.clear();
	
	//l = extend(l,a.size(),a.size());
//	p = I(a[0].size(););
	
	for (int i = 0; i < a.size(); ++i)
	{
		l[i][i] = 1;
		if (abs(a[i][i]) > DBL_EPSILON)
		{
			for (int j = i + 1; j < a.size(); ++j)
			{
				double t = a[j][i] / a[i][i];
				a[j] = a[j] - t * a[i];
				l[j][i] += t;
			}
		}
		else
		{
			int j;
			for (j = i; j < a[i].size(); ++j)
			{
				if (abs(a[i][j]) > DBL_EPSILON)
				{
					swapCols(a, i, j);
					swap(p[i],p[j]);
					break;
				}
			}

			if (j == a[i].size())//a[i] is dependent
			{
				Vec vv = -1 * l[i];
				vv[i] = 1;
				if (abs(vv * b) > DBL_EPSILON )//check no solution
				{
					return 0;
				}
				b.erase(b.begin()+i);
				l.erase(l.begin()+i);
				a.erase(a.begin()+i);
			}
			--i;
		}
	}

	makeSquare(l);

	return 1;
}



int main()
{
	
	int k, n; cin >> k >> n;
	Matrix A(k);
	Vec B(k);
	for (int i = 0; i < k; ++i)
	{

		A[i] = Vec(n);
		for (int j = 0; j < n; ++j)
		{
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < k;++i)
	{ 
		cin >> B[i];
	}
	Matrix L,P = I(n),U = A;
	
	L = extend(L, k,k);
	if (!LUP(U, B, L, P))
	{
		cout << "No solution" << endl;
		return 0;
	}
	if (U.size() < U[0].size())
	{
		cout << "Many solution" << endl;
		makeSquare(U);
	}
	else
	{
		cout << "Unique solution" << endl;
	}
	

	//cout << "L\n" << L*(inverse((L))) << "U\n" << U*inverse(U) << "P\n" << P*T(P) << endl << (L*U*P);

	Matrix aInverse = (T(P) * T(inverse(T(U))))*(inverse(L));//to inverse U we just transpose U and compute inverse and transpose again(because i have implemented method for lower triangular)
	
	//cout << "I" << aInverse * A << "A"<<A;
	Matrix BB;
	BB.push_back(B);
	BB = T(BB);
	Vec ans = T( (aInverse * BB) )[0];

	ans = extend(ans, n);
	cout <<ans << endl;
}
