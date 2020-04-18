// Fill out your copyright notice in the Description page of Project Settings.

#include "HitBoxBase.h"
#include "Components/BoxComponent.h"
#include "Player/sphereBase.h"
#include "Components/SceneComponent.h"

// Sets default values
AHitBoxBase::AHitBoxBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseScene = CreateDefaultSubobject<USceneComponent>(TEXT("SceneBase"));

    HitBoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("HitBox"));
	HitBoxComp->OnComponentBeginOverlap.AddDynamic(this, &AHitBoxBase::BeginHit);
	//HitBoxComp->SetupAttachment(BaseScene);

}

// Called when the game starts or when spawned
void AHitBoxBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHitBoxBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHitBoxBase::BeginHit(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (Cast<AsphereBase>(OtherActor))
	{
		AsphereBase * sphere = Cast<AsphereBase>(OtherActor);
		OnHitSphere(sphere);
	}
}

void AHitBoxBase::OnHitSphere(class AsphereBase * sphere)
{

}

