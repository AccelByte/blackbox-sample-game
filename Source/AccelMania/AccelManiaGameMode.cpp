// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "AccelManiaGameMode.h"
#include "AccelManiaHUD.h"
#include "AccelManiaCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "AccelManiaLog.h"

AAccelManiaGameMode::AAccelManiaGameMode()
    : Super()
{
    // set default pawn class to our Blueprinted character
    static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
    DefaultPawnClass = PlayerPawnClassFinder.Class;

    // use our custom HUD class
    HUDClass = AAccelManiaHUD::StaticClass();

    PrimaryActorTick.bStartWithTickEnabled = true;
    PrimaryActorTick.bCanEverTick = true;
}

void AAccelManiaGameMode::BeginPlay()
{
    Super::BeginPlay();
    UE_LOG(LogTemp, Warning, TEXT("GameMode BeginPlay"));
}

void AAccelManiaGameMode::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    Super::EndPlay(EndPlayReason);
    UE_LOG(LogTemp, Warning, TEXT("GameMode EndPlay"));
}

void AAccelManiaGameMode::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AAccelManiaGameMode::PostLogin(APlayerController * NewPlayer)
{
    // only work on single player
    Super::PostLogin(NewPlayer);
    FString LevelName = TEXT("FirstPersonExampleMap");
    
    CurrentPlayerController = NewPlayer;
}
