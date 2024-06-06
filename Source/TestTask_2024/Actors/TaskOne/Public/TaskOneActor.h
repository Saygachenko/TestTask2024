// RedRuins Softworks (c)

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestTask_2024/Interfaces/TaskOne/Public/InteractInterface.h"
#include "TaskOneActor.generated.h"

class UWidgetComponent;

UCLASS()
class TESTTASK_2024_API ATaskOneActor : public AActor, public IInteractInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATaskOneActor();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void LookAtStart_Implementation();

	void LookAtEnd_Implementation();

	void InteractWith_Implementation();

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* StaticMeshComponent = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
	UWidgetComponent* WidgetComponent = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
	UWidgetComponent* MarkerWidgetComponent = nullptr;

	UPROPERTY(EditDefaultsOnly)
	FName MaterialColorName = "Base Color";

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly)
	FLinearColor Color = FLinearColor::Red;

	void DistanceCalculation();
};
