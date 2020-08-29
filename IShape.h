#pragma once
#include "Vector2.h"
#include "Matrix4x4.h"
#include <vector>

enum ShapeType
{
	EOrangeRicky,
	EBlueRicky,
	EClevelandZ,
	ERhodeIslandZ,
	EHero,
	ETeewee,
	ESmashBoy
};

class IShape
{
public:
	IShape() {};
	~IShape() {};
	Matrix4x4 GetShape() { return m_shapeTiles; };
	ShapeType GetShapeType() { return m_type; };
	void Rotate() { m_lastRotation = m_shapeTiles;  m_shapeTiles.Rotate(); }
	bool IsEndReached() { return m_endReached; };
	bool Collision() { return m_collision; };
	void virtual Update() = 0;
	std::vector<std::pair<int, int>> virtual  LastIndices() = 0;
	std::vector<std::pair<int, int>> virtual  CurrentIndices() = 0;

protected:
	Vector2 m_position;
	Vector2 m_lastPosition;
	Matrix4x4 m_lastRotation;
	Matrix4x4 m_shapeTiles;
	ShapeType m_type;
	bool m_endReached;
	bool m_collision;
};

