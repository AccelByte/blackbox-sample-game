// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "AccelManiaGameMode.generated.h"

UCLASS(minimalapi)
class AAccelManiaGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AAccelManiaGameMode();
	
	void BeginPlay();
    void EndPlay(const EEndPlayReason::Type EndPlayReason);
	virtual void Tick(float DeltaTime) override;
	virtual void PostLogin(APlayerController* NewPlayer);

private:
    APlayerController * CurrentPlayerController;
};


