// Fill out your copyright notice in the Description page of Project Settings.

#include "EndLocation.h"
#include "GameMode/TestGameGameModeBase.h"
#include "Components/StaticMeshComponent.h"
#include "Engine.h"



AEndLocation::AEndLocation()
{
	EndMeshComp->CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EndMeshComp"));
	HitBoxComp->SetupAttachment(EndMeshComp);
}

void AEndLocation::OnHitSphere(class AsphereBase * sphere)
{
	ATestGameGameModeBase * GameModeBase = Cast<ATestGameGameModeBase>(GetWorld()->GetAuthGameMode());
	GameModeBase->SetPlayerInput(false);
}
