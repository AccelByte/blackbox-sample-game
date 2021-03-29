// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class AccelMania : ModuleRules
{
    public AccelMania(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.NoSharedPCHs;
        PrivatePCHHeaderFile = "AccelmaniaPch.h";
        CppStandard = CppStandardVersion.Cpp17;
        bAllowConfidentialPlatformDefines = true;
        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "JsonUtilities", "RenderCore" });
        PublicDefinitions.Add("SDK_INTEGRATION_TEST=0");
    }
}
