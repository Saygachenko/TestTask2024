// RedRuins Softworks (c)


#include "TestTask_2024/Actors/TaskOne/Public/TaskOneActor.h"

#include "Components/WidgetComponent.h"
#include "TestTask_2024/Interfaces/TaskOne/Public/MarkerInterface.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"

// Sets default values
ATaskOneActor::ATaskOneActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(FName("StaticMeshComponent"));
	RootComponent = StaticMeshComponent;

	WidgetComponent = CreateDefaultSubobject<UWidgetComponent>(FName("InteractWidgetComponent"));
	WidgetComponent->SetupAttachment(GetRootComponent());

	WidgetComponent->SetHiddenInGame(true);

	MarkerWidgetComponent = CreateDefaultSubobject<UWidgetComponent>(FName("MarkerWidgetComponent"));
	MarkerWidgetComponent->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void ATaskOneActor::BeginPlay()
{
	Super::BeginPlay();
	
	if (MarkerWidgetComponent)
	{
		World = GetWorld();
		MainCharacter = UGameplayStatics::GetPlayerCharacter(World, 0);
		MarkerWidget = MarkerWidgetComponent->GetUserWidgetObject();
	}
}

// Called every frame
void ATaskOneActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	DistanceCalculation();
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

void ATaskOneActor::InteractWith_Implementation()
{
	if (StaticMeshComponent)
	{
		UMaterialInstanceDynamic* MaterialInstance = StaticMeshComponent->CreateAndSetMaterialInstanceDynamic(0);
		if (MaterialInstance)
		{
			MaterialInstance->SetVectorParameterValue(MaterialColorName, Color);
		}
	}
}

void ATaskOneActor::DistanceCalculation()
{
	if (World && MarkerWidgetComponent && MarkerWidget && MainCharacter)
	{
		if (MarkerWidget->GetClass()->ImplementsInterface(UMarkerInterface::StaticClass()))
		{
			FVector ActorLocation = GetActorLocation();
			FVector CharacterLocation = MainCharacter->GetActorLocation();
			float Distance = FVector::Dist(ActorLocation, CharacterLocation) / 100.0f;
			auto TruncInt = FMath::TruncToInt(Distance);
			if (TruncInt > 1)
			{
				MarkerWidgetComponent->SetHiddenInGame(false);

				FString DistanceString = FString::Printf(TEXT("%i m"), TruncInt);
				FText DistanceText = FText::FromString(DistanceString);

				IMarkerInterface::Execute_UpdateDistance(MarkerWidget, DistanceText);
			}
			else
			{
				MarkerWidgetComponent->SetHiddenInGame(true);
			}
		}
	}
}