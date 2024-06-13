// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GALAGA_USFX_2P : ModuleRules
{
	public GALAGA_USFX_2P(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });
	}
}
