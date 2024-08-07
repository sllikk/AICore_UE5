// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AI_Core/ESense.h"
#include "Perception/AIPerceptionTypes.h"
#include "base_mob_controller.generated.h"

class Amobs_base;
class UAISenseConfig_Sight;
class UAISenseConfig_Hearing;
class UAISenseConfig_Touch;
class UAISenseConfig_Damage;
class UAISenseConfig_Team;


UCLASS(Blueprintable)
class AI_CORE_API Abase_mob_controller : public AAIController
{
	GENERATED_BODY()

public:

	explicit Abase_mob_controller(const FObjectInitializer& ObjectInitializer);
	
protected:
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	virtual ETeamAttitude::Type GetTeamAttitudeTowards(const AActor&Other) const override;

public:

	FORCEINLINE bool CanSeeActors(const TObjectPtr<AActor>& Actor,  ESenseType& Sense, FAIStimulus& Stimulus); 
	
	void  HandleSenseSight(TObjectPtr<AActor> Actor);
	void  HandleSenseSightLost();
	void  HandleSenseHearing(const FVector& vecLocationSound);
	void  HandleSensedDamage(const AActor* Actor);
	
private:
	
	
};
