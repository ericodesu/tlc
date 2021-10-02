// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHUDWidget.h"

#define LOCTEXT_NAMESPACE "PlayerHUD"

void SPlayerHUDWidget::Construct(const FArguments& InArgs)
{
    const FMargin ContentPadding = FMargin(100.0f, 200.0f);

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
                [
                    SNew(STextBlock)
                    .Text(LifeStatusLabelText)
                ]
            ]
        ];
}

#undef LOCTEXT_NAMESPACE