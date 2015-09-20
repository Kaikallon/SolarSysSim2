// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "vector3D.h"
#include "GameFramework/Actor.h"
#include "body.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(Critical, Log, All);

UCLASS()
class SOLARSYSSIM_API ABody : public AActor
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Body)
		FVector setVel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Body)
		float setMass;
	
public:	
	// Sets default values for this actor's properties
	ABody(UVectorDouble vel, float mass, float radius);
	void Initialize(UVectorDouble vel, float mass, float radius);
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	//--------------

	//Forces and such
	void CalcForces(TArray<ABody*>& allBodies);
	void CalcVel();
	void CalcPos();
	
	//Collision related
	bool			Overlap						(ABody* other);
	void			MergeBodies					(ABody* other);
	double			CalcNewRadius				(ABody* other);
	UVectorDouble	CalcNewVel					(ABody *other);
	UVectorDouble	CalcDistanceToCentreOfMass	(ABody* other);
	


	//Variabler
	UVectorDouble Forces, pos, vel;

	double mass;
	float* dT;
	float radius;

private:
	ABody();

};
