#pragma once
#include "IShape.h"
class Teewee : public IShape
{
public:
	Teewee();
	~Teewee();
	void Update() override;
	std::vector<std::pair<int, int>> LastIndices() override;
	std::vector<std::pair<int, int>> CurrentIndices() override;
};

