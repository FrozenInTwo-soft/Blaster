// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class BLASTER_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:
	AProjectile();
	virtual void Tick(float DeltaTime) override;
	virtual void Destroyed() override;

	/*
	 * Used with server-side rewind
	 */

	bool bUseServerSideRewind = false;
	FVector_NetQuantize TraceStart;
	FVector_NetQuantize100 InitialVelocity;

	UPROPERTY(EditAnywhere)
	float InitialSpeed = 15000;

	// Only set this for Grenades and rockets.
	UPROPERTY(EditAnywhere)
	float Damage = 10.f;
	
	UPROPERTY(EditAnywhere)
	float HeadShotDamage = 20.f;
	
protected:
	virtual void BeginPlay() override;
	void StartDestroyTimer();
	void DestoyTimerFinished();
	void SpawnTrailSystem();
	void ExplodeDamage();

	UFUNCTION()
	virtual void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		FVector NormalImpulse, const FHitResult& Hit);

	UPROPERTY(EditAnywhere)
	class UParticleSystem* ImpactParticles;

	UPROPERTY(EditAnywhere)
	class USoundBase* ImpactSound;

	UPROPERTY(EditAnywhere)
	class UBoxComponent* CollisionBox;
	
	UPROPERTY(EditAnywhere)
	class UNiagaraSystem* TrailSystem;

	UPROPERTY()
	class UNiagaraComponent* TrailSystemComponent;

	UPROPERTY(VisibleAnywhere)
	class UProjectileMovementComponent* ProjectileMovementComponent;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* ProjectileMesh;
	
	UPROPERTY(EditAnywhere, Category = "Damage")
	float InnerRadius{200.f};
	
	UPROPERTY(EditAnywhere, Category = "Damage")
	float OuterRadius{500.f};

private:
	UPROPERTY(EditAnywhere)
	UParticleSystem* Tracer;

	class UParticleSystemComponent* TracerComponent;

	FTimerHandle DestroyTimer;

	UPROPERTY(EditAnywhere)
	float DestroyTime = 3;
};
