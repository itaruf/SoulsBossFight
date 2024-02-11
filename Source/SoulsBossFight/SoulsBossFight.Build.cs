// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SoulsBossFight : ModuleRules
{
	public SoulsBossFight(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
