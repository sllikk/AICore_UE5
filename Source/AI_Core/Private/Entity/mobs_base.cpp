// Fill out your copyright notice in the Description page of Project Settings.

#include "Entity/mobs_base.h"

#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Perception/AIPerceptionStimuliSourceComponent.h"
#include "Perception/AISense_Damage.h"
#include "Perception/AISense_Sight.h"


// Sets default values
Amobs_base::Amobs_base(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer), m_flmaxhealth(0),  m_blsdead(false)
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	pStimuliSourceComponent = nullptr;
	pBehaviorTree = nullptr;
	m_flcurrenthealth = m_flmaxhealth;
	
	pStimuliSourceComponent = ObjectInitializer.CreateDefaultSubobject<UAIPerceptionStimuliSourceComponent>(this, TEXT("MobsPerceptionComponent"));	

	GetCapsuleComponent()->InitCapsuleSize(45.f, 96.0f);
	GetCharacterMovement()->MaxWalkSpeed = MobMovement.flmaxspeedwalk; 
	GetCharacterMovement()->Mass = MobMovement.flmass;
	GetCharacterMovement()->MaxAcceleration = MobMovement.flacceleration;
	GetCharacterMovement()->bRequestedMoveUseAcceleration = true;
	
	AIControllerClass = pAI_Controller;

	SetActorScale3D(FVector(0.7, 0.7, 0.7));
}

void Amobs_base::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	if (pStimuliSourceComponent->IsValidLowLevel())
	{
		pStimuliSourceComponent->RegisterForSense(UAISense_Damage::StaticClass());  
		pStimuliSourceComponent->RegisterForSense(UAISense_Sight::StaticClass());
	}
}

// Called when the game starts or when spawned
void Amobs_base::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void Amobs_base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void Amobs_base:: HandleTakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType,
	AController* InstigatedBy, AActor* DamageCauser)
{
	if (ISDead() || GetCurrentHealth() <= 0)
	{
		return;
	}

	m_flcurrenthealth = FMath::Clamp(m_flcurrenthealth - Damage, 0.0f, m_flmaxhealth);

	if (GetCurrentHealth() <= 0)
	{
		m_blsdead = true;
	}
}




