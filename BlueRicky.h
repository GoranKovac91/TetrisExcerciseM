#pragma once
#include "IShape.h"
#include <iostream>
#include <vector>

class BlueRicky : public IShape
{
public:
	BlueRicky();
	~BlueRicky();

	void Show();
	void Update() override;
	std::vector<std::pair<int, int>> LastIndices() override;
	std::vector<std::pair<int, int>> CurrentIndices() override;
};

