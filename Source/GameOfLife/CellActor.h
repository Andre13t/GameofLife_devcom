// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CellActor.generated.h"

UCLASS()
class GAMEOFLIFE_API ACellActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACellActor();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// create a static mesh component we can use and this is a class off UStaticMeshComponent,
	// and a garbage collectio can collect any time and u have do put a UPROPERTY()
	
	UPROPERTY(VisibleAnywhere) UStaticMeshComponent* StaticMeshComponent;

protected:
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:	
	UPROPERTY() UStaticMesh* AliveMesh;
	UPROPERTY() UStaticMesh* DeadMesh;
	
	UFUNCTION() void ChangeState();
	
	bool isAllive{};
	
	void SetCellDead();
	void SetCellAlive();
	
};
