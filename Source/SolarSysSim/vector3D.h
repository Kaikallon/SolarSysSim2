#pragma once
#include "Vector.h"
class UVectorDouble 
{

public:
	double X, Y, Z;

public:

	UVectorDouble();
	UVectorDouble(double x, double y, double z);
	//FORCEINLINE Uvector3D(const Uvector3D &source); //Copy-konstruktor


	UVectorDouble& operator= (const UVectorDouble& source)
	{
		X = source.X;
		Y = source.Y;
		Z = source.Z;

		return *this;
	}
	UVectorDouble& operator= (const FVector& source)
	{
		X = source.X;
		Y = source.Y;
		Z = source.Z;

		return *this;
	}



	UVectorDouble operator+=(const UVectorDouble& V)
	{
		X += V.X; Y += V.Y; Z += V.Z;
		return *this;
	}



	//Operators
	//friend UVectorDouble operator+(const UVectorDouble &a, const UVectorDouble &b);


	//void Reset();

	
};
//UVectorDouble operator+(const Uvector3D &a, const Uvector3D &b)
//{
//	return Uvector3D(a.x + b.x, a.y + b.y, a.z + b.z);
//}
//#ifdef IMPLEMENT_ASSIGNMENT_OPERATOR_MANUALLY
//
//FORCEINLINE Uvector3D& Uvector3D::operator=(const Uvector3D& source)
//{
//	//UObject::operator=(source);
//	x = source.x;
//	y = source.y;
//	z = source.z;
//	return *this;
//}
//#endif

//FORCEINLINE Uvector3D::Uvector3D(const Uvector3D &source)
//	: UObject(source)
//{
//
//	this->x = source.x;
//	this->y = source.y;
//	this->z = source.z;
//}

