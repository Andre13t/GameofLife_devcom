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


	ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAssetAlive(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAssetDead(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));

	AliveMesh = MeshAssetAlive.Object;
	DeadMesh = MeshAssetDead.Object;
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

