// Fill out your copyright notice in the Description page of Project Settings.

#include "TestGameGameModeBase.h"
#include "Engine.h"
#include "Player/sphereBase.h"


ATestGameGameModeBase::ATestGameGameModeBase()
{
	PrimaryActorTick.bCanEverTick = true;
	PlayerDieCount = 0;
	IsEnd = false;
}

void ATestGameGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	AsphereBase * Pawn = Cast<AsphereBase>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (Pawn)
	{
		PlayerPawn = Pawn;
		CurrentPosition = PlayerPawn->GetActorLocation();
	}
}

void ATestGameGameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATestGameGameModeBase::SetSphereLocation(FVector Start)
{
	PlayerPawn->SetActorLocation(Start);
	PlayerPawn->SphereMeshComp->SetPhysicsLinearVelocity(FVector(0,0,0));
	PlayerPawn->SphereMeshComp->SetPhysicsAngularVelocity(FVector(0, 0, 0));
}

void ATestGameGameModeBase::SetSphereLocation()
{
	PlayerPawn->SetActorLocation(CurrentPosition);
	PlayerPawn->SphereMeshComp->SetPhysicsLinearVelocity(FVector(0, 0, 0));
	PlayerPawn->SphereMeshComp->SetPhysicsAngularVelocity(FVector(0, 0, 0));
}

void ATestGameGameModeBase::SetCurrentPosition(FVector Location)
{
	if (Location != FVector(0,0,0))
	{
		CurrentPosition = Location;
	}
}

void ATestGameGameModeBase::SetPlayerInput(bool isInput)
{
	PlayerPawn->IsInput = isInput;
	if (!isInput)
	{
		IsEnd = true;
	}
}
