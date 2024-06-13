// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GALAGA_USFX_2P/FabricaDeNaves_1_F.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFabricaDeNaves_1_F() {}
// Cross Module References
	GALAGA_USFX_2P_API UClass* Z_Construct_UClass_AFabricaDeNaves_1_F_NoRegister();
	GALAGA_USFX_2P_API UClass* Z_Construct_UClass_AFabricaDeNaves_1_F();
	GALAGA_USFX_2P_API UClass* Z_Construct_UClass_AFabricaDeNaves_F();
	UPackage* Z_Construct_UPackage__Script_GALAGA_USFX_2P();
// End Cross Module References
	void AFabricaDeNaves_1_F::StaticRegisterNativesAFabricaDeNaves_1_F()
	{
	}
	UClass* Z_Construct_UClass_AFabricaDeNaves_1_F_NoRegister()
	{
		return AFabricaDeNaves_1_F::StaticClass();
	}
	struct Z_Construct_UClass_AFabricaDeNaves_1_F_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AFabricaDeNaves_1_F_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AFabricaDeNaves_F,
		(UObject* (*)())Z_Construct_UPackage__Script_GALAGA_USFX_2P,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFabricaDeNaves_1_F_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n *\n */" },
		{ "IncludePath", "FabricaDeNaves_1_F.h" },
		{ "ModuleRelativePath", "FabricaDeNaves_1_F.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AFabricaDeNaves_1_F_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFabricaDeNaves_1_F>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AFabricaDeNaves_1_F_Statics::ClassParams = {
		&AFabricaDeNaves_1_F::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AFabricaDeNaves_1_F_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AFabricaDeNaves_1_F_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AFabricaDeNaves_1_F()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AFabricaDeNaves_1_F_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AFabricaDeNaves_1_F, 2239057785);
	template<> GALAGA_USFX_2P_API UClass* StaticClass<AFabricaDeNaves_1_F>()
	{
		return AFabricaDeNaves_1_F::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AFabricaDeNaves_1_F(Z_Construct_UClass_AFabricaDeNaves_1_F, &AFabricaDeNaves_1_F::StaticClass, TEXT("/Script/GALAGA_USFX_2P"), TEXT("AFabricaDeNaves_1_F"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFabricaDeNaves_1_F);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
