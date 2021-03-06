// Fill out your copyright notice in the Description page of Project Settings.

#include "SolarSysSim.h"
#include "SolarSysSimGameMode.h"

ASolarSysSimGameMode::ASolarSysSimGameMode()
{
	PrimaryActorTick.bCanEverTick = true;
	//AActor::SetActorTickEnabled(true); ??
	dT = 1;
}

void ASolarSysSimGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	GetAllBodies(GetWorld());
	UpdateAllBodies();
}
void ASolarSysSimGameMode::BeginPlay()
{
	
}

UWorld* ASolarSysSimGameMode::WorldGet()
{
	return this->GetWorld();
}

void ASolarSysSimGameMode::UpdateAllBodies()
{
	//Calculate all bodies' velocity
	for (auto body(allBodies.CreateIterator()); body; body++)
	{
		//(*body)->PerformThreadedTask(CalcVel);
		(*body)->CalcForces(allBodies);
		(*body)->CalcVel();
		(*body)->CalcPos();
		
	}
	//Check for collisions
	for (auto first(allBodies.CreateIterator()); first; first++)
	{
		if (!(*first)->IsPendingKill())
		{
			for (auto second(first + 1); second; second++)
			{
				if (!(*second)->IsPendingKill()) //Maybe also make sure that second != first?? Shouldn't need to
				{
					//Here we have two bodies, none of which are pending kill
					//Now we can do stuff
					if ((*first)->Overlap(*second)) //Check if they overlap
					{
						//Create new body here
						(*first)->MergeBodies(*second);
					}
				}
			}
		}
	}
}

void ASolarSysSimGameMode::GetAllBodies(UWorld* World)
{


	//Empty the list of bodies, otherwise there would be duplicates
	allBodies.Empty();

	//Iterate though all actors, and select valid 'ABody'-ones
	for (FActorIterator It(World); It; ++It)
	{
		AActor* Actor = *It;
		if (Actor != NULL && !Actor->IsPendingKill() && Actor->IsA(ABody::StaticClass()))
		{
			allBodies.Add((ABody*)Actor);
		}
	}

}


