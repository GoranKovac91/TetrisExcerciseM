#include "RhodeIslandZ.h"
#include "Config.h"
#include <conio.h>



RhodeIslandZ::RhodeIslandZ()
{
	m_type = ShapeType::ERhodeIslandZ;
	m_shapeTiles.m00 = 0;	m_shapeTiles.m01 = 0; m_shapeTiles.m02 = 0; m_shapeTiles.m03 = 0;
	m_shapeTiles.m10 = 0;	m_shapeTiles.m11 = 0; m_shapeTiles.m12 = 1; m_shapeTiles.m13 = 1;
	m_shapeTiles.m20 = 0;	m_shapeTiles.m21 = 1; m_shapeTiles.m22 = 1; m_shapeTiles.m23 = 0;
	m_shapeTiles.m30 = 0;	m_shapeTiles.m31 = 0; m_shapeTiles.m32 = 0; m_shapeTiles.m33 = 0;

	m_lastRotation = m_shapeTiles;
	m_position = Vector2(GRID_WIDTH / 2, 0);
	m_lastPosition = Vector2(GRID_WIDTH / 2, -1);
	m_endReached = false;
}


RhodeIslandZ::~RhodeIslandZ()
{
}

void RhodeIslandZ::Update()
{
	char key = std::getchar();
	m_lastPosition = m_position;
	if (key == 'r')
	{
		Rotate();
	}
	if (key == 'a')
	{
		m_position.x--;
	}
	if (key == 'd')
	{
		m_position.x++;
	}

	if (m_position.y < GRID_HEIGHT - 2)
	{
		m_position.y++;
	}
	else
	{
		m_endReached = true;
	}
}

std::vector<std::pair<int, int>> RhodeIslandZ::LastIndices()
{
	std::vector<std::pair<int, int>> indices;
	// first row
	if (m_lastRotation.m00 == 1 && m_lastPosition.y > 0)
	{
		indices.push_back(std::make_pair<int, int>(m_lastPosition.x - 1, m_lastPosition.y - 1));
	}
	if (m_lastRotation.m01 == 1 && m_lastPosition.y > 0)
	{
		indices.push_back(std::make_pair<int, int>(m_lastPosition.x - 0, m_lastPosition.y - 1));
	}
	if (m_lastRotation.m02 == 1 && m_lastPosition.y > 0)
	{
		indices.push_back(std::make_pair<int, int>(m_lastPosition.x + 1, m_lastPosition.y - 1));
	}
	if (m_lastRotation.m03 == 1 && m_lastPosition.y > 0)
	{
		indices.push_back(std::make_pair<int, int>(m_lastPosition.x + 2, m_lastPosition.y - 1));
	}

	// second row
	if (m_lastRotation.m10 == 1 && m_lastPosition.y > -1)
	{
		indices.push_back(std::make_pair<int, int>(m_lastPosition.x - 1, m_lastPosition.y - 0));
	}
	if (m_lastRotation.m11 == 1 && m_lastPosition.y > -1)
	{
		indices.push_back(std::make_pair<int, int>(m_lastPosition.x - 0, m_lastPosition.y - 0));
	}
	if (m_lastRotation.m12 == 1 && m_lastPosition.y > -1)
	{
		indices.push_back(std::make_pair<int, int>(m_lastPosition.x + 0, m_lastPosition.y - 0));
	}
	if (m_lastRotation.m13 == 1 && m_lastPosition.y > -1)
	{
		indices.push_back(std::make_pair<int, int>(m_lastPosition.x + 1, m_lastPosition.y - 0));
	}

	// third row
	if (m_lastRotation.m20 == 1)
	{
		indices.push_back(std::make_pair<int, int>(m_lastPosition.x - 1, m_lastPosition.y + 1));
	}
	if (m_lastRotation.m21 == 1)
	{
		indices.push_back(std::make_pair<int, int>(m_lastPosition.x - 1, m_lastPosition.y + 1));///
	}
	if (m_lastRotation.m22 == 1)
	{
		indices.push_back(std::make_pair<int, int>(m_lastPosition.x + 0, m_lastPosition.y + 1));
	}
	if (m_lastRotation.m23 == 1)
	{
		indices.push_back(std::make_pair<int, int>(m_lastPosition.x + 2, m_lastPosition.y + 1));
	}

	// Fourth row
	if (m_shapeTiles.m30 == 1)
	{
		indices.push_back(std::make_pair<int, int>(m_lastPosition.x - 1, m_lastPosition.y + 2));
	}
	if (m_shapeTiles.m31 == 1)
	{
		indices.push_back(std::make_pair<int, int>(m_lastPosition.x - 0, m_lastPosition.y + 2));
	}
	if (m_shapeTiles.m32 == 1)
	{
		indices.push_back(std::make_pair<int, int>(m_lastPosition.x + 1, m_lastPosition.y + 2));
	}
	if (m_shapeTiles.m33 == 1)
	{
		indices.push_back(std::make_pair<int, int>(m_lastPosition.x + 2, m_lastPosition.y + 2));
	}

	m_lastRotation = m_shapeTiles;
	return indices;
}

std::vector<std::pair<int, int>> RhodeIslandZ::CurrentIndices()
{
	std::vector<std::pair<int, int>> indices;
	// first row
	if (m_shapeTiles.m00 == 1 && m_position.y > 0)
	{
		indices.push_back(std::make_pair<int, int>(m_position.x - 1, m_position.y - 1));
	}
	if (m_shapeTiles.m01 == 1 && m_position.y > 0)
	{
		indices.push_back(std::make_pair<int, int>(m_position.x - 0, m_position.y - 1));
	}
	if (m_shapeTiles.m02 == 1 && m_position.y > 0)
	{
		indices.push_back(std::make_pair<int, int>(m_position.x + 1, m_position.y - 1));
	}
	if (m_shapeTiles.m03 == 1 && m_position.y > 0)
	{
		indices.push_back(std::make_pair<int, int>(m_position.x + 2, m_position.y - 1));
	}

	// second row
	if (m_shapeTiles.m10 == 1)
	{
		indices.push_back(std::make_pair<int, int>(m_position.x - 1, m_position.y - 0));
	}
	if (m_shapeTiles.m11 == 1)
	{
		indices.push_back(std::make_pair<int, int>(m_position.x - 0, m_position.y - 0));
	}
	if (m_shapeTiles.m12 == 1)
	{
		indices.push_back(std::make_pair<int, int>(m_position.x + 0, m_position.y - 0));
	}
	if (m_shapeTiles.m13 == 1)
	{
		indices.push_back(std::make_pair<int, int>(m_position.x + 1, m_position.y - 0));
	}

	// third row
	if (m_shapeTiles.m20 == 1)
	{
		indices.push_back(std::make_pair<int, int>(m_position.x - 1, m_position.y + 1));
	}
	if (m_shapeTiles.m21 == 1)
	{
		indices.push_back(std::make_pair<int, int>(m_position.x - 1, m_position.y + 1));////0
	}
	if (m_shapeTiles.m22 == 1)
	{
		indices.push_back(std::make_pair<int, int>(m_position.x + 0, m_position.y + 1));
	}
	if (m_shapeTiles.m23 == 1)
	{
		indices.push_back(std::make_pair<int, int>(m_position.x + 2, m_position.y + 1));
	}

	// Fourth row
	if (m_shapeTiles.m30 == 1)
	{
		indices.push_back(std::make_pair<int, int>(m_position.x - 1, m_position.y + 2));
	}
	if (m_shapeTiles.m31 == 1)
	{
		indices.push_back(std::make_pair<int, int>(m_position.x - 0, m_position.y + 2));
	}
	if (m_shapeTiles.m32 == 1)
	{
		indices.push_back(std::make_pair<int, int>(m_position.x + 1, m_position.y + 2));
	}
	if (m_shapeTiles.m33 == 1)
	{
		indices.push_back(std::make_pair<int, int>(m_position.x + 2, m_position.y + 2));
	}

	return indices;
}


