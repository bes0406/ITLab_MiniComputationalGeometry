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


int CheckPoint(TPoint a, TPoint b, TPoint c)   // Возвращаемый результат 0 - точка b лежит на прямой, >0 - выше, <0 - ниже
 {
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

double TPoint  :: VectorMult (TPoint  i,  TPoint& j, TPoint k ) // Векторное произведение [i,j,k]
{ 
	// считаем определитель [i, j, k]  
	return ( i[0] * j[1] + k[0] * i[1] + j[0] * k[1] - k[0] * j[1] - i[0] * k[1] - j[0] * i[1] ); 
}