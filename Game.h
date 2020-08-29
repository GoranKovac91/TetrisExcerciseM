#pragma once

#include <iostream>
#include "Grid.h"
class Game
{
public:
	Game();
	~Game();
	void Update();
	void Start();
	bool IsRunning() { return m_isRunning; };

private:
	bool m_isRunning;
	Grid m_grid;
};
