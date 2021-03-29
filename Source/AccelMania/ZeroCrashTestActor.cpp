// Copyright (c) 2019 AccelByte Inc. All Rights Reserved.

#include "ZeroCrashTestActor.h"
#include "FMemoryStomper.h"
#include "AccelManiaLog.h"
// Sets default values
AZeroCrashTestActor::AZeroCrashTestActor()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AZeroCrashTestActor::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void AZeroCrashTestActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}
// NOTE(Maxwell): PS5 clang errors on these pragmas for being an unrecognized warning
#if defined(PLATFORM_WINDOWS) && PLATFORM_WINDOWS
#pragma warning( push )
#pragma warning( disable : 4723)
#endif
int AZeroCrashTestActor::ZeroCrash()
{
    volatile int x = 10;
    volatile int y = 0;
    return x / y;
}
#if defined(PLATFORM_WINDOWS) && PLATFORM_WINDOWS
#pragma warning( pop )
#endif
int AZeroCrashTestActor::NullPtrCrash()
{
    volatile int* i = nullptr;
    volatile int z = 5 + *i;
    return *i;
}

int AZeroCrashTestActor::MemoryStomp()
{
    UE_LOG(LogAccelMania, Log, TEXT("Starting Memory Stomper thread"));
    MemStomperTh = FRunnableThread::Create(new FMemoryStomper(), TEXT("Memory Stomper"), 0, TPri_Normal);
    return 0;
}
