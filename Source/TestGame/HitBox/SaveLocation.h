// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HitBox/HitBoxBase.h"
#include "SaveLocation.generated.h"

/**
 * 
 */
UCLASS()
class TESTGAME_API ASaveLocation : public AHitBoxBase
{
	GENERATED_BODY()
		ASaveLocation();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UStaticMeshComponent * SaveMeshComp;
	
public:
	virtual void OnHitSphere(AsphereBase * sphere) override;
	
	
};
