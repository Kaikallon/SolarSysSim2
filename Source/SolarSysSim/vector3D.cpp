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

