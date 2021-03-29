// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

[SupportedPlatforms(UnrealPlatformClass.Server)]
public class AccelManiaServerTarget : TargetRules   // Change this line as shown previously
{
    public AccelManiaServerTarget(TargetInfo Target) : base(Target)  // Change this line as shown previously
    {
#if UE_4_24_OR_LATER
        DefaultBuildSettings = BuildSettingsVersion.V2;
#endif
        Type = TargetType.Server;
        ExtraModuleNames.Add("AccelMania");    // Change this line as shown previously
    }
}