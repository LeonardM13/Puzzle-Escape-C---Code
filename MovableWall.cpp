// Fill out your copyright notice in the Description page of Project Settings.

#include "MovableWall.h"


// Sets default values for this component's properties
UMovableWall::UMovableWall()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMovableWall::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMovableWall::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (WallTriggerMass() == TotalMass)
	{
		OnOpen.Broadcast();
	}
	else
	{
		OnClose.Broadcast();
	}
}

float UMovableWall::WallTriggerMass()
{
	float TotalMass = 0.f;
	// Find all the overlapping actors
	TArray<AActor*> OverlappingActors;
	if (!WallTrigger) { return TotalMass; }
	WallTrigger->GetOverlappingActors(OverlappingActors);
	// Iterate through them adding their masses
	for (const auto* Actor : OverlappingActors)
	{
		TotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
	}
	return TotalMass;
}

