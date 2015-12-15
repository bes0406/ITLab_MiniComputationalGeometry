#include "stdafx.h"
#include "TPoint.h"
#include "ConvexHull.h"
int main(int argc, _TCHAR* argv[])
{
	TPoint p(1,1);
	ConvexHull t(p);
	ConvexHull t1(p);
	cout << "p  " << p[0] <<"   "<<p[1] << endl << "t   " << t.hull[0][0] <<"   "<< t.hull[0][1] <<endl;
	TPoint p1(1,3);
	cout << "p1  " << p1[0] <<"   "<<p1[1] << endl;
	//int a=t.FindMinX();
	//cout << a <<endl ;
	//int k=t.FindRightSupportLine(p1);
	//bool fl=t.IsPointInHull(p);
	//cout << fl << endl;
	//cout << t.hull[0][0] <<"   " << t.hull[0][1] <<endl;
	cout << "t1   "<< t1.hull[0][0] << t1.hull[0][1] <<endl;
	t1=t1.CreateNewConvexHull(p1);
	cout << "t1.k    " <<t1.k<<endl;
	cout << "t1   " << endl << t1.hull[0][0] << t1.hull[0][1] <<endl << t1.hull[1][0] << t1.hull[1][1] << endl;
	TPoint p2(2,2);
	/*int l=-1;
	cout << l<<endl;
	for (int i=0;i<t1.k; i++)
	{
		cout <<"i   " <<i<<endl;
		bool fl=true;
		cout << fl <<endl;
		int j=0;
		while ((fl)&&(j<t1.k))
		
		{
			if (t1.hull[j][1]*(p2[0]-t1.hull[i][0])-t1.hull[j][0]*(p2[1]-t1.hull[i][1])+p2[1]*t1.hull[i][0]-t1.hull[i][1]*p2[0]>0)
					fl=false;
		cout <<fl<<endl;
			
		j++;
		}
		cout << "Fl  " << fl << endl;
	if (fl) 
		if (l=-1)
			l=i;
		else
			if (p2.distance(t1.hull[l])<p2.distance(t1.hull[i]))
				l=i;
	}*/

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
	cout << "IsPoinrInHull" << endl << "p    " << q << endl << "p1   " << q1 <<endl <<"p2   "<<q2<<endl;
	//bool r=((p[0]==t1.hull[0][0])&((p[1]<=t1.hull[0][1])&(p[1]>=t1.hull[1][1])|(p[1]>=t1.hull[0][1])&(p[1]<=t1.hull[1][1])));
	//bool r1=(p[1]>t1.hull[0][1]);
	//cout << r<< endl;
	system("pause");
	return 0;
}
