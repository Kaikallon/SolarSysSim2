// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "SolarSysSimGameMode.generated.h"


UCLASS()
class SOLARSYSSIM_API ASolarSysSimGameMode : public AGameMode
{
	GENERATED_BODY()
	
public:
	//Default constructor
	ASolarSysSimGameMode();

	//Functions
	virtual void Tick(float DeltaSeconds) override;
	virtual void BeginPlay() override;
	UWorld* WorldGet();
	void	UpdateAllBodies();
	void	GetAllBodies(UWorld* World);
	void	RemoveBodyFromList(ABody*);
	
	

	//Variables
	//Delta-time between frames
	UPROPERTY(EditAnywhere)
		float dT;
	//Pointers to all bodies of interest
	TArray<ABody*> allBodies;
};
