// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <InventorySlot.h>
#include <Components/TextBlock.h>
#include "Blueprint/UserWidget.h"
#include "InventoryWidget.generated.h"


/**
 * 
 */
UCLASS(BlueprintType)
class NEWLITTLEHORRORGAME_API UInventoryWidget : public UUserWidget
{
	GENERATED_BODY()
	

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray <UInventorySlot*> inventorySlot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray <UInventorySlot*> HotInventorySlot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UImage* img;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTextBlock* Title;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UDataTable* DataTableIDtoInfo;

	UFUNCTION(BlueprintCallable)
	void UpdateItemSlotByIndex(int Index);

	UFUNCTION(BlueprintCallable)
	void UpdateHotItemSlotByIndex(int Index);

	UFUNCTION(BlueprintCallable)
	void setDefoult();
};
