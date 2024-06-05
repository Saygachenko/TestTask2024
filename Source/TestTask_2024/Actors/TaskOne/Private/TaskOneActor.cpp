// RedRuins Softworks (c)


#include "TestTask_2024/Actors/TaskOne/Public/TaskOneActor.h"

#include "Components/WidgetComponent.h"

// Sets default values
ATaskOneActor::ATaskOneActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	WidgetComponent = CreateDefaultSubobject<UWidgetComponent>(FName("InteractWidgetComponent"));
	WidgetComponent->SetupAttachment(GetRootComponent());

	WidgetComponent->SetHiddenInGame(true);
}

// Called when the game starts or when spawned
void ATaskOneActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATaskOneActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATaskOneActor::LookAtStart_Implementation()
{
	if (WidgetComponent)
	{
		WidgetComponent->SetHiddenInGame(false);
	}
}

void ATaskOneActor::LookAtEnd_Implementation()
{
	if (WidgetComponent)
	{
		WidgetComponent->SetHiddenInGame(true);
	}
}