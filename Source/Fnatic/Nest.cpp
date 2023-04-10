

#include "Nest.h"
#include "Wolf.h"

ANest::ANest() : 
	m_Wolf(nullptr), TargetActor(nullptr)
{
	PrimaryActorTick.bCanEverTick = false;
}


void ANest::BeginPlay()
{
	Super::BeginPlay();

	if (TargetActor)
	{
		TargetPosition = TargetActor->GetActorLocation();
	}
}

void ANest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ANest::SpawnWolf()
{
	if (GetWorld() && WolfAsset)
	{
		//Clear previous Wolf
		if (m_Wolf != nullptr) { m_Wolf->Destroy(); } 

		this->m_Wolf = GetWorld()->SpawnActor<AWolf>(WolfAsset, GetActorLocation(), GetActorRotation());
		this->m_Wolf->SetTargetPosition(TargetPosition);
		this->m_Wolf->Move();
	}
}

