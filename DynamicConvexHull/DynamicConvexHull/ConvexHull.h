#include "TPoint.h"
#pragma once
class ConvexHull
{
public:
	TPoint *hull;   //массив для хранения точек выпуклой оболочки
	int k;   //количество точек в выпуклой оболочке
	ConvexHull(TPoint p);
	~ConvexHull(void);
	int FindMaxX(ConvexHull a);  //индекс точки с максимальной Х-координатой
	int FindMinX(ConvexHull a);  //индекс точки с минимальной Х-координатой
	bool IsPointInHull(TPoint p, ConvexHull a);  //true если точка принадлежит выпуклой оболочке
};

