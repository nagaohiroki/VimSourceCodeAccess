// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "VimSourceCodeAccess.h"
#include "Modules/ModuleManager.h"
#include "Features/IModularFeatures.h"

#define LOCTEXT_NAMESPACE "FVimSourceCodeAccessModule"

void FVimSourceCodeAccessModule::StartupModule()
{
	IModularFeatures::Get().RegisterModularFeature(TEXT("SourceCodeAccessor"), &VimSourceCodeAccessor);
}

void FVimSourceCodeAccessModule::ShutdownModule()
{
	IModularFeatures::Get().UnregisterModularFeature(TEXT("SourceCodeAccessor"), &VimSourceCodeAccessor);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FVimSourceCodeAccessModule, VimSourceCodeAccess)