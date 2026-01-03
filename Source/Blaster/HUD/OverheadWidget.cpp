// Fill out your copyright notice in the Description page of Project Settings.


#include "OverheadWidget.h"

#include "Components/TextBlock.h"

void UOverheadWidget::SetDisplayText(FString TextToDisplay)
{
	if (DisplayText)
	{
		DisplayText->SetText(FText::FromString(TextToDisplay));
	}
}

void UOverheadWidget::ShowPlayerNetRole(APawn* InPawn)
{
	ENetRole LocalRole = InPawn->GetLocalRole();
	FString Role;
	switch (LocalRole)
	{
	case ROLE_Authority:
		Role = TEXT("Authority");
		break;
	case ROLE_AutonomousProxy:
		Role = TEXT("Autonomous Proxy");
		break;
	case ROLE_SimulatedProxy:
		Role = TEXT("Simulated Proxy");
		break;
	case ROLE_None:
		Role = TEXT("None");
		break;
	default:
		Role = TEXT("None");
	}
	FString LocalRoleString = FString::Printf(TEXT("Local Role : %s") , *Role);
	SetDisplayText(LocalRoleString);
}

void UOverheadWidget::NativeDestruct()
{
	RemoveFromParent();
	Super::NativeDestruct();
}
