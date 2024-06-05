// RedRuins Softworks (c)

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InteractInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInteractInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class TESTTASK_2024_API IInteractInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void LookAtStart();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void LookAtEnd();

	// Function interacting with item
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void InteractWith();
};
