// Fill out your copyright notice in the Description page of Project Settings.

#include "EnergyBallActivation.h"


// Sets default values for this component's properties
UEnergyBallActivation::UEnergyBallActivation()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UEnergyBallActivation::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UEnergyBallActivation::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (SwitchMass0() == ActivationMass0 &&
		SwitchMass1() == ActivationMass1 &&
		SwitchMass2() == ActivationMass2 &&
		SwitchMass3() == ActivationMass3)
	{
		OnActivation.Broadcast();
	}
	else
	{
		OnDeactivation.Broadcast();
	}
}

float UEnergyBallActivation::SwitchMass0()
{
	float TotalMass0 = 0.f;
	// Find all the overlapping actors
	TArray<AActor*> OverlappingActors;
	if (!ActivationSwitch0) { return TotalMass0; }
	ActivationSwitch0->GetOverlappingActors(OverlappingActors);
	// Iterate through them adding their masses
	for (const auto* Actor : OverlappingActors)
	{
		TotalMass0 += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
	}
	return TotalMass0;
}

float UEnergyBallActivation::SwitchMass1()
{
	float TotalMass1 = 0.f;
	// Find all the overlapping actors
	TArray<AActor*> OverlappingActors;
	if (!ActivationSwitch1) { return TotalMass1; }
	ActivationSwitch1->GetOverlappingActors(OverlappingActors);
	// Iterate through them adding their masses
	for (const auto* Actor : OverlappingActors)
	{
		TotalMass1 += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
	}
	return TotalMass1;
}

float UEnergyBallActivation::SwitchMass2()
{
	float TotalMass2 = 0.f;
	// Find all the overlapping actors
	TArray<AActor*> OverlappingActors;
	if (!ActivationSwitch2) { return TotalMass2; }
	ActivationSwitch2->GetOverlappingActors(OverlappingActors);
	// Iterate through them adding their masses
	for (const auto* Actor : OverlappingActors)
	{
		TotalMass2 += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
	}
	return TotalMass2;
}

float UEnergyBallActivation::SwitchMass3()
{
	float TotalMass3 = 0.f;
	// Find all the overlapping actors
	TArray<AActor*> OverlappingActors;
	if (!ActivationSwitch3) { return TotalMass3; }
	ActivationSwitch3->GetOverlappingActors(OverlappingActors);
	// Iterate through them adding their masses
	for (const auto* Actor : OverlappingActors)
	{
		TotalMass3 += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
	}
	return TotalMass3;
}

