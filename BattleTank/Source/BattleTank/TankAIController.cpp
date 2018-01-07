// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"

void ATankAIController::BeginPlay() {
	Super::BeginPlay();
	auto PlayerTank = GetPlayerTank();
	//This on play checks if there isnt a player tank being possessed
	//if not out put where if the enemy tank found the player out enemy has found us
	if (!PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("WHERE IS THE ENEMY!!!"));

	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("ENEMY AI FOUND US: %s"), *(PlayerTank->GetName()));
	}
}
ATank*ATankAIController::GetControlledAITank()const {

	return Cast<ATank>(GetPawn());
}//casting the tank to the pawn 

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) {
		return nullptr;
	}return Cast<ATank>(PlayerPawn);
}

