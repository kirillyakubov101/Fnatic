

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Nest.generated.h"

class AWolf;

UCLASS()
class FNATIC_API ANest : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void SpawnWolf();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	UPROPERTY(BlueprintReadWrite, Category = "Spawn", meta = (AllowPrivateAccess = "true"))
		TSubclassOf<AWolf> WolfAsset;


	UPROPERTY(EditInstanceOnly,BlueprintReadWrite, Category = "Spawn", meta = (AllowPrivateAccess = "true"))
		AActor* TargetActor;


	AWolf* m_Wolf;
	FVector TargetPosition;
	
};
