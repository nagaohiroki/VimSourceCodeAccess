// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class VimSourceCodeAccess : ModuleRules
{
	public VimSourceCodeAccess(ReadOnlyTargetRules Target) : base(Target)
	{
	//	PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"SourceCodeAccess",
				"DesktopPlatform",
				"Json"
			}
			);
		if (Target.bBuildEditor)
		{
			PrivateDependencyModuleNames.Add("HotReload");
		}
	}
}
