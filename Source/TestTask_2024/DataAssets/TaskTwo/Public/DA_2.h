// RedRuins Softworks (c)

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "TestTask_2024/Enums/TaskTwo/Public/TestEnum.h"
#include "DA_2.generated.h"

/**
 * 
 */
UCLASS()
class TESTTASK_2024_API UDA_2 : public UDataAsset
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly)
	ETestEnum Enumeration;

	UPROPERTY(EditDefaultsOnly, meta = (EditCondition = "Enumeration == ETestEnum::value_true", EditConditionHides))
	class UDA_1* DataAsset1 = nullptr;
};
