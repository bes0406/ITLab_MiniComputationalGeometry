#include "TPolygon.h"

/*-----------------------------------------------------------------------------------*/
TPolygon:: TPolygon(void) //  -р по умолчанию "пустой мн-к"
{
	pVertex = NULL;
	Size = 0;
}
/*-----------------------------------------------------------------------------------*/

TPolygon:: TPolygon(TVertex* pV)
{
	pVertex = new TVertex( pV -> Get_Point());
	TVertex* count_v = pV -> Neighbor(CLOCKWISE);
	while( pV != count_v) 
	{
		TVertex* V = new TVertex(count_v -> Get_Point());
		pVertex = pVertex -> Insert_Vertex(V);
		count_v = count_v -> Neighbor(CLOCKWISE);
	}
	pVertex = pVertex ->Get_pNext_Vertex();
	Resize(); // ¬ычисл€ем кол-во вершин в списке pV
}

/*-----------------------------------------------------------------------------------*/
void TPolygon::Resize(void) // ¬ычисл€ет кол-во вершин
{
	if (pVertex == NULL)
		Size = 0;
	else {
		TVertex* pV = pVertex -> Get_pNext_Vertex();
		for( Size = 1; pV != pVertex; ++Size)
			pV = pV -> Get_pNext_Vertex();
	}
}
/*-----------------------------------------------------------------------------------*/

TPolygon:: TPolygon(TPolygon& Pol) //  онструктор копировани€
{
	if( Pol.pVertex == NULL ) // если мн-к пустой
	{
		pVertex = NULL;
		Size = 0;
	}
	else{
		Size = Pol.Size;
		pVertex = new TVertex( Pol.Get_Point() ); // —оздаем текущую вершину по точке
		for(int i = 1; i < Size; ++i) // i = 1 - нулева€ вершина уже создана
		{
			Pol.Advance(CLOCKWISE); // двигаем окно по часовой стрелки у Pol
			TVertex* V = new TVertex( Pol.Get_Point() ); // создаем копию очередной вершины
			pVertex = pVertex -> Insert_Vertex(V); // добавл€ем вершину к уже созданным и передвигем окно у *this
		}
		Pol.Advance(CLOCKWISE); // возвращаем окно в исходное состо€ние
		pVertex = pVertex -> Get_pNext_Vertex(); // тек. вершина *this совпадает с Pol
	}
}
/*-----------------------------------------------------------------------------------*/
TPolygon::~TPolygon(void) // ƒеструктор
{
	if( pVertex != NULL) 
	{
		TVertex* temp = pVertex -> Get_pNext_Vertex();
		while( pVertex != temp)
		{
			delete ( temp -> Remove_Vertex() ); // »звлекаем вершину из полигона и удал€ем ее
			temp = pVertex -> Get_pNext_Vertex(); // ѕредвигаем
		}
		delete pVertex; // удал€ем оставшуюс€ вершину
	}
}
/*-----------------------------------------------------------------------------------*/

// ‘ункции осуществл€ющие доступ к многоугольнику

/*-----------------------------------------------------------------------------------*/

TVertex* TPolygon:: Get_Vertex(void) const // ѕолучить текущую вершину
{
	return pVertex;
}
/*-----------------------------------------------------------------------------------*/
int TPolygon:: Get_Size(void) const // ѕолучить размер 
{
	return Size;
}
/*-----------------------------------------------------------------------------------*/

TPoint TPolygon:: Get_Point(void) const // ѕолучить точку, соотвествующую текущей вершине мн-ка
{
	return (pVertex -> Get_Point());
}
/*-----------------------------------------------------------------------------------*/

TVertex* TPolygon:: Get_Next_Vertex(void) const // ¬озвращает след. вершину после текущей без изменени€ окна
{
	return ( pVertex -> Get_pNext_Vertex() );
}
/*-----------------------------------------------------------------------------------*/

TVertex* TPolygon:: Get_Prev_Vertex(void) const // ¬озвр. предыдущую верш. после тек. без изменени€ окна
{
	return ( pVertex -> Get_pPrev_Vertex() );
}
/*-----------------------------------------------------------------------------------*/

TVertex* TPolygon:: Neighbor(int _rotation) const // _rotation (= {CLOCKWISE, COUNTER_CLOCKWISE}
{
	return ( pVertex -> Neighbor(_rotation) );
}
/*-----------------------------------------------------------------------------------*/

// ‘ункции измен€ющие состо€ние многоугольника

/*-----------------------------------------------------------------------------------*/

TVertex* TPolygon:: Advance(int _rotation) // ѕеремещает окно (измен€ет текущую вершину мн-ка) возвращает ук-ть на активную вершину
{
	pVertex = pVertex -> Neighbor(_rotation);
	return pVertex;
}
/*-----------------------------------------------------------------------------------*/

TVertex* TPolygon:: Advance_Set_Vertex(TVertex* pV) // ѕеремещает окно на заданную вершину
{
	// ѕроверка приналежности текущей вершины
	pVertex = pV;
	return pVertex;
}
/*-----------------------------------------------------------------------------------*/

TVertex* TPolygon:: Insert_Vertex(TPoint& _point) // ƒобавл€ет вершину после текущей и передвигает окно на нов. вершину
{
	if ( Size == 0)
	{
		++Size;
		pVertex = new TVertex(_point);
	} 
	else {
		TVertex* pV = new TVertex(_point); // создем вершину
		pVertex = pVertex -> Insert_Vertex(pV); // ¬ставл€ем вершину после текущей и передвигаем окно
		Size++;
	}
	return pVertex;
}
/*-----------------------------------------------------------------------------------*/
void TPolygon:: Remove_Vertex(void) // ”дал€ет тек. вершину, окно на предшественника
{
	if( pVertex != NULL) 
	{
		TVertex* pV = pVertex;
		--Size;
		if(Size)
			pVertex = NULL; // если больше нет вершин
		else // иначе предвигаем окно и удал€ем вершину
			pVertex = pVertex -> Get_pPrev_Vertex(); 
		delete pV;
	}
}
/*-----------------------------------------------------------------------------------*/
TPolygon* TPolygon:: Split_Polygon(TVertex* pV)
{
	TVertex* copy_pV = pVertex -> Split(pV);
	Resize(); // ѕересчитываем размер текущего полигона после разрезани€
	TPolygon* pPol = new TPolygon(copy_pV); // cоздаем нов. полигон с текущей вершиной *copy_pV
	return pPol;
}
/*-----------------------------------------------------------------------------------*/










