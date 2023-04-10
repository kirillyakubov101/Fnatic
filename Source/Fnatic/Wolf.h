// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Wolf.generated.h"

class AMyAIController;

UCLASS()
class FNATIC_API AWolf : public ACharacter
{
	GENERATED_BODY()

public:
	AWolf();

protected:
	virtual void BeginPlay() override;

private:

	AMyAIController* Controller;
	FVector StartPosition;
	FVector EndPosition;

	UPROPERTY(BlueprintReadOnly, Category = "Target", meta = (AllowPrivateAccess = "true"))
		FVector CurrentTargetPosition;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	void ClearTimerAndStop();

	void SetTargetPosition(FVector);

	UFUNCTION(BlueprintImplementableEvent, Category = "AI Movement")
	void Move();

protected:

	UFUNCTION(BlueprintCallable)
	void MyMove();				//simple movement

	UFUNCTION(BlueprintCallable)
	void StopMove();

	UFUNCTION(BlueprintCallable)
	void WolfDelayedMovement(); //2nd wolf with delay movement

	UFUNCTION(BlueprintCallable)
	void WolfReverseMovement(); //3nd wolf with delay movement

private:

	void MoveForward();
	void MoveBackward();
	bool ShouldStop = false;

private:
	FTimerHandle TimerHandleFirst;
	FTimerHandle TimerHandleSecond;
};
