#include "TVertex.h"
#include <iostream>

// Класс "Многоугольник"

class TPolygon{
private:
	TVertex* pVertex; // Окно многоугольника (текущая акивная вершина мн-ка)
	int Size;  // Кол-во вершин в многоугольнике
private:
    void Resize(void); // пересчитывает кол-во вершин в многоугольнике
public:
	TPolygon(void); // Конструктор
	TPolygon(TVertex* pV); // Создает мн-к на основе двухсвязного списка вершин
	TPolygon(TPolygon& Pol); // К-р копирования
	~TPolygon(void); // Деструктор

//  Функции осуществляющие доступ к многоугольнику

	TVertex* Get_Vertex(void) const; // Получить текущую вершину мн-ка
	int Get_Size(void) const; // Получить размер мн-ка
	TPoint Get_Point(void) const; // Получить точку, соотвествующую текущей вершине мн-ка
//  Edge Get_Edge(void) const; // Получить текущее ребро (началов в тек. вершине, конец в след.)

	TVertex* Get_Next_Vertex(void) const; // Возвращает след. вершину после текущей без изменения окна
	TVertex* Get_Prev_Vertex(void) const;
	TVertex* Neighbor(int _rotation) const; 

// Функции изменения состояния мн-ка
	TVertex* Advance(int _rotation); // Перемещает окно (изменяет текущую вершину мн-ка)
	TVertex* Advance_Set_Vertex(TVertex* pV); // Перемещает окно на заданную вершину

	TVertex* Insert_Vertex(TPoint& _point);// Добавляет вершину после текущей и передвигает окно на нов. вершину
	void Remove_Vertex(void); // Удаляет тек. вершину, окно на предшественника

// Разделение полигонов
	TPolygon* Split_Polygon(TVertex* pV); // Разрезает текущий полигон вдоль хорды соед. текущую вершину с вершиной *pV. Тек. Вершина не измен.
	                                      // Возвращает указатель на новый полигон, текущая вершина которого *copy_pV
};