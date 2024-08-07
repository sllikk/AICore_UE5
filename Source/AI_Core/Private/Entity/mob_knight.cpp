// Fill out your copyright notice in the Description page of Project Settings.


#include "Entity/mob_knight.h"

Amob_knight::Amob_knight(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	FSoftObjectPath ObjectPath(TEXT("/Game/Characters/NPC/Mob/Knight/Mesh/mob_knight_fbx"));
	static USkeletalMesh* pMesh = nullptr;
	if (ObjectPath.IsValid())
	{
		pMesh = Cast<USkeletalMesh>(ObjectPath.TryLoad());
	}
	if (pMesh != nullptr)
	{
		GetMesh()->SetSkeletalMesh(pMesh);
		GetMesh()->SetWorldRotation(FRotator(0,-60, 0));
	}

	FTransform WorldTransform;
	WorldTransform.SetLocation(FVector(0, 0, -25));
	WorldTransform.SetScale3D(FVector(0.7, 0.7, 0.7));
	SetActorTransform(WorldTransform);

	SetMaxHealth(120.0f);
	
}


void Amob_knight::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void Amob_knight::BeginPlay()
{
	Super::BeginPlay();
	
}

void Amob_knight::HandleTakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType,
	AController* InstigatedBy, AActor* DamageCauser)
{
	Super::HandleTakeDamage(DamagedActor, Damage, DamageType, InstigatedBy, DamageCauser);

}

void Amob_knight::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	
	
}

