// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TestGameGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class TESTGAME_API ATestGameGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
    ATestGameGameModeBase();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerPawn")
		class AsphereBase * PlayerPawn;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CurrentPosition")
		FVector CurrentPosition;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DeathCount")
		int32 PlayerDieCount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool IsEnd;

public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	
public:
	void SetSphereLocation();
	void SetSphereLocation(FVector Start);
	void SetCurrentPosition(FVector Location);
	void SetPlayerInput(bool isInput);
	
};
