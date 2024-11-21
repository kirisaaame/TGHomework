// Copyright Epic Games, Inc. All Rights Reserved.

#include "HomeworkWK1GameMode.h"
#include "HomeworkWK1PlayerController.h"
#include "HomeworkWK1Character.h"
#include "UObject/ConstructorHelpers.h"

AHomeworkWK1GameMode::AHomeworkWK1GameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AHomeworkWK1PlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}