// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class AccelManiaTarget : TargetRules
{
	public AccelManiaTarget(TargetInfo Target) : base(Target)
	{
#if UE_4_24_OR_LATER
        DefaultBuildSettings = BuildSettingsVersion.V2;
#endif
        Type = TargetType.Game;
		ExtraModuleNames.Add("AccelMania");
	}
}
