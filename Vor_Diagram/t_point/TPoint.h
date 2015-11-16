#include <cmath>


enum Position{LEFT, RIGHT, BEYOND, BEHIND, BETWEEN, ORIGIN, DESTINATION}; // Положение точки относительно прямой
          //Слева, Cправа, Впереди, Позади, Между, Начало, Конец


// Класс "Точка"
class TPoint
{
protected:
	double x; // Координаты точки
	double y;
public:
	TPoint(double _x = 0.0, double _y = 0.0);
// Векторные операции
	TPoint operator+(const TPoint& P);
	TPoint operator-(const TPoint& P);
	friend TPoint operator*(const double scalar, const TPoint& P); // Cкаляр * TPoint
	double det(const TPoint& _P1, const TPoint& _P2); // Определитель векторов
// Операции отношения
	int operator<(const TPoint& P) const; // Лексикографический порядок
	int operator>(const TPoint& P) const;
	int operator==(const TPoint& P) const;
	int operator!=(const TPoint& P) const;
// Операция доступа к координатам
	double& operator[](const int i); // i = 0 -> x; i = 1 -> y

	double Lenght(); // Вазвращает длину вектора

	// Определяет положение точки оносительно направляющего вектора (отрезка) прямой 
	int Location(TPoint& P1, TPoint& P2); // P1 - начало, P2 - конец вектора
	//double Distation(const Edge& _E); // Вычисляет расстояние от заданной точки до прямой линии
};
	                                                 
                                                      

