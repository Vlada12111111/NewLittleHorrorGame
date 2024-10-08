// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <Components/Image.h>
#include "Components/CanvasPanel.h"
#include "InventorySlot.generated.h"


UCLASS()
class NEWLITTLEHORRORGAME_API UInventorySlot : public UCanvasPanel
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UImage* TitleImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ItemID;
};
