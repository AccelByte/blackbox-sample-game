// Copyright (c) 2019 AccelByte Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HAL/RunnableThread.h"
#include "ZeroCrashTestActor.generated.h"
 
UCLASS()
class ACCELMANIA_API AZeroCrashTestActor : public AActor
{
    GENERATED_BODY()

private:
    FRunnableThread* MemStomperTh;
public:
    // Sets default values for this actor's properties
    AZeroCrashTestActor();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;
    UFUNCTION(BlueprintCallable, meta = (HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject", DisplayName = "Zero Crash", Keywords = "AccelMania Zero Crash"), Category = "AccelMania")
        int ZeroCrash();
    UFUNCTION(BlueprintCallable, meta = (HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject", DisplayName = "Null Ptr Crash", Keywords = "AccelMania Null Ptr"), Category = "AccelMania")
        int NullPtrCrash();
    UFUNCTION(BlueprintCallable, meta = (HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject", DisplayName = "Memory Stomp", Keywords = "AccelMania Memory Stomp"), Category = "AccelMania")
        int MemoryStomp();
};
