#include "qh.h"
#include "math.h"


ConvexHull :: ConvexHull (int _HullSize)
{
	HullSize =_HullSize;
	TPoint temp(0,0);
	for ( int i=0; i < HullSize; i++)
		hull[i] = temp;
}

ConvexHull :: ConvexHull ( const ConvexHull &h) 
{
	HullSize = h.HullSize;
	hull = h.hull;
}

TPoint ConvexHull :: operator[] (int i)
{
	return hull[i];
}


TPoint ConvexHull:: right () // ����� ������ �����
{
	TPoint rig(0,0);
	for (int i = 1; i < HullSize; i++)
		if  ( hull[i-1] > hull[i] )
			rig = hull[i-1];
		else
			rig = hull[i];
     return rig;
}

TPoint ConvexHull:: left () // ����� ����� �����
{
	TPoint lef(0,0);
	for (int i = 1; i < HullSize; i++)
		if  ( hull[i-1] < hull[i] )
			lef = hull[i-1];
		else
			lef = hull[i];
     
	return lef;
}

TPoint ConvexHull ::  remote ( TPoint A, TPoint B, ConvexHull h ) // ����� ���������� ����� �� ������ AB ( ������� ���72, M.M.�����)
{   
	TPoint t(0,0); 
	TPoint q(0,0);
	TPoint maxpoint(0,0);
	
	double dist; // ����������
	double max = 0; //  ������������ ����������

	for (int i=0; i < h.HullSize;  i++)
	{
    // �������� ����� ������������
	t = h[i];

	dist = t.VectorMult(A, B, t);

	if (dist > max ) { max = dist; maxpoint = t;}
	}

	return maxpoint;
}

ConvexHull ConvexHull :: Split (TPoint A, TPoint B,  ConvexHull &above, ConvexHull &bellow) // ������������� ������������ h �� ���������������� abov � bellow
{
	int temp=0;
	int j=0;
	ConvexHull abv ( HullSize );
	ConvexHull bel ( HullSize );
	for ( int i=0; i < HullSize; )
		{
			temp = A.CheckPoint( A, hull[i], B); // �������������� h[i] ������������ AB
			if ( temp >= 0 ) abv[i++] = hull[i];
			else  abv[j++] = hull[i]; 
	    }
	return 0;
}


TPoint ConvexHull :: QiuckHull()
{
	return 0;
}










