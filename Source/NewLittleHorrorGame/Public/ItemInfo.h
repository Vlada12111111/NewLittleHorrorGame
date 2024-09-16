// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <Components/Image.h>
#include "Engine/DataTable.h" 
#include "Engine/Texture2D.h"
#include "Engine/StaticMesh.h"
#include "UObject/NoExportTypes.h"
#include "ItemInfo.generated.h"


/**
 * 
 */
USTRUCT(BlueprintType)
struct NEWLITTLEHORRORGAME_API FItemInfoStructure : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<UTexture2D> Image;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<UStaticMesh> Mesh;
};
