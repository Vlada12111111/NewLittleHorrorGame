// Fill out your copyright notice in the Description page of Project Settings.


#include <InventoryWidget.h>
#include <NewLittleHorrorGame/NewLittleHorrorGameCharacter.h>
#include <Kismet/GameplayStatics.h>
#include <ItemInfo.h>


void UInventoryWidget::UpdateItemSlotByIndex(int Index) {
    if (inventorySlot[Index]) {

        ANewLittleHorrorGameCharacter* PlayerPawn = Cast<ANewLittleHorrorGameCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
        inventorySlot[Index]->Item = PlayerPawn->Inventory->inventory[Index];


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

        ANewLittleHorrorGameCharacter* PlayerPawn = Cast<ANewLittleHorrorGameCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
        if (PlayerPawn->Inventory->HotItem[Index]!=-1) {
        
            HotInventorySlot[Index]->Item = PlayerPawn->Inventory->inventory[PlayerPawn->Inventory->HotItem[Index]];


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

    ANewLittleHorrorGameCharacter* PlayerPawn = Cast<ANewLittleHorrorGameCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));

    if (PlayerPawn) {

        for (int a = 0; a < inventorySlot.Num(); a++) {

            if (inventorySlot[a]) {

                inventorySlot[a]->Item = PlayerPawn->Inventory->inventory[a];

            }
        }


        for (int a = 0; a < HotInventorySlot.Num(); a++) {

            if (HotInventorySlot[a]) {

                if(PlayerPawn->Inventory->HotItem[a]!=-1){
                    HotInventorySlot[a]->Item = PlayerPawn->Inventory->inventory[PlayerPawn->Inventory->HotItem[a]];
                }
                else {
                    HotInventorySlot[a]->Item = NewObject<UItem>();
                }

                

            }
        }



    }

}