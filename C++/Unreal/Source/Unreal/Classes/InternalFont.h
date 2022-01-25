#pragma once

#include "CoreMinimal.h"
#include "UObject/UObjectGlobals.h"
#include "Components/Widget.h"
#include "InternalFont.generated.h"

UENUM()
enum EFontLocales
{
    EN_US UMETA(DisplayName = "EN-US"),
    JP UMETA(DisplayName = "JP")
};

UENUM()
enum EFontExtensions
{
    TTF UMETA(DisplayName = "ttf"),
    OTF UMETA(DisplayName = "otf")
};

USTRUCT()
struct FInternalFont
{
    GENERATED_BODY()

public:
    FORCEINLINE FInternalFont();
    FORCEINLINE FInternalFont(
        FString InName,
        EFontLocales InLocale,
        EFontExtensions InExtension,
        uint32 InSize
    );
    void SetFontLocale(EFontLocales InLocale);
    void SetFontExtension(EFontExtensions InExtension);
    FSlateFontInfo GetFontInfo();

    FString Name;
    uint32 Size;

protected:
    FString Locale;
    FString Extension;

private:
    FString ConvertFontLocale(EFontLocales InLocale);
    FString ConvertFontExtension(EFontExtensions InExtension);
};

FORCEINLINE FInternalFont::FInternalFont()
{}

FORCEINLINE FInternalFont::FInternalFont(
    FString InName,
    EFontLocales InLocale,
    EFontExtensions InExtension,
    uint32 InSize
)
    : Name(InName),
      Size(InSize),
      Locale(ConvertFontLocale(InLocale)),
      Extension(ConvertFontExtension(InExtension))
{}

inline FString FInternalFont::ConvertFontLocale(EFontLocales InLocale)
{
    const UEnum* Enum = FindObject<UEnum>(ANY_PACKAGE, TEXT("EFontLocales"), true);

    return Enum->GetNameStringByValue(static_cast<uint32>(InLocale)).ToLower();
}

inline FString FInternalFont::ConvertFontExtension(EFontExtensions InExtension)
{
    static const UEnum* Enum = FindObject<UEnum>(ANY_PACKAGE, TEXT("EFontExtensions"), true);

    return Enum->GetNameStringByValue(static_cast<uint32>(InExtension)).ToLower();
}

inline void FInternalFont::SetFontLocale(EFontLocales InLocale)
{
    this->Locale = ConvertFontLocale(InLocale);
}

inline void FInternalFont::SetFontExtension(EFontExtensions InExtension)
{
    this->Extension = ConvertFontExtension(InExtension);
}

inline FSlateFontInfo FInternalFont::GetFontInfo()
{
    FString FullFileName = this->Name + "." + this->Extension;
    FString ResourceDirPath = FPaths::ProjectContentDir() / "UI" / "HUD" / "Faces" / "Raw" / this->Locale;
    FString FilePath = ResourceDirPath / FullFileName;

    if (FPaths::DirectoryExists(ResourceDirPath) == false || FPaths::FileExists(FilePath) == false)
    {
        FullFileName = "Roboto-Bold.ttf";
        ResourceDirPath = FPaths::EngineContentDir() / "Slate" / "Fonts";
        FilePath = ResourceDirPath / FullFileName;
    }

    return FSlateFontInfo(
        FilePath,
        this->Size
    );
}