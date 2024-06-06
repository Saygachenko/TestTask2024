// RedRuins Softworks (c)


#include "TestTask_2024/Components/TaskOne/Public/InteractionComponent.h"

#include "TestTask_2024/Interfaces/TaskOne/Public/InteractInterface.h"
#include "TestTask_2024/Characters/TaskOne/Public/MainCharacter.h"

// Sets default values for this component's properties
UInteractionComponent::UInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	Owner = GetOwner();
	OwnerCharacter = Cast<AMainCharacter>(Owner);
	OwnerController = OwnerCharacter->GetController();
}

// Called every frame
void UInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	InteractionTrace();
}

void UInteractionComponent::InteractionTrace()
{
	UWorld* World = GetWorld();
	if (World)
	{
		if (Owner)
		{
			if (OwnerCharacter)
			{
				if (OwnerController)
				{
					FVector ViewLocation;
					FRotator ViewRotation;
					OwnerController->GetPlayerViewPoint(ViewLocation, ViewRotation);

					FHitResult HitResult;
					const FVector TraceStart = OwnerCharacter->GetActorLocation();
					const FVector TraceDirection = TraceStart - ViewLocation;
					const FVector ProjectedVector = TraceDirection.ProjectOnToNormal(ViewRotation.Vector());
					const FVector TraceEnd = ViewLocation + ProjectedVector * InteractDistance;

					FCollisionQueryParams QueryParams;
					QueryParams.AddIgnoredActor(OwnerCharacter);

					bool bTraceResult = World->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, ECC_Visibility, QueryParams);
					if (bTraceResult)
					{
						if (HitResult.GetActor() != LookAtActor)
						{
							if (LookAtActor && LookAtActor->GetClass()->ImplementsInterface(UInteractInterface::StaticClass()))
							{
								IInteractInterface::Execute_LookAtEnd(LookAtActor);
							}

							LookAtActor = HitResult.GetActor();

							if (LookAtActor && LookAtActor->GetClass()->ImplementsInterface(UInteractInterface::StaticClass()))
							{
								IInteractInterface::Execute_LookAtStart(LookAtActor);
							}
						}
					}
					else
					{
						if (LookAtActor && LookAtActor->GetClass()->ImplementsInterface(UInteractInterface::StaticClass()))
						{
							IInteractInterface::Execute_LookAtEnd(LookAtActor);
						}

						LookAtActor = nullptr;
					}
				}
			}
		}
	}
}

void UInteractionComponent::Interact()
{
	if (LookAtActor)
	{
		if (LookAtActor->GetClass()->ImplementsInterface(UInteractInterface::StaticClass()))
		{
			IInteractInterface::Execute_InteractWith(LookAtActor);
		}
	}
}