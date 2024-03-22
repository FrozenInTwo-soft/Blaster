// Fill out your copyright notice in the Description page of Project Settings.


#include "FlagZone.h"
#include "Flag.h"
#include "Blaster/Character/BlasterCharacter.h"
#include "Blaster/GameMode/CTFGameMode.h"
#include "Components/SphereComponent.h"

AFlagZone::AFlagZone()
{
 	PrimaryActorTick.bCanEverTick = false;

	ZoneSphere = CreateDefaultSubobject<USphereComponent>(TEXT("ZoneSphere"));
	ZoneSphere->SetSphereRadius(80.f);
	SetRootComponent(ZoneSphere);
}

void AFlagZone::BeginPlay()
{
	Super::BeginPlay();

	ZoneSphere->OnComponentBeginOverlap.AddDynamic(this, &AFlagZone::OnSphereOverlap);
}

void AFlagZone::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AFlag* OverlappingFlag = Cast<AFlag>(OtherActor);
	if (OverlappingFlag && OverlappingFlag->GetTeam() != Team && OverlappingFlag->GetOwner() != nullptr)
	{
		ACTFGameMode* GameMode = GetWorld()->GetAuthGameMode<ACTFGameMode>();
		if (GameMode)
		{
			GameMode->FlagCaptured(OverlappingFlag, this);
		}
		OverlappingFlag->ResetFlag();
	}
}
