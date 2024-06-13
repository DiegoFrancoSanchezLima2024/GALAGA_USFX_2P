// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class GALAGA_USFX_2PEditorTarget : TargetRules
{
	public GALAGA_USFX_2PEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.Add("GALAGA_USFX_2P");
	}
}
