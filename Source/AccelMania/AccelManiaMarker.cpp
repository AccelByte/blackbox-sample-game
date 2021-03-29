// Copyright (c) 2020 AccelByte Inc. All Rights Reserved.
// This is licensed software from AccelByte Inc, for limitations
// and restrictions contact your company contract manager.

#include "AccelManiaMarker.h"

// Sets default values
AAccelManiaMarker::AAccelManiaMarker()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AAccelManiaMarker::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void AAccelManiaMarker::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}
