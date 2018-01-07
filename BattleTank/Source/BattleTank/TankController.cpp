// Fill out your copyright notice in the Description page of Project Settings.

#include "TankController.h"
#include "Tank.h"


//tick 
//super class
//method that calls and aim towards crosshair

void ATankController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime); 
AimTowardsCrossHair();
UE_LOG(LogTemp, Warning, TEXT("Player controlling ticking"));
	
}
void ATankController::BeginPlay() {
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();

	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("WHERE IS IT"));
		
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("PLAYER IS PLAYING: %s"),*(ControlledTank->GetName()));
	}
}

ATank*ATankController::GetControlledTank()const {

	return Cast<ATank>(GetPawn());
}
void ATankController::AimTowardsCrossHair(){
	

//get world through a line trace print out what it hits 
//tell tank to taim at this point

}

