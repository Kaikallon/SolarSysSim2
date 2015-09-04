// Fill out your copyright notice in the Description page of Project Settings.

#include "SolarSysSim.h"


//Private default constructor
ABody::ABody()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	this->gConst = 1;
	this->mass = 1;
	this->dT = 1;
	this->vel = { 0, 0, 0 };
	this->pos = { 0, 0, 0 };


}
ABody::ABody(FVector vel, FVector pos, float mass, float radius)
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
void ABody::BeginPlay()
{
	Super::BeginPlay();
	pos = GetActorLocation();
	
}

// Called every frame
void ABody::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ABody::CalcForces(TArray<ABody*>& allBodies)
{
	//Reset all forces before calculating new ones
	this->Forces = { 0, 0, 0 };
	


	for (auto planet_itr((allBodies.CreateConstIterator())); planet_itr; planet_itr++)
	{
		//Check for it self, and skip
		if ((*planet_itr) == this) continue;

		float dist = this->GetDistanceTo((*planet_itr));
		float magnitude = -(gConst * mass * (*planet_itr)->mass) / pow(dist, 2);
		//CalcForces
		this->Forces.X += ((GetActorLocation().X - (*planet_itr)->GetActorLocation().X) * magnitude) / dist;
		this->Forces.Y += ((GetActorLocation().Y - (*planet_itr)->GetActorLocation().Y) * magnitude) / dist;
		this->Forces.Z += ((GetActorLocation().Z - (*planet_itr)->GetActorLocation().Z) * magnitude) / dist;
	}

}

void ABody::CalcAcc()
{
	acc.X = Forces.X / mass; 
	acc.Y = Forces.Y / mass;
	acc.Z = Forces.Z / mass;

}
void ABody::CalcVel()
{
	vel += acc; // * dT;
}
void ABody::CalcPos()
{
	pos += vel; // * dT;
	this->SetActorLocation(pos);


	//this->SetActorLocation(this->GetActorLocation() + vel);
	//pos += acc; // *dT;
}


