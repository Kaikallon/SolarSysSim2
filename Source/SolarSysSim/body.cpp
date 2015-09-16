// Fill out your copyright notice in the Description page of Project Settings.

#include "SolarSysSim.h"

DEFINE_LOG_CATEGORY(Critical);
//Private default constructor
ABody::ABody()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	this->setMass = 1;
	this->mass = 1;
	this->vel = UVectorDouble{ 0, 0, 0 };
	this->pos = UVectorDouble{ 0, 0, 0 };

}
ABody::ABody(UVectorDouble vel, UVectorDouble pos, float mass, float radius)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	this->setMass = mass;
	this->mass = mass;
	this->vel = vel;
	this->pos = pos;

}

// Called when the game starts or when spawned
void ABody::BeginPlay()
{
	Super::BeginPlay();
	pos =  GetActorLocation();
	vel = setVel;
	mass = setMass;

	if (GetWorld() == NULL) { UE_LOG(Critical, Fatal, TEXT("No world! Pointer invalid!")) }
	dT = &((ASolarSysSimGameMode*)GetWorld()->GetAuthGameMode())->dT;
	
}

// Called every frame
void ABody::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ABody::CalcForces(TArray<ABody*>& allBodies)
{
	//Reset all forces before calculating new ones
	this->Forces = UVectorDouble{ 0, 0, 0 };
	


	for (auto planet_itr((allBodies.CreateConstIterator())); planet_itr; planet_itr++)
	{
		//Check for it self, and skip
		if ((*planet_itr) == this) continue;

		float dist = this->GetDistanceTo((*planet_itr));
		float magnitude = -(/*gConst * mass * */ (*planet_itr)->mass) / pow(dist, 2); //Skip it's own mass and gConst, and you get accelleration directly
		//CalcForces
		this->Forces.X += ((GetActorLocation().X - (*planet_itr)->GetActorLocation().X) * magnitude) / dist;
		this->Forces.Y += ((GetActorLocation().Y - (*planet_itr)->GetActorLocation().Y) * magnitude) / dist;
		this->Forces.Z += ((GetActorLocation().Z - (*planet_itr)->GetActorLocation().Z) * magnitude) / dist;
	}//mass *

}

void ABody::CalcVel()
{
	vel += Forces; //  * *dT);
}
void ABody::CalcPos()
{
	pos += vel; // * *dT);
	this->SetActorLocation({ (float)pos.X, (float)pos.Y, (float)pos.Z });

}

bool ABody::Overlap(ABody* other)

	return pos.GetDistanceTo(other->pos) < (this->radius - other->radius);
}