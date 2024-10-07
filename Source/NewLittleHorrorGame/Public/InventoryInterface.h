#pragma once

#include "CoreMinimal.h"
#include "InventoryComponent.h"
#include "UObject/Interface.h"
#include "InventoryInterface.generated.h"

UINTERFACE(MinimalAPI)
class UInventoryInterface : public UInterface
{
	GENERATED_BODY()
};

class IInventoryInterface
{
	GENERATED_BODY()

public:
	virtual UInventoryComponent* getIvenwntoryComponent() = 0;
};
