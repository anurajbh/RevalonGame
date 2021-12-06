// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystem.h"
#include "DrawDebugHelpers.h"
#include "ShooterCharacter.h"
#define OUT
// Sets default values
AGun::AGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootSceneComponent = CreateDefaultSubobject < USceneComponent >(TEXT("RootSceneComponent"));
	SetRootComponent(RootSceneComponent);
	SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
	SkeletalMeshComponent->SetupAttachment(RootSceneComponent);
}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AGun::PullTrigger()
{
	UGameplayStatics::SpawnEmitterAttached(MuzzleFlashEffect, SkeletalMeshComponent, TEXT("MuzzleFlashSocket"));
	FHitResult RaycastHit;
	FVector ShotDirection;
	if (GunTrace(OUT RaycastHit, OUT ShotDirection))
	{
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ShotImpactEffect, RaycastHit.Location, ShotDirection.Rotation());
		AActor* ShotActor = Cast<AShooterCharacter>(RaycastHit.GetActor());
		if (ShotActor)
		{
			FPointDamageEvent GunDamageEvent(GunDamage, RaycastHit, ShotDirection, nullptr);
			ShotActor->TakeDamage(GunDamage, GunDamageEvent, GetOwnerController(), this);
		}
	}

}

bool AGun::GunTrace(FHitResult& RaycastHit, FVector& ShotDirection)
{
	FVector ViewPointLoc;
	FRotator ViewPointRot;
	AController* OwnerController = GetOwnerController();
	if (!OwnerController)
	{
		return false;
	}
	OwnerController->GetPlayerViewPoint(ViewPointLoc, ViewPointRot);
	ShotDirection = -ViewPointRot.Vector();
	FVector End = ViewPointLoc + ViewPointRot.Vector() * MaxRange;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);
	Params.AddIgnoredActor(GetOwner());
	return GetWorld()->LineTraceSingleByChannel(OUT RaycastHit, ViewPointLoc, End, ECC_GameTraceChannel1, Params);
}

AController* AGun::GetOwnerController() const
{
	APawn* OwnerPawn = Cast<APawn>(GetOwner());
	if (!OwnerPawn)
	{
		return nullptr;
	}
	return OwnerPawn->GetController();
}

