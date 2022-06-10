// Fill out your copyright notice in the Description page of Project Settings.


#include "FlagZone.h"
#include "Components/SphereComponent.h"
#include "Blaster/Weapon/Flag.h"
#include "Blaster/GameMode/CTFGameMode.h"

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
	// ABlasterCharacter* OverlappingCharacter = Cast<ABlasterCharacter>(OtherActor);
	// if (OverlappingCharacter && OverlappingCharacter->IsHoldingFlag() && OverlappingCharacter->GetTeam() == Team)
	if (OverlappingFlag && OverlappingFlag->GetTeam() != Team)
	{
		ACTFGameMode* GameMode = GetWorld()->GetAuthGameMode<ACTFGameMode>();
		if (GameMode)
		{
			GameMode->FlagCaptured(OverlappingFlag, this);
		}
		OverlappingFlag->ResetFlag();
	}
}
