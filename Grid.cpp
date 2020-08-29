#include "Grid.h"
#include "BlueRicky.h"
#include "OrangeRicky.h"
#include "ClevelandZ.h"
#include "RhodeIslandZ.h"
#include "Smashboy.h"
#include "Hero.h"
#include "Teewee.h"
#include "time.h"



Grid::Grid()
{
}


Grid::~Grid()
{
}

void Grid::Initialize()
{
	if (!m_initialized)
		return;
	m_initialized = true;
	m_current = nullptr;
	m_next = nullptr;
	for (size_t i = 0; i < GRID_WIDTH; i++)
	{
		for (size_t j = 0; j < GRID_HEIGHT; j++)
		{
			m_grid[i][j] = 0;
		}
	}
}

void Grid::Update()
{

	Random();
	// grid update logic
	if (m_current == nullptr)
		m_current = new OrangeRicky();
	m_current->Update();
	for (auto it : m_current->LastIndices())
	{
		m_grid[it.first][it.second] = 0;
	}

		for (auto it : m_current->CurrentIndices())
		{
			m_grid[it.first][it.second] = 1;

		}

		if (m_current->IsEndReached())
		{
			m_current = m_next;
		}
		/*if (m_current->Collision())
		{
			m_current = new Teewee;
		}
		*/
	
		Show();
}

		
	


void Grid::Show()
{
	
	system("CLS");
	std::cout << "--------------------------------------* Current grid layout *--------------------------------------" << std::endl;
	for (size_t i = 0; i < GRID_HEIGHT; i++)
	{
		for (size_t j = 0; j < GRID_WIDTH; j++)
		{
			std::cout << m_grid[j][i];
		
			
		}
		std::cout << std::endl;
		
	}
	
	std::cout << "--------------------------------------* END *--------------------------------------" << std::endl;
	 
}

void Grid::Random()
{
	srand(time(NULL));

	rand() % 6;
	if (rand() % 6 == 0)
	{
		m_next = new ClevelandZ();
	}
	else if (rand() % 6 == 1)
	{
		m_next = new BlueRicky();

	}
	else if (rand() % 6 == 2)
	{
		m_next = new Hero();
	}
	else if (rand() % 6 == 3)
	{
		m_next = new OrangeRicky();
	}
	else if (rand() % 6 == 4)
	{
		m_next = new RhodeIslandZ();
	}
	else if (rand() % 6 == 5)
	{
		m_next = new Teewee();
	}
	else if (rand() % 6 == 6)
	{
		m_next = new RhodeIslandZ();
	}
}




