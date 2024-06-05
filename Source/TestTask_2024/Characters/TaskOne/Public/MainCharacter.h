// RedRuins Softworks (c)

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MainCharacter.generated.h"

class UUserWidget;

UCLASS()
class TESTTASK_2024_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainCharacter();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float InteractDistance = 1.5f;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY()
	AActor* LookAtActor = nullptr;

	UFUNCTION(BlueprintCallable)
	void InteractionTrace();

};
