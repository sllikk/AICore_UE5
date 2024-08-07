// Fill out your copyright notice in the Description page of Project Settings.


#include "Entity/unit_base.h"

// Sets default values
Aunit_base::Aunit_base()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void Aunit_base::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void Aunit_base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


