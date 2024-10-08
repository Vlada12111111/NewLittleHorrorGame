// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"

UInventoryComponent::UInventoryComponent()
{

	PrimaryComponentTick.bCanEverTick = true;

	for (int a = 0; a < ItemSlotNumber; a++) {
		Inventory.Add(-1);
	}
	for (int a = 0; a < HotItemSlotNumber; a++) {
		HotInventory.Add(-1);
	}

}


int UInventoryComponent::addItemInFreePlace(int NewItemID) {

		for (int a = 0; a < Inventory.Num(); a++) {//set item in first empty position
				if (Inventory[a]== -1) {

					Inventory[a] = NewItemID;
					setItemInHotInventory(a);
					return a;

				};
		}
	return -1;//if inventary is full
}

int UInventoryComponent::setItemInHotInventory(int refresh) {
		for (int a = 0; a < HotInventory.Num(); a++) {//set item in first empty position
				if (HotInventory[a] == -1) {

					HotInventory[a] = refresh;
					return a;

				};
		}
	return -1;//if inventary is full
}

void UInventoryComponent::addItemInIndexPlace(int NewItemID, int index) {
		Inventory[index] = NewItemID;
		RefreshHotInventory();
}


void UInventoryComponent::removeItem(int ID) {
	for (int a = 0; a < Inventory.Num(); a++) {
		if (Inventory[a] == ID) {
			Inventory[a] = -1;
			return;
		}
	}
}

void UInventoryComponent::removeItemBySlotIndex(int Index) {
	Inventory[Index] = -1;
}




void UInventoryComponent::InventoryPrint() {
	for (int a = 0; a != Inventory.Num(); a++) {
		if (GEngine) {
			if (Inventory[a]) { GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Item: %s"), Inventory[a])); }
		}
	}
}

void UInventoryComponent::RefreshHotInventory()
{
	for (int a = 0; a != HotInventory.Num(); a++) {
		if (HotInventory[a]!=-1) {
			if (Inventory[HotInventory[a]] == -1) {
				HotInventory[a] = -1;
			}
		}
	}
}
