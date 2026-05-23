// Fill out your copyright notice in the Description page of Project Settings.


#include "CompanionAIController.h"
#include "Components/StateTreeComponent.h" 
#include "TimerManager.h"

// Sets default values
ACompanionAIController::ACompanionAIController()
{
	StateTreeComponent = CreateDefaultSubobject<UStateTreeComponent>("StateTreeComponent");
}

void ACompanionAIController::CommandFollowActor(AActor* NewFollowTarget)
{
	if (!IsValid(NewFollowTarget))
	{
		StopFollowing();
		return;
	}

	FollowTarget = NewFollowTarget;
	RefreshFollowMove();

	GetWorldTimerManager().SetTimer(
		FollowRefreshTimerHandle,
		this,
		&ACompanionAIController::RefreshFollowMove,
		FollowRefreshInterval,
		true);
}

void ACompanionAIController::StopFollowing()
{
	GetWorldTimerManager().ClearTimer(FollowRefreshTimerHandle);
	FollowTarget = nullptr;
	StopMovement();
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
	StopFollowing();
	
	if (StateTreeComponent)
	{
		StateTreeComponent->StopLogic("Unpossessed");
	}
	
	Super::OnUnPossess();
}

void ACompanionAIController::RefreshFollowMove()
{
	if (!IsValid(FollowTarget))
	{
		StopFollowing();
		return;
	}

	MoveToActor(FollowTarget, FollowAcceptanceRadius, true, true, true);
}

