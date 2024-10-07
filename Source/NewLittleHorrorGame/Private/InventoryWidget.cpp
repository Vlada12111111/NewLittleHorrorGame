// Fill out your copyright notice in the Description page of Project Settings.


#include <InventoryWidget.h>
#include <NewLittleHorrorGame/NewLittleHorrorGameCharacter.h>
#include <Kismet/GameplayStatics.h>
#include <ItemInfo.h>


void UInventoryWidget::UpdateItemSlotByIndex(int Index) {
    if (inventorySlot[Index]) {

        UInventoryComponent* InventoryCom = (Cast<IInventoryInterface>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0)))->getIvenwntoryComponent();
        inventorySlot[Index]->Item = InventoryCom->inventory[Index];

        FItemInfoStructure* Row = DataTableIDtoInfo->FindRow<FItemInfoStructure>(FName(*FString::FromInt(inventorySlot[Index]->Item->ID)), "");

        if (Row) {
            UTexture2D* LoadedTexture = Row->Image.LoadSynchronous();
            if (LoadedTexture && inventorySlot[Index]->TitleImage) {
                inventorySlot[Index]->TitleImage->SetBrushFromTexture(LoadedTexture);

            }
        }
    }
}

void UInventoryWidget::UpdateHotItemSlotByIndex(int Index) {
    if (HotInventorySlot[Index]) {

        UInventoryComponent* InventoryCom = (Cast<IInventoryInterface>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0)))->getIvenwntoryComponent();

        if (InventoryCom->HotItem[Index]!=-1) {
        
            HotInventorySlot[Index]->Item = InventoryCom->inventory[InventoryCom->HotItem[Index]];


            FItemInfoStructure* Row = DataTableIDtoInfo->FindRow<FItemInfoStructure>(FName(*FString::FromInt(HotInventorySlot[Index]->Item->ID)), "");

            if (Row) {
                UTexture2D* LoadedTexture = Row->Image.LoadSynchronous();
                if (LoadedTexture && HotInventorySlot[Index]->TitleImage) {
                    HotInventorySlot[Index]->TitleImage->SetBrushFromTexture(LoadedTexture);

                }
            }
        
        }
        else {

            HotInventorySlot[Index]->Item = NewObject<UItem>();


            FItemInfoStructure* Row = DataTableIDtoInfo->FindRow<FItemInfoStructure>(FName(*FString::FromInt(-1)), "");

            if (Row) {
                UTexture2D* LoadedTexture = Row->Image.LoadSynchronous();
                if (LoadedTexture && HotInventorySlot[Index]->TitleImage) {
                    HotInventorySlot[Index]->TitleImage->SetBrushFromTexture(LoadedTexture);

                }
            }
        }
    }
}

void UInventoryWidget::setDefoult()
{

    UInventoryComponent* InventoryCom = (Cast<IInventoryInterface>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0)))->getIvenwntoryComponent();

    if (InventoryCom) {

        for (int a = 0; a < inventorySlot.Num(); a++) {

            if (inventorySlot[a]) {

                inventorySlot[a]->Item = InventoryCom->inventory[a];

            }
        }


        for (int a = 0; a < HotInventorySlot.Num(); a++) {

            if (HotInventorySlot[a]) {

                if(InventoryCom->HotItem[a]!=-1){
                    HotInventorySlot[a]->Item = InventoryCom->inventory[InventoryCom->HotItem[a]];
                }
                else {
                    HotInventorySlot[a]->Item = NewObject<UItem>();
                }
            }
        }
    }
}