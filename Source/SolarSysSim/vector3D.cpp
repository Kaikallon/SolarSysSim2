// Fill out your copyright notice in the Description page of Project Settings.

#include "SolarSysSim.h"



UVectorDouble::UVectorDouble()
{
	this->X = 0;
	this->Y = 0;
	this->Z = 0;
}
UVectorDouble::UVectorDouble(double x, double y, double z)
{
	this->X = x;
	this->Y = y;
	this->Z = z;
}

UVectorDouble operator+(const UVectorDouble& c1, const UVectorDouble& c2)
{
	return UVectorDouble(c1.X + c2.X, c1.Y + c2.Y, c1.Z + c2.Z);
}

UVectorDouble operator-(const UVectorDouble& c1, const UVectorDouble& c2)
{
	return UVectorDouble(c1.X - c2.X, c1.Y - c2.Y, c1.Z - c2.Z);
}