#pragma once

#include "GameFramework/PlayerController.h"

#include "AMPlayerController.generated.h"

UCLASS()
class AMPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	virtual void BeginPlay() override;
};