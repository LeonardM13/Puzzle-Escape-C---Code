// Fill out your copyright notice in the Description page of Project Settings.

#include "RotatinTrigger.h"


// Sets default values for this component's properties
URotatinTrigger::URotatinTrigger()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void URotatinTrigger::BeginPlay()
{
	Super::BeginPlay();

	OverlappingActor = GetWorld()->GetFirstPlayerController()->GetPawn();
}


// Called every frame
void URotatinTrigger::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	
	if (LampTrigger->IsOverlappingActor(OverlappingActor))
	{
		GetOwner()->SetActorRotation(LampRotation);
	}

}

