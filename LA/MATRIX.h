#pragma once
#include<iostream>
#include<vector>
#include<math.h>


using namespace std;
using Vec = vector<double>;
using Matrix = vector<vector<double>>;

Matrix extend(Matrix mat, int rows, int cols);

Matrix I(int n);

Vec extend(Vec v, int s);

Matrix T(Matrix v);

ostream& operator << (ostream& os, Vec v);

ostream& operator << (ostream& os, Matrix v);

Vec operator +(Vec v1, Vec v2);

Vec operator -(Vec v1, Vec v2);

Vec operator *(double d, Vec v2);

double operator *(Vec v1, Vec v2);

Matrix operator *(Matrix v1, Matrix v2);

double proj(Vec v, Vec v1);

Matrix inverse(Matrix v);

