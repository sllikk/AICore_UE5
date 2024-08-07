// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class AI_Core : ModuleRules
{
	public AI_Core(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "AIModule", "GameplayTags", 
			"GameplayTasks", "Navmesh", "NavigationSystem" });

		PrivateDependencyModuleNames.AddRange(new string[] { "UMG", "Chaos", "FieldSystemEngine", "GeometryCollectionEngine" });

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
