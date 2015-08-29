// Fill out your copyright notice in the Description page of Project Settings.

#include "SolarSysSim.h"
#include "body.h"


// Sets default values
Abody::Abody()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	int test = 1;

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

