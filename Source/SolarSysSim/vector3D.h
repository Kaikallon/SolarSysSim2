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
		X += V.X; 
		Y += V.Y; 
		Z += V.Z;
		return *this;
	}
	UVectorDouble operator-=(const UVectorDouble& V)
	{
		X -= V.X;
		Y -= V.Y;
		Z -= V.Z;
		return *this;
	}
	UVectorDouble operator*(const float& V)
	{
		X *= V; 
		Y *= V; 
		Z *= V;
		return *this;
	}
	UVectorDouble operator/(const float& V)
	{
		X /= V;
		Y /= V;
		Z /= V;
		return *this;
	}
	friend UVectorDouble operator+(const UVectorDouble& c1, const UVectorDouble& c2);
	friend UVectorDouble operator-(const UVectorDouble& c1, const UVectorDouble& c2);

	//Functions
	double GetDistanceTo(UVectorDouble& other)
	{
		return 
			sqrt
			(
				pow((X - other.X), 2) + 
				pow((Y - other.Y), 2) + 
				pow((Z - other.Z), 2)
			);
	}

	
};

