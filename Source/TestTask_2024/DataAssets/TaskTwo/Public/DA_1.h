// RedRuins Softworks (c)

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "TestTask_2024/Structures/TaskTwo/Public/TestStructure.h"
#include "DA_1.generated.h"

/**
 * 
 */
UCLASS()
class TESTTASK_2024_API UDA_1 : public UDataAsset
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly)
	FTestStructure TestStructure;
};
