#pragma once
#include "IShape.h"

class OrangeRicky : public IShape
{
public:
	OrangeRicky();
	~OrangeRicky();
	void Show();
	void Update() override;
	std::vector<std::pair<int, int>> LastIndices() override;
	std::vector<std::pair<int, int>> CurrentIndices() override;
};

