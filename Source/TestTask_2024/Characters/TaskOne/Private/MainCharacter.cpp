// RedRuins Softworks (c)


#include "TestTask_2024/Characters/TaskOne/Public/MainCharacter.h"

#include "Kismet/GameplayStatics.h"
#include "TestTask_2024/Interfaces/TaskOne/Public/InteractInterface.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

// Sets default values
AMainCharacter::AMainCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	InteractionTrace();
}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* Input = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		Input->BindAction(InteractInputAction, ETriggerEvent::Started, this, &AMainCharacter::Interact);
	}
}

void AMainCharacter::InteractionTrace()
{
	UWorld* World = GetWorld();
	if (World)
	{
		AController* MainController = GetController();
		if (MainController)
		{
			FVector ViewLocation;
			FRotator ViewRotation;
			MainController->GetPlayerViewPoint(ViewLocation, ViewRotation);

			FHitResult HitResult;
			const FVector TraceStart = GetActorLocation();
			const FVector TraceDirection = TraceStart - ViewLocation;
			const FVector ProjectedVector = TraceDirection.ProjectOnToNormal(ViewRotation.Vector());
			const FVector TraceEnd = ViewLocation + ProjectedVector * InteractDistance;

			FCollisionQueryParams QueryParams;
			QueryParams.AddIgnoredActor(this);

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

void AMainCharacter::Interact()
{
	if (LookAtActor)
	{
		if (LookAtActor->GetClass()->ImplementsInterface(UInteractInterface::StaticClass()))
		{
			IInteractInterface::Execute_InteractWith(LookAtActor);
		}
	}
}