#include "tpoint.h"

TPoint :: TPoint (double x, double y)
{
	X=x;
	Y=y;
}

TPoint TPoint :: operator+( TPoint &m)
{
	X+= m.X;
	Y+= m.Y;
	return (*this);
}

TPoint TPoint :: operator-( TPoint &m)
{
	X-= m.X;
	Y-= m.Y;
	return (*this);
}

int TPoint :: operator >( TPoint &m)
{ 
	return ( (X > m.X) || ((X == m.X) && (Y > m.Y)) );
}


int TPoint :: operator < ( TPoint &m)
{ 
	return ( (X < m.X) || ((X == m.X) && (Y < m.Y)) );
}

double TPoint :: length()
{
	return sqrt ( X*X + Y*Y );
}


int TPoint :: CheckPoint(TPoint a, TPoint b, TPoint c)   // ������������ ��������� 0 - ����� b ����� �� ������, >0 - ����, <0 - ����
 {
	 /// ��� �������: ��������, ���� � ���������� ����� 0.7, �� ��� ���������� � int ��� ������ 0
	 /// ����� ������ ����� ����
	 return (b.X-a.X)*(b.Y-c.Y)-(b.Y-a.Y)*(b.X-c.X);
}


 double TPoint ::operator [] (int i)
{
	if ( i == 0 )  return X;
	else  if ( i==1 ) return Y;
}


int TPoint ::operator == (TPoint &m)
{
	return ( (X==m.X) && (Y==m.Y) );
}

int TPoint ::operator != (TPoint &m)
{
	return ( (X!=m.X) || (X!=m.Y) );
}

double TPoint  :: VectorMult (TPoint  i,  TPoint& j, TPoint k ) // ��������� ������������ [i,j,k]
{ 
	// ������� ������������ [i, j, k]  
	return ( i[0] * j[1] + k[0] * i[1] + j[0] * k[1] - k[0] * j[1] - i[0] * k[1] - j[0] * i[1] ); 
}