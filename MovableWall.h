// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "MovableWall.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FWallTrigger);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UMovableWall : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMovableWall();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	float WallTriggerMass();

private:
	UPROPERTY(EditAnywhere)
		ATriggerVolume* WallTrigger= nullptr;
	UPROPERTY(BlueprintAssignable)
		FWallTrigger OnOpen;
	UPROPERTY(BlueprintAssignable)
		FWallTrigger OnClose;

	float TotalMass = 32.f;
};
