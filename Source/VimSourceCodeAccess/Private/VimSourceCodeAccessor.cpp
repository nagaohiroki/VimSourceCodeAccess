// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "VimSourceCodeAccessor.h"
#include "HAL/PlatformProcess.h"

#define LOCTEXT_NAMESPACE "VimSourceCodeAccessor"
void FVimSourceCodeAccessor::RefreshAvailability() {}

bool FVimSourceCodeAccessor::CanAccessSourceCode() const
{
	return true;
}

bool FVimSourceCodeAccessor::DoesSolutionExist() const
{
	return true;
}

FName FVimSourceCodeAccessor::GetFName() const
{
	return FName("VimSourceCodeAccessor");
}

FText FVimSourceCodeAccessor::GetNameText() const
{
	return LOCTEXT("VimDisplayName", "Vim");
}

FText FVimSourceCodeAccessor::GetDescriptionText() const
{
	return LOCTEXT("VimDisplayDesc", "Open source code files in Vim");
}

bool FVimSourceCodeAccessor::OpenSolution()
{
	return true;
}

bool FVimSourceCodeAccessor::OpenSolutionAtPath(const FString& InSolutionPath)
{
	return true;
}

bool FVimSourceCodeAccessor::OpenFileAtLine(const FString& FullPath, int32 LineNumber, int32 ColumnNumber)
{
	const FString Param = FString::Format(TEXT("--remote-silent +\"call cursor({0}, {1})\" \"{2}\""), {LineNumber, ColumnNumber, FullPath});
	FProcHandle Proc = FPlatformProcess::CreateProc(TEXT("D:\\vim\\gvim.exe"), *Param, true, true, false, nullptr, 0, nullptr, nullptr);
	if(!Proc.IsValid())
	{
		FPlatformProcess::CloseProc(Proc);
	}
	return true;
}

bool FVimSourceCodeAccessor::OpenSourceFiles(const TArray<FString>& AbsoluteSourcePaths)
{
	return true;
}

bool FVimSourceCodeAccessor::AddSourceFiles(const TArray<FString>& AbsoluteSourcePaths, const TArray<FString>& AvailableModules)
{
	return false;
}

bool FVimSourceCodeAccessor::SaveAllOpenDocuments() const
{
	return true;
}
#undef LOCTEXT_NAMESPACE
