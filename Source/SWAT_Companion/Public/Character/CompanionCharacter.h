// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "CompanionCharacter.generated.h"

class UAbilitySystemComponent;
class UCompanionAttributeSet;
class UGameplayAbility;


UCLASS()
class SWAT_COMPANION_API ACompanionCharacter : public ACharacter , public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ACompanionCharacter();
	
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GAS")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	
	UPROPERTY()
	TObjectPtr<UCompanionAttributeSet> AttributeSet;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GAS")
	TArray<TSubclassOf<UGameplayAbility>> DefaultAbilities;

	bool bDefaultAbilitiesGranted = false;
	
	virtual void BeginPlay() override;
	void GrantDefaultAbilities();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void PossessedBy(AController* NewController) override;
};
