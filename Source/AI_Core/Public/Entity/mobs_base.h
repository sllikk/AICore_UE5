// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "GameFramework/Character.h"
#include "Perception/AISense.h"
#include "mobs_base.generated.h"

USTRUCT(BlueprintType)
struct FBaseMobMovement 
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category= "Movement")
	float flmaxspeedwalk;

	UPROPERTY(BlueprintReadWrite, Category= "Movement")
	float flacceleration;

	UPROPERTY(BlueprintReadWrite, Category= "Movement")
	float flmass;	

	FBaseMobMovement()
	{
		flmaxspeedwalk = 0;
		flacceleration = 0;
		flmass = 0;
	}
};
	

//------------ Forward Declaration for optimization compiler --------------//
class UWidgetComponent;
class UBehaviorTree;
class UAIPerceptionStimuliSourceComponent;

UCLASS(Blueprintable)
class AI_CORE_API Amobs_base : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite ,Category="UI", meta=(AllowPrivateAccess = "true"))
	TObjectPtr<UWidgetComponent> softBaseWidget;

	UPROPERTY(Transient, VisibleAnywhere, Category="AI")
	TObjectPtr<UBehaviorTree> pBehaviorTree;

	UPROPERTY(EditAnywhere, Category="AI")
	TSubclassOf<AAIController> pAI_Controller;
	
public:
	// Sets default values for this character's properties
	explicit Amobs_base(const FObjectInitializer& ObjectInitializer);
	
protected:

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void PostInitializeComponents() override;
	virtual void HandleTakeDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);

public:
	// Getters Setters
	bool ISDead() const;
	float GetCurrentHealth() const;
	float GetMaxHealth() const;

	TObjectPtr<UBehaviorTree> GetBehaviorTree() const;
	
	void SetBehaviorTree(TObjectPtr<UBehaviorTree> ptrbehavior_tree);
	void SetMaxHealth(float flhealth);
	void SetDead(bool bldead);
	
	UPROPERTY(EditAnywhere, Category="Movement")
	FBaseMobMovement MobMovement;
	
private:

	UPROPERTY()
	TObjectPtr<UAIPerceptionStimuliSourceComponent> pStimuliSourceComponent;

	float m_flmaxhealth;
	float m_flcurrenthealth;
	bool m_blsdead;
	
};
/* ---------------------------inline Setter and Getter------------------------------------------------------------- */
	
FORCEINLINE void Amobs_base::SetBehaviorTree(TObjectPtr<UBehaviorTree> ptrbehavior_tree)
{
	pBehaviorTree = ptrbehavior_tree; 		
}

FORCEINLINE TObjectPtr<UBehaviorTree> Amobs_base::GetBehaviorTree() const
{
	return pBehaviorTree;
}

FORCEINLINE float Amobs_base::GetCurrentHealth() const
{
	return m_flcurrenthealth;
}

FORCEINLINE float Amobs_base::GetMaxHealth() const
{
	return m_flmaxhealth;
}

FORCEINLINE void Amobs_base::SetMaxHealth(float flhealth)
{
	m_flmaxhealth = flhealth;
}


FORCEINLINE bool Amobs_base::ISDead() const
{
	return m_blsdead;
}

FORCEINLINE void Amobs_base::SetDead(bool bldead)
{
	m_blsdead = bldead;		
}















