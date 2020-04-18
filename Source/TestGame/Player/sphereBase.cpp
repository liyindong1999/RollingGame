// Fill out your copyright notice in the Description page of Project Settings.

#include "sphereBase.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "Engine.h"



// Sets default values
AsphereBase::AsphereBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	IsInput = true;
	SphereSpeed = 300.0f;
	SpeedMin = SphereSpeed;
	SpeedMax = 600.f;

	SphereMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SphereBase"));
	SphereMeshComp->SetSimulatePhysics(true);
	CameraArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraArm"));
	CameraArmComp->SetupAttachment(SphereMeshComp);
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComp->SetupAttachment(CameraArmComp);

}

// Called when the game starts or when spawned
void AsphereBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AsphereBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (IsInput && AngularVector != FVector(0, 0, 0)) {
		SphereMeshComp->SetPhysicsAngularVelocity(AngularVector);
	}
}

// Called to bind functionality to input
void AsphereBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward",this,&AsphereBase::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight",this, &AsphereBase::MoveRight);
	PlayerInputComponent->BindAction("SpeedUp", IE_Pressed, this, &AsphereBase::SpeedUp);
	PlayerInputComponent->BindAction("SpeedLow", IE_Released, this, &AsphereBase::SpeedLow);
}

void AsphereBase::MoveForward(float val)
{
	
	if (IsInput) {
		AngularVector.Y = SphereSpeed * val;
	}
}

void AsphereBase::MoveRight(float val)
{
	if (IsInput) {
		AngularVector.X = SphereSpeed * val;
	}
}
void AsphereBase::SpeedUp()
{
	SphereSpeed = SpeedMax;
}
void AsphereBase::SpeedLow()
{
	SphereSpeed = SpeedMin;
}
