// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

UCLASS()
class REVALONGAME_API AGun : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGun();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere)
		float GunDamage = 10.f;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void PullTrigger();
private:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* RootSceneComponent;
	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* SkeletalMeshComponent;
	UPROPERTY(EditAnywhere)
		class UParticleSystem* MuzzleFlashEffect;
	UPROPERTY(EditAnywhere)
		class UParticleSystem* ShotImpactEffect;
	UPROPERTY(EditAnywhere)
		float MaxRange = 1000.f;
	UPROPERTY(EditAnywhere)
		class USoundBase* MuzzleSound = nullptr;
	UPROPERTY(EditAnywhere)
		class USoundBase* ImpactSound = nullptr;
	bool GunTrace(FHitResult& RaycastHit, FVector& ShotDirection);
	AController* GetOwnerController() const;
};
