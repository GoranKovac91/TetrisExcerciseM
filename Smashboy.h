#pragma once
#include "IShape.h"

class Smashboy : public IShape
{
public:
	Smashboy();
	~Smashboy();
	void Update() override;
	std::vector<std::pair<int, int>> LastIndices() override;
	std::vector<std::pair<int, int>> CurrentIndices() override;
};

