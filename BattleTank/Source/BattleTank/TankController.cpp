// Fill out your copyright notice in the Description page of Project Settings.

#include "TankController.h"
#include "Tank.h"


//tick 
//super class
//method that calls and aim towards crosshair

void ATankController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime); 
AimTowardsCrossHair();

//UE_LOG(LogTemp, Warning, TEXT("Player controlling ticking"));
	
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
	
	
	FVector HitLocation;//out parameter
	if (GetSightRayHitLocation(HitLocation)) {//will ray trace 
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());
	}

//get world through a line trace print out what it hits 
//tell tank to taim at this point

}
bool ATankController::GetSightRayHitLocation(FVector& HitLocation)const{
	
	
		//set crosshair position 
	int32 ViewportSizeX, ViewportSizeY;
	
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX*CrosshairXLocation, ViewportSizeY*CrosshairYLocation);
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection)) {
		GetLookVectorHitLocation(LookDirection, HitLocation);
	}
	//de project screen position
	//line trace along direction to see what we hit

		return true;
}
bool ATankController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection)const {
	FVector CameraWorldLocation;//displosable to be passed in params
	
	(DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection));
	
	
	
		
		return true;
}
bool ATankController::GetLookVectorHitLocation(
	 FVector LookDirection, FVector& HitLocation) const{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection* LineTraceRange);

	if (GetWorld()->LineTraceSingleByChannel(
		HitResult,
	StartLocation,
	EndLocation,
	ECollisionChannel::ECC_Visibility
	)) {
		HitLocation = HitResult.Location;
			return true;
	}
	
	return false;
}