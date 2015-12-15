#include "TPoint.h"
#pragma once
class ConvexHull
{
public:
	TPoint *hull;   //������ ��� �������� ����� �������� ��������
	int k;   //���������� ����� � �������� ��������
	ConvexHull(TPoint p); //�����������
	ConvexHull(const ConvexHull &a);  //����������� �����������
	~ConvexHull(void);  //����������
	ConvexHull& operator=(const ConvexHull &a); //������������
	int FindMaxX();  //������ ����� � ������������ �-�����������
	int FindMinX();  //������ ����� � ����������� �-�����������
	bool IsPointInHull(TPoint p);  //true ���� ����� ����������� �������� ��������
	int FindLeftSupportLine(TPoint p);   //����� ����� ������� ������
	int FindRightSupportLine(TPoint p);   //����� ������ ������� ������
	ConvexHull CreateNewConvexHull(TPoint p);
};

