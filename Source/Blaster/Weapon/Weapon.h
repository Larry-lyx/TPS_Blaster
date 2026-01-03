// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

class UWidgetComponent;
class USphereComponent;

UENUM(BlueprintType)
enum class EWeaponState : uint8
{
	EWS_Initial UMETA(DisplayName = "Initial"),
	EWS_Equipped UMETA(DisplayName = "Equipped"),
	EWS_Dropped UMETA(DisplayName = "Dropped"),

	EWS_MAX UMETA(DisplayName = "Max")
};

UCLASS()
class BLASTER_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	AWeapon();

	void ShowPickUpWidget(bool bShowWidget) const;

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	UFUNCTION()
	virtual void OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
private:
	UPROPERTY(VisibleAnywhere , Category = "Weapon Properties")
	USkeletalMeshComponent* WeaponMesh;

	UPROPERTY(VisibleAnywhere , Category = "Weapon Properties")
	USphereComponent* AreaSphere;

	UPROPERTY(VisibleAnywhere , Category = "Weapon Properties")
	EWeaponState WeaponState;

	UPROPERTY(EditAnywhere , Category = "Weapon Properties")
	UWidgetComponent* PickUpWidget;

public:
	FORCEINLINE void SetWeaponState(EWeaponState State){WeaponState = State ;}
	FORCEINLINE EWeaponState GetWeaponState() const {return WeaponState;}
};
