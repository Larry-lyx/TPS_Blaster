// Fill out your copyright notice in the Description page of Project Settings.


#include "BlasterGameMode.h"

void ABlasterGameMode::PlayerEliminated(ABlasterCharacter* ElimCharacter, ABlasterPlayerController* VictimController,
	ABlasterPlayerController* AttackerController)
{
	if (ElimCharacter)
	{
		ElimCharacter->Elim();
	}
}
