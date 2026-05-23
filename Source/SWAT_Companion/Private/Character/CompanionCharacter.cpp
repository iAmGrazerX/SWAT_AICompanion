// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/CompanionCharacter.h"
#include "AbilitySystemComponent.h"
#include "CompanionAttributeSet.h"

// Sets default values
ACompanionCharacter::ACompanionCharacter()
{
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComponent");
	
	AttributeSet = CreateDefaultSubobject<UCompanionAttributeSet>("AttributeSet");
}

UAbilitySystemComponent* ACompanionCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

// Called when the game starts or when spawned
void ACompanionCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACompanionCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACompanionCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	
	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->InitAbilityActorInfo(this,this);
		GrantDefaultAbilities();
	}
}

void ACompanionCharacter::GrantDefaultAbilities()
{
	if (!AbilitySystemComponent || bDefaultAbilitiesGranted)
	{
		return;
	}

	for (TSubclassOf<UGameplayAbility> AbilityClass : DefaultAbilities)
	{
		if (AbilityClass)
		{
			AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(AbilityClass, 1));
		}
	}

	bDefaultAbilitiesGranted = true;
}



