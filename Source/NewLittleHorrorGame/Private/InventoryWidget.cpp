// Fill out your copyright notice in the Description page of Project Settings.


#include <InventoryWidget.h>
#include <NewLittleHorrorGame/NewLittleHorrorGameCharacter.h>
#include <Kismet/GameplayStatics.h>
#include <ItemInfo.h>


void UInventoryWidget::UpdateItemSlot(int Index) {
    
        UInventoryComponent* InventoryCom = (Cast<IInventoryInterface>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0)))->getIvenwntoryComponent();
        inventorySlot[Index]->ItemID = InventoryCom->Inventory[Index]; // set correct ID

        FItemInfoStructure* Row = DataTableIDtoInfo->FindRow<FItemInfoStructure>(FName(*FString::FromInt(inventorySlot[Index]->ItemID)), "");

        if (Row && inventorySlot[Index]->TitleImage) { // set correct immage
                inventorySlot[Index]->TitleImage->SetBrushFromTexture(Row->Image.LoadSynchronous());
        }
}

void UInventoryWidget::UpdateHotItemSlot(int Index) {
   
        UInventoryComponent* InventoryCom = (Cast<IInventoryInterface>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0)))->getIvenwntoryComponent();
        HotInventorySlot[Index]->ItemID = getCorrectHotItemID(InventoryCom, Index);// set correct ID

        FItemInfoStructure* Row = DataTableIDtoInfo->FindRow<FItemInfoStructure>(FName(*FString::FromInt(HotInventorySlot[Index]->ItemID)), "");

        if (Row && HotInventorySlot[Index]->TitleImage) {// set correct immage
                    HotInventorySlot[Index]->TitleImage->SetBrushFromTexture(Row->Image.LoadSynchronous());
        }
}

void UInventoryWidget::UpdateItemAndHotItemSlots(int Index)
{
    UpdateItemSlot(Index);
    UpdateAllHotItemSlot();
}

void UInventoryWidget::UpdateAllItemSlot()
{
    for (int indexCounter = 0; indexCounter < inventorySlot.Num(); indexCounter++) {
        UpdateItemSlot(indexCounter);
    }
}

void UInventoryWidget::UpdateAllHotItemSlot()
{
    for (int indexCounter = 0; HotInventorySlot.Num()> indexCounter; indexCounter++) {
        UpdateHotItemSlot(indexCounter);
    }
}

void UInventoryWidget::setDefoult()
{
    UpdateAllItemSlot();
    UpdateAllHotItemSlot();
}

void UInventoryWidget::UpdateHotItemByOnecChenged(int InventeryNamber)
{
    UInventoryComponent* InventoryCom = (Cast<IInventoryInterface>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0)))->getIvenwntoryComponent();

    for (int indexCounter = 0; InventoryCom->HotInventory.Num() > indexCounter; indexCounter++) {//if someone has refresh in hot item update it
        if (InventoryCom->HotInventory[indexCounter] == InventeryNamber) {
            UpdateHotItemSlot(indexCounter);
            return;
        }
    }
}

int UInventoryWidget::getCorrectHotItemID(UInventoryComponent* inventory, int index)
{
    if (inventory->HotInventory[index] != -1) { // if HotInventory isn`t refresh in object (ID) return null object (ID=-1)
        return inventory->Inventory[inventory->HotInventory[index]];
    }
    else {
        return -1;
    }
}

