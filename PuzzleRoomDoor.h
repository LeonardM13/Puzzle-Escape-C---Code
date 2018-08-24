// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "PuzzleRoomDoor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorTrigger);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UPuzzleRoomDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPuzzleRoomDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	float TriggerPlatformMass0();
	float TriggerPlatformMass1();
	float TriggerPlatformMass2();
	float TriggerPlatformMass3();
	float TriggerPlatformMass4();

private:
	UPROPERTY(EditAnywhere)
		ATriggerVolume* TriggerPlatform0 = nullptr;
	UPROPERTY(EditAnywhere)
		ATriggerVolume* TriggerPlatform1 = nullptr;
	UPROPERTY(EditAnywhere)
		ATriggerVolume* TriggerPlatform2 = nullptr;
	UPROPERTY(EditAnywhere)
		ATriggerVolume* TriggerPlatform3 = nullptr;
	UPROPERTY(EditAnywhere)
		ATriggerVolume* TriggerPlatform4 = nullptr;
	UPROPERTY(BlueprintAssignable)
		FDoorTrigger OnOpen;
	UPROPERTY(BlueprintAssignable)
		FDoorTrigger OnClose;

	float TriggerMass0 = 21.f;
	float TriggerMass1 = 22.f;
	float TriggerMass2 = 23.f;
	float TriggerMass3 = 24.f;
	float TriggerMass4 = 25.f;
};
