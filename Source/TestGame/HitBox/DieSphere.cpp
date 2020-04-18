// Fill out your copyright notice in the Description page of Project Settings.

#include "DieSphere.h"
#include "Player/sphereBase.h"
#include "Engine.h"
#include "GameMode/TestGameGameModeBase.h"

void ADieSphere::OnHitSphere(AsphereBase * sphere)
{
	ATestGameGameModeBase * GameModeBase =  Cast<ATestGameGameModeBase>(GetWorld()->GetAuthGameMode());
	GameModeBase->SetSphereLocation();
}
