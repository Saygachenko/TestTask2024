// RedRuins Softworks (c)

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MarkerInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UMarkerInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class TESTTASK_2024_API IMarkerInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void UpdateDistance(const FText& NewDistance);
};
