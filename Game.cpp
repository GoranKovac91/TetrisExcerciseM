#include "Game.h"
#include <cstdlib>
#include <Windows.h>
#include <thread>
#include <chrono>

Game::Game()
{
}


Game::~Game()
{
}

void Game::Update()
{
	std::cout << "Game is running!" << std::endl;
	m_grid.Update();
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

void Game::Start()
{
	m_isRunning = true;
	m_grid = Grid();
	m_grid.Initialize();
}
