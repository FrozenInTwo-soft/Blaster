// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon.h"
#include "HitScanWeapon.generated.h"

/**
 * 
 */
UCLASS()
class BLASTER_API AHitScanWeapon : public AWeapon
{
	GENERATED_BODY()

public:
	virtual void Fire(const FVector& HitTarget) override;

protected:
	void WeaponTraceHit(const FVector& TraceStart, const FVector& HitTarget, FHitResult& OutHit);

	UPROPERTY(EditAnywhere, Category = "Weapon|FX")
	class UParticleSystem* ImpactParticles;
	
	UPROPERTY(EditAnywhere, Category = "Weapon|FX")
	USoundBase* HitSound;
	
private:
	UPROPERTY(EditAnywhere, Category = "Weapon|FX")
	UParticleSystem* BeamParticles;

	UPROPERTY(EditAnywhere, Category = "Weapon|FX")
	UParticleSystem* MuzzleFlash;

	UPROPERTY(EditAnywhere, Category = "Weapon|FX")
	USoundBase* FireSound;

	
	
	
};
