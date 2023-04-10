#include "Wolf.h"
#include "MyAIController.h"


AWolf::AWolf()	
{
	PrimaryActorTick.bCanEverTick = false;
}


void AWolf::BeginPlay()
{
	Super::BeginPlay();
	
	//cache startPos
	StartPosition = GetActorLocation();
	auto tempController = GetController();

	if (tempController)
	{
		Controller = Cast<AMyAIController>(tempController);
	}
}

void AWolf::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWolf::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AWolf::SetTargetPosition(FVector pos)
{
	this->EndPosition = pos;
	CurrentTargetPosition = pos;
}

void AWolf::MyMove()
{
	if (!Controller || ShouldStop) { return; }
	Controller->MoveToLocation(CurrentTargetPosition);
}

void AWolf::StopMove()
{
	if (!Controller) { return; }
	Controller->StopMovement();
}


void AWolf::WolfDelayedMovement()
{
	MyMove();
	GetWorldTimerManager().SetTimer(TimerHandleFirst, this, &AWolf::MyMove, 0.5f, true, 1.5f);
	GetWorldTimerManager().SetTimer(TimerHandleSecond, this, &AWolf::StopMove, 1.502f, true, 1.f);
}
 
void AWolf::WolfReverseMovement()
{
	MyMove();
	GetWorldTimerManager().SetTimer(TimerHandleFirst, this, &AWolf::MoveForward, 0.5f, true, 1.5f); //forward movement
	GetWorldTimerManager().SetTimer(TimerHandleSecond, this, &AWolf::MoveBackward, 1.502f, true, 1.f); //backward movement |a little extra time due to the float precision
}



void AWolf::MoveForward()
{
	CurrentTargetPosition = EndPosition;
	MyMove();
}

void AWolf::MoveBackward()
{
	CurrentTargetPosition = StartPosition;
	MyMove();
}

void AWolf::ClearTimerAndStop()
{
	ShouldStop = true;
	StopMove();
	GetWorldTimerManager().ClearTimer(TimerHandleFirst);
	GetWorldTimerManager().ClearTimer(TimerHandleSecond);
	
}



