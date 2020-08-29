#include "Matrix4x4.h"

Matrix4x4::Matrix4x4()
{
}


Matrix4x4::~Matrix4x4()
{
}

void Matrix4x4::Rotate()
{
	Matrix4x4 temp = Matrix4x4();

	temp.m00 = m30; temp.m01 = m20; temp.m02 = m10; temp.m03 = m00;
	temp.m10 = m31; temp.m11 = m21; temp.m12 = m11; temp.m13 = m01;
	temp.m20 = m32; temp.m21 = m22; temp.m22 = m12; temp.m23 = m02;
	temp.m30 = m33; temp.m31 = m23; temp.m32 = m13; temp.m33 = m03;


	m00 = temp.m00; m01 = temp.m01; m02 = temp.m02; m03 = temp.m03;
	m10 = temp.m10; m11 = temp.m11; m12 = temp.m12; m13 = temp.m13;
	m20 = temp.m20; m21 = temp.m21; m22 = temp.m22; m23 = temp.m23;
	m30 = temp.m30; m31 = temp.m31; m32 = temp.m32; m33 = temp.m33;
}
