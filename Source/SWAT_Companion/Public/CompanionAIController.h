// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/AIModule/Classes/AIController.h"
#include "CompanionAIController.generated.h"

class AActor;
class UStateTreeComponent;

UCLASS()
class SWAT_COMPANION_API ACompanionAIController : public AAIController
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACompanionAIController();

	UFUNCTION(BlueprintCallable, Category = "Companion|Commands")
	void CommandFollowActor(AActor* NewFollowTarget);

	UFUNCTION(BlueprintCallable, Category = "Companion|Commands")
	void StopFollowing();

protected:
	// Called when the game starts or when spawned
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category = "AI")
	TObjectPtr<UStateTreeComponent> StateTreeComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Companion|Follow")
	float FollowAcceptanceRadius = 200.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Companion|Follow")
	float FollowRefreshInterval = 0.35f;

	UPROPERTY(BlueprintReadOnly, Category = "Companion|Follow")
	TObjectPtr<AActor> FollowTarget;

	FTimerHandle FollowRefreshTimerHandle;
	
	virtual void OnPossess(APawn* InPawn) override;
	virtual void OnUnPossess() override;

private:
	void RefreshFollowMove();
	
};
