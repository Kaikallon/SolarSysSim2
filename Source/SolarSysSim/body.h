// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "vector3D.h"
#include "GameFramework/Actor.h"
#include "body.generated.h"


UCLASS()
class SOLARSYSSIM_API ABody : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABody(UVectorDouble vel, UVectorDouble pos, float mass, float radius);


	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	//Metoder

	void CalcForces(TArray<ABody*>& allBodies);
	void CalcAcc();
	void CalcVel();
	void CalcPos();

	
private:
	ABody();

	//Variabler
	UVectorDouble Forces, acc, pos, vel;
	UPROPERTY(EditAnywhere)
		FVector setVel;
	UPROPERTY(EditAnywhere)
		float setMass;
	double mass;
	float dT, radius;
	float gConst;  //Make static



};
