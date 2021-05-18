// (c)2021 Andre Dias

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FieldHandlerComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAMEOFLIFE_API UFieldHandlerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UFieldHandlerComponent();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)void initField(int32 sizeX, int32 sizeY, float cellDistance, float baseLocatX, float baseLocatY);

	UPROPERTY(EditAnyWhere)TSubclassOf<AActor> CellActor;
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:	
	
		
};
