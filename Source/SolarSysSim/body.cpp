// Fill out your copyright notice in the Description page of Project Settings.

#include "SolarSysSim.h"
#include "body.h"


// Sets default values
Abody::Abody()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	this->gConst = 1;
	this->mass = 1;
	this->dT = 1;
	this->vel = { 0, 0, 0 };
	this->pos = { 0, 0, 0 };


}
Abody::Abody(FVector vel, FVector pos, float mass, float radius)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	this->gConst = 1;
	this->mass = mass;
	this->dT = 1;
	this->vel = vel;
	this->pos = pos;

}

// Called when the game starts or when spawned
void Abody::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void Abody::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void Abody::CalcForces(Abody* planB)
{
	//Reset all forces
	this->Forces.X = 0;
	this->Forces.Y = 0;
	this->Forces.Z = 0;

	float dist = this->GetDistanceTo(planB);
	float AbsForce = (gConst * mass * planB->mass)/ pow(dist, 2);
	//CalcForces
	this->Forces.X += (GetActorLocation().X - planB->GetActorLocation().X) / dist;
	this->Forces.Y += (GetActorLocation().Y - planB->GetActorLocation().Y) / dist;
	this->Forces.Z += (GetActorLocation().Z - planB->GetActorLocation().Z) / dist;

}

void Abody::CalcAcc()
{
	acc.X = Forces.X / mass; 
	acc.Y = Forces.Y / mass;
	acc.Z = Forces.Z / mass;
}
void Abody::CalcVel()
{
	vel += acc; // * dT;
}
void Abody::CalcPos()
{
	pos += acc; // *dT;
}