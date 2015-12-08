#include "stdafx.h"
#include "TPoint.h"
#include "ConvexHull.h"
int main(int argc, _TCHAR* argv[])
{
	TPoint p(2,3);
	ConvexHull t(p);
	cout << p[0] <<"   "<<p[1] << endl << t.hull[0][0] << t.hull[0][1] <<endl;
	TPoint p1(4,5);
	int a=t.FindMinX();
	cout << a <<endl ;
	int k=t.FindRightSupportLine(p1);
	//bool fl=t.IsPointInHull(p1);
	cout << k ;
	//t.CreateNewConvexHull(p1);
	system("pause");
	return 0;
}
