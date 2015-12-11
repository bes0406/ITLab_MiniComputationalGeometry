# include "set_points.h"

using namespace std;

class ConvexHull  
{
	SetPoints hull; // ��������, ��������� �� ������ �����
	int HullSize;
public:

	ConvexHull (int _HullSize ); 
	ConvexHull ( const ConvexHull &h);
	TPoint operator[] (int i);

	TPoint left (); // ���������� ����� ����� �����
	TPoint right(); // ���������� ����� ������ �����
	TPoint remote ( TPoint , TPoint , ConvexHull h); // �������� ��������� ����� �� ������ l

	ConvexHull Split (TPoint A, TPoint B, ConvexHull &above, ConvexHull &bellow);

	TPoint QiuckHull(); 

};


