// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "VimSourceCodeAccessor.h"

class FVimSourceCodeAccessModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	FVimSourceCodeAccessor& GetAccessor();
private:

	FVimSourceCodeAccessor VimSourceCodeAccessor;
};
