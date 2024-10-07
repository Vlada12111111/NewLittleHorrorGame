// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <Item.h>
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
	TArray <UItem*> inventory = {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int HotItemSlotNumber = 5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ItemSlotNumber = 15;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray <int> HotItem = {};

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	UFUNCTION(BlueprintCallable)
	int addItemInFreePlace(UItem* NewItem);

	UFUNCTION(BlueprintCallable)
	int addHotItemInFreePlace(UItem* NewItem, int RealObject);

	UFUNCTION(BlueprintCallable)
	void addItemInIndexPlace(UItem* NewItem, int index);

	UFUNCTION(BlueprintCallable)
	void removeItemByID(int ID);

	UFUNCTION(BlueprintCallable)
	void removeItemBySlotIndex(int SlotIndex);

	UFUNCTION(BlueprintCallable)
	void InventoryPrint();

	UFUNCTION(BlueprintCallable)
	TArray<int32> getIDItemList();
		
};
