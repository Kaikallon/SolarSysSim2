// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "body.generated.h"


UCLASS()
class SOLARSYSSIM_API Abody : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Abody(FVector vel, FVector pos, float mass, float radius);


	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	//Metoder

	void CalcForces(Abody* planB);
	void CalcAcc();
	void CalcVel();
	void CalcPos();
	
private:
	Abody();

	//Variabler
	FVector Forces, acc, vel, pos;
	float mass, dT, radius;
	float gConst;  //Make static

};
