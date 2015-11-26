#include "StdAfx.h"
#include "ConvexHull.h"


ConvexHull::ConvexHull(TPoint p)
{
	k=1;
	hull=new TPoint[k];
	hull[0]=p;
}

ConvexHull::~ConvexHull(void)
{
	delete[] hull;
}

int ConvexHull:: FindMaxX(ConvexHull a) //индекс точки с максимальной Х-координатой
{
	int n=0;
	int xn=hull[0][0];
	for(int i=1; i<a.k; i++)
		if (hull[i][0]>xn)
		{
			xn=hull[i][0];
			n=i;
		};
	return n;
}

int ConvexHull:: FindMinX(ConvexHull a)  //индекс точки с минимальной Х-координатой
{
	int m=0;
	int xm=hull[0][0];
	for(int i=1; i<a.k; i++)
		if (hull[i][0]<xm)
		{
			xm=hull[i][0];
			m=i;
		};
	return m;
}

bool ConvexHull:: IsPointInHull(TPoint p, ConvexHull a)  //true если точка принадлежит выпуклой оболочке
{
	int m=FindMinX(a);   //индекс точки с минимальной Х-координатой
	int n=FindMaxX(a);  //индекс точки с максимальной Х-координатой
	//создаем два массива - верхний и нижний, которые разделяет прямая MN
	int ku;  //размер верхнего массива
	int kd;   //размер нижнего массива
	TPoint *u;  //верхний массив
	TPoint *d;    //нижний массив
	if (m<n)
	{
		ku=a.k-(n-m-1);
		u=new TPoint[ku];
		kd=n-m+1;
		d=new TPoint[kd];
		int i=0;
		for (int j=m; j>=0; i++,j--)
			u[i]=a.hull[j];
		i++; //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		for (int j=a.k-1; j<=n; j++,i++)
			u[i]=a.hull[j];
		i=0;
		for (int j=m; j<=n; j++,i++)
			d[i]=a.hull[j];
	}
	else //if m>n !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!m=n
	{
		ku=n-m+1;
		u=new TPoint[ku];
		kd=a.k-(n-m-1);
		d=new TPoint[kd];
		int i=0;
		for (int j=m; j<=a.k; i++,j++)
			d[i]=a.hull[j];
		i++; //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		for (int j=0; j<=n; j++,i++)
			d[i]=a.hull[j];
		i=0;
		for (int j=m; j<=n; j++,i++)
			u[i]=a.hull[j];
	}
	bool fl=true;
	int i=0;
	while ((fl)&&(i<ku-1))
	{
		if (p[1]*(u[i][0]-u[i+1][0])-p[0]*(u[i][1]-u[i+1][1])+u[i][1]*u[i+1][0]-u[i+1][1]*u[i][0]>0)
			fl=false;
		i++;
	}
	i=0;
	while ((fl)&&(i<kd-1))
	{
		if (p[1]*(d[i][0]-d[i+1][0])-p[0]*(d[i][1]-d[i+1][1])+d[i][1]*d[i+1][0]-d[i+1][1]*d[i][0]<0)
			fl=false;
		i++;
	}
	return fl;
}

int FindLeftSupportLine(TPoint p, ConvexHull a)   //поиск левой опорной прямой
{
	int l=-1;
	for (int i=0;i<a.k; i++)
	{
		bool fl=true;
		int j=0;
		while ((fl)&&(j<a.k))
		{
			if (a.hull[j][1]*(p[0]-a.hull[i][0])-a.hull[j][0]*(p[1]-a.hull[i][1])+p[1]*a.hull[i][0]-a.hull[i][1]*p[0]>0)
				fl=false;
		j++;
		}
	if (fl) 
		if (l=-1)
			l=i;
		else
			if (p.distance(a.hull[l])<p.distance(a.hull[i]))
				l=i;
	i++;
	}
	return l;
}
int ConvexHull:: FindRightSupportLine(TPoint p, ConvexHull a)   //поиск правой опорной прямой
{
	int r=-1;
	for (int i=0;i<a.k; i++)
	{
		bool fl=true;
		int j=0;
		while ((fl)&&(j<a.k))
		{
			if (a.hull[j][1]*(p[0]-a.hull[i][0])-a.hull[j][0]*(p[1]-a.hull[i][1])+p[1]*a.hull[i][0]-a.hull[i][1]*p[0]<0)
				fl=false;
		j++;
		}
	if (fl) 
		if (r=-1)
			r=i;
		else
			if (p.distance(a.hull[r])<p.distance(a.hull[i]))
				r=i;
	i++;
	}
	return r;
}

/*ConvexHull ConvexHull:: CreateNewConvexHull(TPoint p, ConvexHull a)
{
	if (IsPointInHull(p,a))
		return a;
	else
	{
		int l=FindLeftSupportLine(p,a);
		int r=FindRightSupportLine(p,a);
		int knew; //размер нового массива
		if (r<l) 
			knew=a.k-(r-l-1)+1;
		else knew=-(r-l-1)+1;
		TPoint *b;
		b=new TPoint[knew];
		if (r>l)
		{
			int i=0;
			for (i;i<=l; i++)
				b[i]=a.hull[i];
			b[i+1]=p;  //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			for (int j=i+2, t=r; j<knew; j++,t++)
				b[j]=a.hull[t];
		}
		else //if (r<l) !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		{
			int j=0;
			for (int i=r; i<=l; i++,j++)
				b[j]=a.hull[i];
			b[j+1]=p;  //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		}
	}
	return a; //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!создать новую выпуклую оболочку. конструктор
}*/