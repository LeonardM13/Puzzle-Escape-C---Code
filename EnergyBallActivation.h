// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "EnergyBallActivation.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FParticleTrigger);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UEnergyBallActivation : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UEnergyBallActivation();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	float SwitchMass0();
	float SwitchMass1();
	float SwitchMass2();
	float SwitchMass3();

private:
	UPROPERTY(EditAnywhere)
		ATriggerVolume* ActivationSwitch0 = nullptr;
	UPROPERTY(EditAnywhere)
		ATriggerVolume* ActivationSwitch1 = nullptr;
	UPROPERTY(EditAnywhere)
		ATriggerVolume* ActivationSwitch2 = nullptr;
	UPROPERTY(EditAnywhere)
		ATriggerVolume* ActivationSwitch3 = nullptr;
	UPROPERTY(BlueprintAssignable)
		FParticleTrigger OnActivation;
	UPROPERTY(BlueprintAssignable)
		FParticleTrigger OnDeactivation;
	
	float ActivationMass0 = 3.f;
	float ActivationMass1 = 3.f;
	float ActivationMass2 = 3.f;
	float ActivationMass3 = 3.f;
};
