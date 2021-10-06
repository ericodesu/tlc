// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Unreal/Classes/PlayerStatus.h"
#include "Unreal/Classes/InternalFont.h"

#include "SlateBasics.h"
#include "SlateExtras.h"

/**
 * 
 */
class SPlayerHUDWidget : public SCompoundWidget
{
	SLATE_BEGIN_ARGS(SPlayerHUDWidget) {}

	SLATE_ARGUMENT(TWeakObjectPtr<class APlayerHUD>, WidgetOwnerArg)

	SLATE_END_ARGS()

public:
	void Construct(const FArguments& InArgs);

private:
	TWeakObjectPtr<class APlayerHUD> WidgetOwner;
	TSharedPtr<SVerticalBox> WrapperBox;
	TSharedPtr<SHorizontalBox> FooterBox;

	void AttachEssentialStatus();
	void AttachHealthStatusBar();
	void AttachManaStatusBar();
};
