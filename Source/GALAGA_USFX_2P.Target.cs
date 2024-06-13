// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class GALAGA_USFX_2PTarget : TargetRules
{
	public GALAGA_USFX_2PTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.Add("GALAGA_USFX_2P");
	}
}
