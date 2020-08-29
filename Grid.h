#pragma once
#include "Config.h"
#include "IShape.h"
#include <iostream>

class Grid
{
public:
	Grid();
	~Grid();
	void Initialize();
	void Update();
	void Show();
	void Random();
	
	

private:
	int m_grid[GRID_WIDTH][GRID_HEIGHT];
	bool m_initialized;
	IShape* m_current;
	IShape* m_next;
	
	
};

