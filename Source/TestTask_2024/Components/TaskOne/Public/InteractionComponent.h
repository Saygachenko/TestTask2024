// RedRuins Softworks (c)

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InteractionComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TESTTASK_2024_API UInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInteractionComponent();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void Interact();

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float InteractDistance = 1.4f;

	// Called when the game starts
	virtual void BeginPlay() override;
		
private:
	UPROPERTY()
	AActor* LookAtActor = nullptr;

	UPROPERTY()
	class AMainCharacter* OwnerCharacter;

	UFUNCTION(BlueprintCallable)
	void InteractionTrace();
};
