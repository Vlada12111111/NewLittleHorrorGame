// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"



UCLASS(BlueprintType)
class NEWLITTLEHORRORGAME_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()


public:	
	// Sets default values for this component's properties
	UInventoryComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray <int> Inventory = {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int HotItemSlotNumber = 5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ItemSlotNumber = 15;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray <int> HotInventory = {};

public:	
	UFUNCTION(BlueprintCallable)
	int addItemInFreePlace(int NewItemID);

	UFUNCTION(BlueprintCallable)
	int setItemInHotInventory(int refresh);

	UFUNCTION(BlueprintCallable)
	void addItemInIndexPlace(int NewItem, int index);

	UFUNCTION(BlueprintCallable)
	void removeItem(int ID);

	UFUNCTION(BlueprintCallable)
	void removeItemBySlotIndex(int SlotIndex);

	UFUNCTION(BlueprintCallable)
	void InventoryPrint();

	UFUNCTION(BlueprintCallable)
	void RefreshHotInventory();
};
