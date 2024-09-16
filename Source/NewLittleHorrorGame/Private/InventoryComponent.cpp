// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"

UInventoryComponent::UInventoryComponent()
{

	PrimaryComponentTick.bCanEverTick = true;

}

void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	for (int a = 0; a < ItemSlotNumber; a++) {
		inventory.Add(NewObject<UItem>());
	}
	for (int a = 0; a < HotItemSlotNumber; a++) {
		HotItem.Add(-1);
	}

}

int UInventoryComponent::addItemInFreePlace(UItem* NewItem) {

	if (NewItem) {

		for (int a = 0; a < inventory.Num(); a++) {
			if (inventory[a]) {
				if (inventory[a]->ID == -1) {

					inventory[a] = NewItem;
					addHotItemInFreePlace(NewItem, a);
					return a;

				};
			}
		}
	}
	return -1;
}

int UInventoryComponent::addHotItemInFreePlace(UItem* NewItem, int RealObject) {

	if (NewItem) {

		for (int a = 0; a < HotItem.Num(); a++) {
			if (HotItem[a]) {
				if (HotItem[a] == -1) {

					HotItem[a] = RealObject;
					return a;

				};
			}
		}
	}
	return -1;
}

void UInventoryComponent::addItemInIndexPlace(UItem* NewItem, int index) {

	if (NewItem) {
		inventory[index] = NewItem;
	}
}


void UInventoryComponent::removeItemByID(int ID) {
	for (int a = 0; a < inventory.Num(); a++) {
		if (inventory[a] && inventory[a]->ID == ID) {
			inventory[a] = NewObject<UItem>();
			return;
		}
	}
}

void UInventoryComponent::removeItemBySlotIndex(int Index) {

	inventory[Index] = NewObject<UItem>();
	return;

}


void UInventoryComponent::print() {

	for (int a = 0; a != inventory.Num(); a++) {
		if (GEngine) {

			if (inventory[a]) { GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Item: %s"), *inventory[a]->name)); }
			else {
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Item:---")));
			}
		}

	}
}


TArray<int32> UInventoryComponent::getIDItemList() {

	TArray<int32> IDs;

	for (int a = 0; a < inventory.Num(); a++) {
		if (inventory[a]) {
			if (inventory[a]->ID) { IDs.Add(inventory[a]->ID); }
			else { IDs.Add(-1); }
		}
	}

	return IDs;
}