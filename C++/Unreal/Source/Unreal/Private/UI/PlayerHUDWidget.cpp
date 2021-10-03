// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/PlayerHUDWidget.h"

#define LOCTEXT_NAMESPACE "PlayerHUD"

void SPlayerHUDWidget::Construct(const FArguments& InArgs)
{
    const FMargin ContentPadding = FMargin(0, 0);

    const FText LifeStatusLabelText = LOCTEXT("LifeStatusLabel", "Life");

    ChildSlot
        [
            SNew(SOverlay)
            + SOverlay::Slot()
            .HAlign(HAlign_Fill)
            .VAlign(VAlign_Fill)
            .Padding(ContentPadding)
            [
                SNew(SVerticalBox)
                + SVerticalBox::Slot()
                .VAlign(VAlign_Bottom)
                [
                    SNew(STextBlock)
                    .Text(LifeStatusLabelText)
                ]
            ]
        ];
}

#undef LOCTEXT_NAMESPACE