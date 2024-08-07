// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "unit_base.generated.h"

UCLASS()
class AI_CORE_API Aunit_base : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	Aunit_base();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
public:	

	
};
