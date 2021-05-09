// Fill out your copyright notice in the Description page of Project Settings.


#include "CellActor.h"

// Sets default values
ACellActor::ACellActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// create a root component scene we can attach more thinghs to
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("ActorRootComponent"));

	// create the sttic mesh component so the actor can  actually look like something
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ActorMesh"));

	// setting the visual mesh
	// this is a bad thing to do because if the file changes the location it will break


	ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAssetAlive(TEXT("StaticMesh'/Game/Assets/Cube.Cube'"));
	ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAssetDead(TEXT("StaticMesh'/Game/Assets/Sphere.Sphere'"));

	// test if the objetc is working correctly
	if (MeshAssetAlive.Object)
	{
		AliveMesh = MeshAssetAlive.Object;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("ACellActor::ACellActor() : Failed to find mesh asset for alive state"));
	}
	if (MeshAssetDead.Object)
	{
		DeadMesh = MeshAssetDead.Object;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("ACellActor::ACellActor() : Failed to find mesh asset for dead state"));
	}
	
	SetCellDead();
	
	// attach our loaded static mesh to the root component to show it
	StaticMeshComponent->SetupAttachment(RootComponent);
}

// define the mesh that will be the dead
void ACellActor::SetCellDead()
{
	StaticMeshComponent->SetStaticMesh(DeadMesh);
}

// define the mesh that will be the Alive
void ACellActor::SetCellAlive()
{
	StaticMeshComponent->SetStaticMesh(AliveMesh);
}

// Called when the game starts or when spawned
void ACellActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACellActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

