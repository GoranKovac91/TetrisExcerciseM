#pragma once
#include "IShape.h"

class RhodeIslandZ : public IShape
{
public:
	RhodeIslandZ();
	~RhodeIslandZ();
	void Update() override;
	std::vector<std::pair<int, int>> LastIndices() override;
	std::vector<std::pair<int, int>> CurrentIndices() override;
};

