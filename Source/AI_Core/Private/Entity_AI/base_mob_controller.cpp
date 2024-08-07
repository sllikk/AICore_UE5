// Fill out your copyright notice in the Description page of Project Settings.


#include "Entity_AI/base_mob_controller.h"

#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISense_Sight.h"
#include <iostream>

#include "Perception/AISense_Damage.h"
#include "Perception/AISense_Hearing.h"
#include "Perception/AISense_Prediction.h"
#include "Perception/AISense_Team.h"
#include "Perception/AISense_Touch.h"

Abase_mob_controller::Abase_mob_controller(const FObjectInitializer& ObjectInitializer)
{
	AAIController::SetGenericTeamId(FGenericTeamId(10));

}

void Abase_mob_controller::BeginPlay()
{
	Super::BeginPlay();
}

void Abase_mob_controller::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

ETeamAttitude::Type Abase_mob_controller::GetTeamAttitudeTowards(const AActor& Other) const
{


	return Super::GetTeamAttitudeTowards(Other);

}

bool Abase_mob_controller::CanSeeActors(const TObjectPtr<AActor>& Actor, ESenseType& Sense, FAIStimulus& Stimulus) 
{
	FActorPerceptionBlueprintInfo PerceptionBlueprintInfo;
	if (PerceptionComponent->GetActorsPerception(Actor, PerceptionBlueprintInfo))
	{
		for (const FAIStimulus& CurrentStimulus : PerceptionBlueprintInfo.LastSensedStimuli)
		{
			TSubclassOf<UAISense> SensedClass = UAIPerceptionSystem::GetSenseClassForStimulus(GetWorld(), CurrentStimulus);
			bool bSenseMatched = false;

			if (SensedClass != nullptr)
			{
				switch (Sense)
				{
				case ESenseType::NONE:	
					std::cout << "NONE_SENSE" << std::endl;
					break;
				case ESenseType::SIGHT:
				    if (SensedClass == UAISense_Sight::StaticClass())
					{
						bSenseMatched = true;
					}
				break;	
				case ESenseType::HEARING:
					if (SensedClass == UAISense_Hearing::StaticClass())
					{
						bSenseMatched = true;
					}
					break;	
				case ESenseType::DAMAGE:
					if (SensedClass == UAISense_Damage::StaticClass())
					{
						bSenseMatched = true;
					}
					break;	
				case ESenseType::TOUCH:
					if (SensedClass == UAISense_Touch::StaticClass())
					{
						bSenseMatched = true;
					}
					break;	
				case ESenseType::TEAM:
					if (SensedClass == UAISense_Team::StaticClass())
					{
						bSenseMatched = true;
					}
					break;	
				case ESenseType::PREDICTION:
					if (SensedClass == UAISense_Prediction::StaticClass())
					{
						bSenseMatched = true;
					}
					break;	
				default: std::cout << "Unhandled AI Sense" << std::endl;
					break;
				}
			}
		}
		
	}

	return false;
}

void Abase_mob_controller::HandleSenseSight(TObjectPtr<AActor> Actor)
{

}

void Abase_mob_controller::HandleSenseSightLost()
{

}

void Abase_mob_controller::HandleSenseHearing(const FVector& vecLocationSound)
{

}

void Abase_mob_controller::HandleSensedDamage(const AActor* Actor)
{

}
