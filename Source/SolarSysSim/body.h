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
	ABody(UVectorDouble vel, UVectorDouble pos, float mass, float radius);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;


	//Metoder
	void CalcForces(TArray<ABody*>& allBodies);
	void CalcVel();
	void CalcPos();
//	UFUNCTION(BlueprintCallable, Category = Body)
//		void SetDoubles(float mass, FVector vel, FVector pos);

	
private:
	ABody();

	//Variabler
	UVectorDouble Forces, acc, pos, vel;

	double mass;
	float* dT;
	float radius;

	float gConst;  //Make static later


};
