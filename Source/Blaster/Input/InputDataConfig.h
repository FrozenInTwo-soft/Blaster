// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "InputDataConfig.generated.h"

class UInputAction;

UCLASS()
class BLASTER_API UInputDataConfig : public UDataAsset
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(EditAnywhere, Category="Input|Action")
	UInputAction* JumpAction;
	
	UPROPERTY(EditAnywhere, Category="Input|Action")
	UInputAction* CrouchAction;
	
	UPROPERTY(EditAnywhere, Category="Input|Action")
	UInputAction* EquipAction;
	
	UPROPERTY(EditAnywhere, Category="Input|Action")
	UInputAction* DropAction;
	
	UPROPERTY(EditAnywhere, Category="Input|Action")
	UInputAction* AimAction;
	
	UPROPERTY(EditAnywhere, Category="Input|Action")
	UInputAction* ReloadAction;
	
	UPROPERTY(EditAnywhere, Category="Input|Action")
	UInputAction* FireAction;
	
	UPROPERTY(EditAnywhere, Category="Input|Action")
	UInputAction* ThrowGrenadeAction;
	
	UPROPERTY(EditAnywhere, Category="Input|Action")
	UInputAction* SwapAction;
	
	UPROPERTY(EditAnywhere, Category="Input|Action")
	UInputAction* MoveAction;
	
	UPROPERTY(EditAnywhere, Category="Input|Action")
	UInputAction* LookAction;
	
	UPROPERTY(EditAnywhere, Category="Input|Action")
	UInputAction* MouseLookAction;
	
	
};
