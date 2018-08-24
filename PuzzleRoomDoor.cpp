// Fill out your copyright notice in the Description page of Project Settings.

#include "PuzzleRoomDoor.h"


// Sets default values for this component's properties
UPuzzleRoomDoor::UPuzzleRoomDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPuzzleRoomDoor::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UPuzzleRoomDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (TriggerPlatformMass0() == TriggerMass0 &&
        TriggerPlatformMass1() == TriggerMass1 &&
		TriggerPlatformMass2() == TriggerMass2 &&
		TriggerPlatformMass3() == TriggerMass3 &&
		TriggerPlatformMass4() == TriggerMass4 )
	
	{
		OnOpen.Broadcast();
	}
	else
	{
		OnClose.Broadcast();
	}
}

float UPuzzleRoomDoor::TriggerPlatformMass0()
{
	float TotalMass0 = 0.f;
	// Find all the overlapping actors
	TArray<AActor*> OverlappingActors;
	if (!TriggerPlatform0) { return TotalMass0; }
	TriggerPlatform0->GetOverlappingActors(OverlappingActors);
	// Iterate through them adding their masses
	for (const auto* Actor : OverlappingActors)
	{
		TotalMass0 += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
	}
	return TotalMass0;
}

float UPuzzleRoomDoor::TriggerPlatformMass1()
{
	float TotalMass1 = 0.f;
	// Find all the overlapping actors
	TArray<AActor*> OverlappingActors;
	if (!TriggerPlatform1) { return TotalMass1; }
	TriggerPlatform1->GetOverlappingActors(OverlappingActors);
	// Iterate through them adding their masses
	for (const auto* Actor : OverlappingActors)
	{
		TotalMass1 += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
	}
	return TotalMass1;
}

float UPuzzleRoomDoor::TriggerPlatformMass2()
{
	float TotalMass2 = 0.f;
	// Find all the overlapping actors
	TArray<AActor*> OverlappingActors;
	if (!TriggerPlatform2) { return TotalMass2; }
	TriggerPlatform2->GetOverlappingActors(OverlappingActors);
	// Iterate through them adding their masses
	for (const auto* Actor : OverlappingActors)
	{
		TotalMass2 += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
	}
	return TotalMass2;
}

float UPuzzleRoomDoor::TriggerPlatformMass3()
{
	float TotalMass3 = 0.f;
	// Find all the overlapping actors
	TArray<AActor*> OverlappingActors;
	if (!TriggerPlatform3) { return TotalMass3; }
	TriggerPlatform3->GetOverlappingActors(OverlappingActors);
	// Iterate through them adding their masses
	for (const auto* Actor : OverlappingActors)
	{
		TotalMass3 += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
	}
	return TotalMass3;
}

float UPuzzleRoomDoor::TriggerPlatformMass4()
{
	float TotalMass4 = 0.f;
	// Find all the overlapping actors
	TArray<AActor*> OverlappingActors;
	if (!TriggerPlatform4) { return TotalMass4; }
	TriggerPlatform4->GetOverlappingActors(OverlappingActors);
	// Iterate through them adding their masses
	for (const auto* Actor : OverlappingActors)
	{
		TotalMass4 += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
	}
	return TotalMass4;
}


