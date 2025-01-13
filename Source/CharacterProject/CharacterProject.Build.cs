// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CharacterProject : ModuleRules
{
	public CharacterProject(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
