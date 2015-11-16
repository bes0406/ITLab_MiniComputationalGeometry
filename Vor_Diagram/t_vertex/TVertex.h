#include "../t_point/TPoint.h"

// Класс "Вершина"


enum  ROTATION {CLOCKWISE, COUNTER_CLOCKWISE};
    //По часовой, против часовой стрелки

class TVertex
{
private:
	TPoint Point; // Точка
	TVertex* Next_Vertex; // Указатель на последователя (по часовой стрелки)
	TVertex* Prev_Vertex; // Указатеь на предшественника (против часовой стрелки)
	
public:
// Конструкторы
	TVertex(double _x, double _y); // Сздаем вершину на основе координат
	TVertex(const TPoint& _point); // Сздаем вершину на основе точки


// Операции с двухсвязным списком
	TVertex* Get_pNext_Vertex(void) const; // Возвращает указатель на след. вершину
	TVertex* Get_pPrev_Vertex(void) const; // Возвращает указатель на пред. вершину
	TVertex* Insert_Vertex(TVertex* pV); // Вставляет вершину после *this
	TVertex* Remove_Vertex(void); // Удаляет текущую вершину, возвращает указатель на нее

	void Splice_Vertex(TVertex* pV); // Cоединение двух вершин ????? (ХИТРОЕ)
	TVertex* Split(TVertex* pV); // Разрезает кольцевой список на два с добовлением копий

	TPoint Get_Point(void)const; // Возвращает точку, в которой находится текущая вершина
	TVertex* Neighbor(int _rotation); // Возвращает соседа при вращении по часовой, или против часовой стрелки
};
