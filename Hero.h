#pragma once
#include "IShape.h"
#include <iostream>
class Hero : public IShape
{
public:
	Hero();
	~Hero();
	void Update() override;
	std::vector<std::pair<int, int>> LastIndices() override;
	std::vector<std::pair<int, int>> CurrentIndices() override;

	void Show();
};

