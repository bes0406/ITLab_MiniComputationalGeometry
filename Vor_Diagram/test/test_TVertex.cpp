#include "TVertex.h"
#include "gtest.h"

/*---------------------------------------------------------------------------------------*/
// Тестирование класса <TVertex>
/*---------------------------------------------------------------------------------------*/

TEST(TVertex, can_create_vertex_from_a_point) // Могу создать вершину из точки (создание коректное)
{
	TPoint P(3.3,4.4);
	ASSERT_NO_THROW( TVertex V(P) );
	TVertex V(P);
	EXPECT_EQ(P, V.Get_Point());
	EXPECT_EQ( (&V), V.Get_pNext_Vertex() );
	EXPECT_EQ( (&V), V.Get_pPrev_Vertex() );
}
/*---------------------------------------------------------------------------------------*/

TEST(TVertex, can_create_vertex_from_a_coordinates) // Могу создать вершину из координат
{
	ASSERT_NO_THROW( TVertex V(3.3, 4.4) );
	TVertex V(3.3, 4.4);
	TPoint P(3.3, 4.4);
	EXPECT_EQ(P, V.Get_Point() );
	EXPECT_EQ( (&V), V.Get_pNext_Vertex() );
	EXPECT_EQ( (&V), V.Get_pPrev_Vertex() );
}
/*---------------------------------------------------------------------------------------*/

TEST(TVertex, can_correctly_insert_vertex) // могу вставить вершину, вставка коректна
{
	TVertex V1(3.3, 4.4);
	TVertex V2(5.5, 7.7);
	TVertex V3(2.2, 1.1);

	V1.Insert_Vertex(&V2);
	V2.Insert_Vertex(&V3);

	EXPECT_EQ(&V2, V1.Get_pNext_Vertex());
	EXPECT_EQ(&V3, V1.Get_pPrev_Vertex());

	EXPECT_EQ(&V3, V2.Get_pNext_Vertex());
	EXPECT_EQ(&V1, V2.Get_pPrev_Vertex());

	EXPECT_EQ(&V1, V3.Get_pNext_Vertex());
	EXPECT_EQ(&V2, V3.Get_pPrev_Vertex());
}
/*---------------------------------------------------------------------------------------*/

TEST(TVertex, can_correctly_remove_vertex) // могу коректно удалить вершину
{
	TVertex V1(3.3, 4.4);
	TVertex V2(5.5, 7.7);
	TVertex V3(2.2, 1.1);

	V1.Insert_Vertex(&V2);
	V2.Insert_Vertex(&V3);

	ASSERT_NO_THROW( V2.Remove_Vertex());

	EXPECT_EQ(&V3, V1.Get_pNext_Vertex());
	EXPECT_EQ(&V3, V1.Get_pPrev_Vertex());

	EXPECT_EQ(&V1, V3.Get_pNext_Vertex());
	EXPECT_EQ(&V1, V3.Get_pPrev_Vertex());
}
/*---------------------------------------------------------------------------------------*/

TEST(TVertex, can_get_neighbor) // могу получить соседа по часовой стрелки и против
{
    TVertex V1(3.3, 4.4);
	TVertex V2(5.5, 7.7);
	TVertex V3(2.2, 1.1);

	V1.Insert_Vertex(&V2);
	V2.Insert_Vertex(&V3);

	EXPECT_EQ(&V1, V2.Neighbor(COUNTER_CLOCKWISE) );
	EXPECT_EQ(&V3, V2.Neighbor(CLOCKWISE) );
}
/*---------------------------------------------------------------------------------------*/

TEST(TVertex, can_get_point) // могу получить точку, в которой находится текущая вершина
{
	TPoint P(3.2, 3.2);
	TVertex V(P);
	EXPECT_EQ(P,V.Get_Point());
}
/*---------------------------------------------------------------------------------------*/