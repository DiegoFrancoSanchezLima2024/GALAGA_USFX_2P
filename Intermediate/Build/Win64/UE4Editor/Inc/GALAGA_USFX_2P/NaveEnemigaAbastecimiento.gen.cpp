// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GALAGA_USFX_2P/NaveEnemigaAbastecimiento.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNaveEnemigaAbastecimiento() {}
// Cross Module References
	GALAGA_USFX_2P_API UClass* Z_Construct_UClass_ANaveEnemigaAbastecimiento_NoRegister();
	GALAGA_USFX_2P_API UClass* Z_Construct_UClass_ANaveEnemigaAbastecimiento();
	GALAGA_USFX_2P_API UClass* Z_Construct_UClass_ANaveEnemiga();
	UPackage* Z_Construct_UPackage__Script_GALAGA_USFX_2P();
// End Cross Module References
	void ANaveEnemigaAbastecimiento::StaticRegisterNativesANaveEnemigaAbastecimiento()
	{
	}
	UClass* Z_Construct_UClass_ANaveEnemigaAbastecimiento_NoRegister()
	{
		return ANaveEnemigaAbastecimiento::StaticClass();
	}
	struct Z_Construct_UClass_ANaveEnemigaAbastecimiento_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ANaveEnemigaAbastecimiento_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ANaveEnemiga,
		(UObject* (*)())Z_Construct_UPackage__Script_GALAGA_USFX_2P,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANaveEnemigaAbastecimiento_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "NaveEnemigaAbastecimiento.h" },
		{ "ModuleRelativePath", "NaveEnemigaAbastecimiento.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ANaveEnemigaAbastecimiento_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ANaveEnemigaAbastecimiento>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ANaveEnemigaAbastecimiento_Statics::ClassParams = {
		&ANaveEnemigaAbastecimiento::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ANaveEnemigaAbastecimiento_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ANaveEnemigaAbastecimiento_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ANaveEnemigaAbastecimiento()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ANaveEnemigaAbastecimiento_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ANaveEnemigaAbastecimiento, 3049322100);
	template<> GALAGA_USFX_2P_API UClass* StaticClass<ANaveEnemigaAbastecimiento>()
	{
		return ANaveEnemigaAbastecimiento::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ANaveEnemigaAbastecimiento(Z_Construct_UClass_ANaveEnemigaAbastecimiento, &ANaveEnemigaAbastecimiento::StaticClass, TEXT("/Script/GALAGA_USFX_2P"), TEXT("ANaveEnemigaAbastecimiento"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ANaveEnemigaAbastecimiento);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
