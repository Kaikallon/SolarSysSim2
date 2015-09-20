// Fill out your copyright notice in the Description page of Project Settings.

#include "SolarSysSim.h"

//#define true (rand() % 2 == 0)

DEFINE_LOG_CATEGORY(Critical);
//Private default constructor
ABody::ABody()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Default init
	Initialize({0, 0, 0}, 1, 1);

}
ABody::ABody(UVectorDouble vel, float mass, float radius)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Initialize(vel, mass, radius);
	
}
void ABody::Initialize(UVectorDouble vel, float mass, float radius)
{
	this->setMass = mass;
	this->mass = mass;
	this->vel = vel;
	
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
		//Split force into components, and add
		this->Forces += ((this->pos - (*planet_itr)->pos) * magnitude) / dist;
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



//Collisions ---------------------

bool ABody::Overlap(ABody* other)
{
	return pos.GetDistanceTo(other->pos) < (this->radius - other->radius);
}

void ABody::MergeBodies(ABody* other)
{

	this->mass += other->mass;
	pos += CalcDistanceToCentreOfMass(other);
	vel += CalcNewVel(other);
	radius = CalcNewRadius(other);
	
	other->Destroy();
}

double ABody::CalcNewRadius(ABody* other)
{
	double volume = (pow(this->radius, 3) * PI)
		+ (pow(other->radius, 3)* PI);

	double newRadius = pow(volume / PI, (double) 1 / (double) 3);
	return newRadius;
}

UVectorDouble ABody::CalcNewVel(ABody *other)
{
	//Impulslagen för oelastiska kollisioner
	return	((this->vel * this->mass) + (other->vel*other->mass)) / (this->mass + other->mass);
}

UVectorDouble ABody::CalcDistanceToCentreOfMass(ABody* other)
{
	//Returnerar avståndet två planeters masscentrum
	//return (planB -> mass * (this->pos.GetElement(plane)- planB->pos.GetElement(plane))) / (this->mass * planB->mass);
	return  ((this->pos*this->mass) + (other->pos * other->mass)) / (this->mass + other->mass);
}