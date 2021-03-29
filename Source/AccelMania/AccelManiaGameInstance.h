#pragma once

#include "Engine/GameInstance.h"
#include "AccelManiaGameInstance.generated.h"

UCLASS(config = Game, transient, BlueprintType, Blueprintable)
class UAccelManiaGameInstance : public UGameInstance
{
    GENERATED_BODY()

public:
    void Init() override;
    void Shutdown() override;
    void OnStart() override;
};
