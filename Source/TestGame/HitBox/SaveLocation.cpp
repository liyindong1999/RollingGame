// Fill out your copyright notice in the Description page of Project Settings.

#include "SaveLocation.h"
#include "GameMode/TestGameGameModeBase.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"


ASaveLocation::ASaveLocation()
{
	SaveMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SaveMesh"));
}

void ASaveLocation::OnHitSphere(AsphereBase * sphere)
{
	ATestGameGameModeBase * GameModeBase = Cast<ATestGameGameModeBase>(GetWorld()->GetAuthGameMode());
	GameModeBase->SetCurrentPosition(HitBoxComp->GetComponentLocation());
}
