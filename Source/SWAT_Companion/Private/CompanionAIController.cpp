// Fill out your copyright notice in the Description page of Project Settings.


#include "CompanionAIController.h"
#include "Components/StateTreeComponent.h" 
#include "TimerManager.h"

// Sets default values
ACompanionAIController::ACompanionAIController()
{
	StateTreeComponent = CreateDefaultSubobject<UStateTreeComponent>("StateTreeComponent");
}

void ACompanionAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	
	if (StateTreeComponent)
	{
		StateTreeComponent->StartLogic();
	}
}

void ACompanionAIController::OnUnPossess()
{
	if (StateTreeComponent)
	{
		StateTreeComponent->StopLogic("Unpossessed");
	}
	
	Super::OnUnPossess();
}


