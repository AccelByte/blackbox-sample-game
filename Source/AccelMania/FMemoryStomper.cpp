// Copyright (c) 2019 AccelByte Inc. All Rights Reserved.

#include "FMemoryStomper.h"
#include "AccelManiaLog.h"
#include "Launch/Resources/Version.h"

#if defined(PLATFORM_WINDOWS) && PLATFORM_WINDOWS
#    include "Windows/WindowsPlatformProcess.h"
#elif defined(PLATFORM_LINUX) && PLATFORM_LINUX
#    include "GenericPlatform/GenericPlatformProcess.h"
#elif (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE) &&                                                               \
    ((defined(PLATFORM_XBOXONEGDK) && !PLATFORM_XBOXONEGDK) || !defined(PLATFORM_XBOXONEGDK))
#    if ENGINE_MINOR_VERSION >= 26
#        include "XboxOnePlatformProcess.h"
#    else
#        include "XboxOne/XboxOnePlatformProcess.h"
#    endif
#endif

#if (defined(PLATFORM_XBOXONEGDK) && PLATFORM_XBOXONEGDK) || (defined(PLATFORM_XSX) && PLATFORM_XSX)
#    include "XboxCommonGDKPlatformProcess.h"
#endif

#if defined(PLATFORM_XSX) && PLATFORM_XSX
#    include "XSXPlatformProcess.h"
#endif

FMemoryStomper::FMemoryStomper()
    : InitialStomperSz(50)
    , backIdx(InitialStomperSz)
    , frontIdx(-1)
{
    Stomp = new uint32[50];
}

FMemoryStomper::~FMemoryStomper()
{
    delete[] Stomp;
}

void FMemoryStomper::Exit()
{
}

bool FMemoryStomper::Init()
{
    return true;
}

uint32 FMemoryStomper::Run()
{
    while (1) {
        UE_LOG(
            LogAccelMania, Log, TEXT("Stomping Memory[0x%x, 0x%x]"), (int64)Stomp + frontIdx, (int64)Stomp + backIdx);
        *(Stomp + backIdx) = FMath::Rand();
        *(Stomp + frontIdx) = FMath::Rand();
        backIdx = FMath::Rand();
        frontIdx = -FMath::Rand();
#if PLATFORM_LINUX
        FGenericPlatformProcess::Sleep(0.3f);
#elif (defined(PLATFORM_XBOXONEGDK) && PLATFORM_XBOXONEGDK) || (defined(PLATFORM_XSX) && PLATFORM_XSX)
        FXboxCommonGDKPlatformProcess::Sleep(0.3f);
#endif
    }
    return 0;
}

void FMemoryStomper::Stop()
{
}
