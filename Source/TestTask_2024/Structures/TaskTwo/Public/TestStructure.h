// RedRuins Softworks (c)

#pragma once

#include "CoreMinimal.h"
#include "TestStructure.generated.h"

USTRUCT(BlueprintType)
struct FTestStructure
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	class UDA_2* DataAsset1 = nullptr;

	UPROPERTY(EditDefaultsOnly)
	FName Name = FName();

	UPROPERTY(EditDefaultsOnly)
	UTexture* Texture = nullptr;

	UPROPERTY(EditDefaultsOnly)
	FVector Vector = FVector();
};