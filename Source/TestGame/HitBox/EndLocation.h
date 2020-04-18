// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HitBox/HitBoxBase.h"
#include "EndLocation.generated.h"

/**
 * 
 */
UCLASS()
class TESTGAME_API AEndLocation : public AHitBoxBase
{
	GENERATED_BODY()
		AEndLocation();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UStaticMeshComponent * EndMeshComp;
	
public:
	virtual void OnHitSphere(class AsphereBase * sphere) override;
	
};
