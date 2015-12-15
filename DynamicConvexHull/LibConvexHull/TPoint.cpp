#include "TPoint.h"


TPoint:: TPoint(double _x, double _y)                      //�����������
{
	x=_x;
	y=_y;
}
TPoint:: TPoint (const TPoint &p)
{
	x=p.x;
	y=p.y;
}
TPoint TPoint:: operator+ (TPoint &p)                  //����� ��������� �����
{
	TPoint q;
	q.x=x+p.x;
	q.y=y+p.y;
	return q;
}

TPoint TPoint:: operator- (TPoint &p)                   //�������� ��������� �����
{
	TPoint q;
	q.x=x-p.x;
	q.y=y-p.y;
	return q;
}

double TPoint:: operator[] (int i)                      //�������� ����������: ���������� ���������� � ��� [0] � ���������� y ��� [1]            
{
	if (i==0) return (x);
	else if (i==1) return (y);
	     else throw i;
}

bool TPoint:: operator== (const TPoint &p) const                    //true ���� ����� ��� �����
{
	return ((x==p.x)&&(y==p.y));
}

bool TPoint:: operator!= (TPoint &p)                    //true ���� ������� ��� �����
{
	return ((x!=p.x)||(y!=p.y));
}

bool TPoint:: operator< (TPoint &p)                      //true ���� ������ ����� ������ ������
{
	return ((x<p.x)||((x==p.x)&&(y<p.y)));
}

bool TPoint:: operator> (TPoint &p)                      //true ���� ������ ����� ������ ������
{
	return ((x>p.x)||((x==p.x)&&(y>p.y)));
}

double TPoint:: distance (TPoint &p)                              //���������� ����� ����� �������
{
	return (sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y)));
}

TPoint::~TPoint(void)                                    //����������
{
}
