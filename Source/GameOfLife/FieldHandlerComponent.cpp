// (c)2021 Andre Dias


#include "FieldHandlerComponent.h"
#include "CellActor.h"

// Sets default values for this component's properties
UFieldHandlerComponent::UFieldHandlerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UFieldHandlerComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UFieldHandlerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void  UFieldHandlerComponent::initField(int32 sizeX, int32 sizeY, float cellDistance, float baseLocatX, float baseLocatY)
{
	int32 i, j;
	FVector locationMap{};
	FRotator rotationMap{};
	FActorSpawnParameters SpawnParameters;
	AActor* SpawnedCell;

	SpawnParameters = FActorSpawnParameters();
	SpawnParameters.Owner = GetOwner();
	SpawnParameters.bNoFail = true;
	rotationMap = FRotator::ZeroRotator;

	for (i = 0; i < sizeX; i++)
	{
		for (j = 0; j < sizeY; j++)
		{
			locationMap.Y = (i * cellDistance) + baseLocatX;
			locationMap.Z = (j * cellDistance) + baseLocatY;
			SpawnedCell = GetWorld()->SpawnActor(CellActor, &locationMap, &rotationMap, SpawnParameters);
		}
	}
}
