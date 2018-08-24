// Fill out your copyright notice in the Description page of Project Settings.

#include "LightSwitch.h"
#include "GameFramework/Actor.h"
#include "Components/RectLightComponent.h"

// Sets default values for this component's properties
ULightSwitch::ULightSwitch()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void ULightSwitch::BeginPlay()
{
	Super::BeginPlay();
	// ...
}


// Called every frame
void ULightSwitch::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (TotalActorMassOnTrigger() == TriggerMass)
	{
		GetOwner()->FindComponentByClass<URectLightComponent>()->SetIntensity(0.0f);
	}
}

float ULightSwitch::TotalActorMassOnTrigger()
{
	float TotalMass = 0.f;
	// Find all the overlapping actors
	TArray<AActor*> OverlappingActors;
	if (!LightTrigger) { return TotalMass; }
	LightTrigger->GetOverlappingActors(OUT OverlappingActors);
	// Iterate through them adding their masses
	for (const auto* Actor : OverlappingActors)
	{
		TotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
	}

	return TotalMass;
}


