// Copyright (c) 2019 AccelByte Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "HAL/Runnable.h"

/**
 *
 */
class ACCELMANIA_API FMemoryStomper : public FRunnable
{
private:
    uint32* Stomp;
    uint32 InitialStomperSz;
    int64 backIdx;
    int64 frontIdx;
public:
    FMemoryStomper();
    virtual ~FMemoryStomper();
    void Exit() override;
    bool Init() override;
    uint32 Run() override;
    void Stop() override;
};
