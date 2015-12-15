#include "stdafx.h"
#include "TPoint.h"
#include "ConvexHull.h"
int main(int argc, _TCHAR* argv[])
{   //не работает если точки лежат на одной прямой 
	cout << "Input Point"<<endl;
	TPoint p1;
	cin >> p1.x >> p1.y;
	ConvexHull t(p1);
	bool fl=true;
	while (fl)
	{
		cout << "ConvexHull:"<<endl;
	for (int i=0; i<t.k; i++)
		cout <<"("<< t.hull[i][0] <<"," << t.hull[i][1] <<")"<<endl;
	cout << "if you want to Input Point then input 1" << endl;
	cout << "if you want to Finish then input 2" << endl;
	int c;
	cin >> c;
	switch (c)
	{
	case 2: fl=false; break;
	case 1: 
		{
			TPoint p;
			cin >> p.x >> p.y;
			t.CreateNewConvexHull(p);
	} break;
	}
	}
	/*TPoint p(1,3);
	ConvexHull t(p);
	ConvexHull t1(p);
	cout << "p  " << p[0] <<"   "<<p[1] << endl << "t   " << t.hull[0][0] <<"   "<< t.hull[0][1] <<endl;
	TPoint p1(1,1);
	cout << "p1  " << p1[0] <<"   "<<p1[1] << endl;
	//int a=t.FindMinX();
	//cout << a <<endl ;
	//int k=t.FindRightSupportLine(p1);
	//bool fl=t .IsPointInHull(p);
	//cout << fl << endl;
	//cout << t.hull[0][0] <<"   " << t.hull[0][1] <<endl;
	cout << "t1   "<< t1.hull[0][0] << t1.hull[0][1] <<endl;
	t1=t1.CreateNewConvexHull(p1);
	cout << "t1.k    " <<t1.k<<endl;
	cout << "t1   " << endl << t1.hull[0][0] << t1.hull[0][1] <<endl << t1.hull[1][0] << t1.hull[1][1] << endl;
	TPoint p2(2,2);
	
	int l=t1.FindLeftSupportLine(p2);
	int r=t1.FindRightSupportLine(p2);
	t1=t1.CreateNewConvexHull(p2);
	cout << "l  " <<l << "             r   "<<r<< endl;
	cout << "t1.k    " <<t1.k<<endl;
	cout << "t1   "<< t1.hull[0][0] << t1.hull[0][1] <<endl << t1.hull[1][0] << t1.hull[1][1] << endl << t1.hull[2][0] << t1.hull[2][1] <<endl << t1.hull[3][0] << t1.hull[3][1] <<endl;
	bool q1, q2, q;
	q=t1.IsPointInHull(p);
	q1=t1.IsPointInHull(p1);
	q2=t1.IsPointInHull(p2);
	cout << "IsPointInHull" << endl << "p    " << q << endl << "p1   " << q1 <<endl <<"p2   "<<q2<<endl;
	//bool r=((p[0]==t1.hull[0][0])&((p[1]<=t1.hull[0][1])&(p[1]>=t1.hull[1][1])|(p[1]>=t1.hull[0][1])&(p[1]<=t1.hull[1][1])));
	//bool r1=(p[1]>t1.hull[0][1]);
	//cout << r<< endl;
	int m=t1.FindMinX();   //индекс точки с минимальной Х-координатой                
	int n=t1.FindMaxX();
	cout <<"MIN   " << m << "             MAX   " << n <<endl;
	TPoint p3(1,4);
	t1=t1.CreateNewConvexHull(p3);
	cout << "t1.k    " <<t1.k<<endl;
	cout << "t1   "<< t1.hull[0][0] << t1.hull[0][1] <<endl << t1.hull[1][0] << t1.hull[1][1] << endl << t1.hull[2][0] << t1.hull[2][1] <<endl << t1.hull[3][0] << t1.hull[3][1] <<endl;
	*/system("pause");
	return 0;
}
