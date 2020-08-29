#pragma once
class Matrix4x4
{
public:
	Matrix4x4();
	~Matrix4x4();

	void Rotate();

	int m00, m01, m02, m03;
	int m10, m11, m12, m13;
	int m20, m21, m22, m23;
	int m30, m31, m32, m33;
};

