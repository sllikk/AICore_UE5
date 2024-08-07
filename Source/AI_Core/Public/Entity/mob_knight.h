// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Entity/mobs_base.h"
#include "mob_knight.generated.h"

class USkeletalMesh;

UCLASS()
class AI_CORE_API Amob_knight : public Amobs_base
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category="BaseMesh", meta=(AllowPrivateAccess = "true"))
	TSoftObjectPtr<USkeletalMesh> knight_skeletal;
	

public:

	explicit Amob_knight(const FObjectInitializer& ObjectInitializer);

protected:

	virtual void Tick(float DeltaSeconds) override;
	virtual void BeginPlay() override;
	virtual void HandleTakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser) override;
	virtual void PostInitializeComponents() override;		

private:

	
};


