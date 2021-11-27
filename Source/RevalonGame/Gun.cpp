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
	OwnerPawn = Cast<APawn>(GetOwner());
	if (!OwnerPawn)
	{
		return;
	}

	AController* OwnerController = OwnerPawn->GetController();
	if (!OwnerController)
	{
		return;
	}
	FVector ViewPointLoc;
	FRotator ViewPointRot;
	OwnerController->GetPlayerViewPoint(ViewPointLoc, ViewPointRot);
	FVector End = ViewPointLoc + ViewPointRot.Vector()*MaxRange;
	FHitResult RaycastHit;
	if (GetWorld()->LineTraceSingleByChannel(OUT RaycastHit, ViewPointLoc, End, ECC_GameTraceChannel1))
	{
		FVector ShotDirection = -ViewPointRot.Vector();
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ShotImpactEffect, RaycastHit.Location, ShotDirection.Rotation());
		AActor* ShotActor = Cast<AShooterCharacter>(RaycastHit.GetActor());
		if (ShotActor)
		{
			FPointDamageEvent GunDamageEvent(GunDamage, RaycastHit, ShotDirection, nullptr);
			ShotActor->TakeDamage(GunDamage, GunDamageEvent, OwnerController, this);
		}
	}

}

