#pragma once
#include "IShape.h"
#include <iostream>

class ClevelandZ : public IShape
{
public:
	ClevelandZ();
	~ClevelandZ();

	void Show();
	void Update() override;
	std::vector<std::pair<int, int>> LastIndices() override;
	std::vector<std::pair<int, int>> CurrentIndices() override;
};

