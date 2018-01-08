// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATank*GetControlledTank()const;
	
	void BeginPlay() override;
private:

virtual void Tick(float DeltaTime)override;
 void AimTowardsCrossHair();
 bool GetSightRayHitLocation(FVector& HitLocation)const;

 UPROPERTY(EditAnywhere)
	 float CrosshairXLocation = .5, CrosshairYLocation = .3333;
 UPROPERTY(EditAnywhere)
  float LineTraceRange= 1000000;

bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection)const;
bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation)const;
};
