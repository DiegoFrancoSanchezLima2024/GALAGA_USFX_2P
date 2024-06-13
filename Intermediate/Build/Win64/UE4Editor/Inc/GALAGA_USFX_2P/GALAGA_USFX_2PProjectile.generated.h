// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FVector;
struct FHitResult;
#ifdef GALAGA_USFX_2P_GALAGA_USFX_2PProjectile_generated_h
#error "GALAGA_USFX_2PProjectile.generated.h already included, missing '#pragma once' in GALAGA_USFX_2PProjectile.h"
#endif
#define GALAGA_USFX_2P_GALAGA_USFX_2PProjectile_generated_h

#define GALAGA_USFX_2P_Source_GALAGA_USFX_2P_GALAGA_USFX_2PProjectile_h_15_SPARSE_DATA
#define GALAGA_USFX_2P_Source_GALAGA_USFX_2P_GALAGA_USFX_2PProjectile_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnHit);


#define GALAGA_USFX_2P_Source_GALAGA_USFX_2P_GALAGA_USFX_2PProjectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnHit);


#define GALAGA_USFX_2P_Source_GALAGA_USFX_2P_GALAGA_USFX_2PProjectile_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAGALAGA_USFX_2PProjectile(); \
	friend struct Z_Construct_UClass_AGALAGA_USFX_2PProjectile_Statics; \
public: \
	DECLARE_CLASS(AGALAGA_USFX_2PProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/GALAGA_USFX_2P"), NO_API) \
	DECLARE_SERIALIZER(AGALAGA_USFX_2PProjectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define GALAGA_USFX_2P_Source_GALAGA_USFX_2P_GALAGA_USFX_2PProjectile_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAGALAGA_USFX_2PProjectile(); \
	friend struct Z_Construct_UClass_AGALAGA_USFX_2PProjectile_Statics; \
public: \
	DECLARE_CLASS(AGALAGA_USFX_2PProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/GALAGA_USFX_2P"), NO_API) \
	DECLARE_SERIALIZER(AGALAGA_USFX_2PProjectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define GALAGA_USFX_2P_Source_GALAGA_USFX_2P_GALAGA_USFX_2PProjectile_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AGALAGA_USFX_2PProjectile(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AGALAGA_USFX_2PProjectile) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGALAGA_USFX_2PProjectile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGALAGA_USFX_2PProjectile); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGALAGA_USFX_2PProjectile(AGALAGA_USFX_2PProjectile&&); \
	NO_API AGALAGA_USFX_2PProjectile(const AGALAGA_USFX_2PProjectile&); \
public:


#define GALAGA_USFX_2P_Source_GALAGA_USFX_2P_GALAGA_USFX_2PProjectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGALAGA_USFX_2PProjectile(AGALAGA_USFX_2PProjectile&&); \
	NO_API AGALAGA_USFX_2PProjectile(const AGALAGA_USFX_2PProjectile&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGALAGA_USFX_2PProjectile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGALAGA_USFX_2PProjectile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AGALAGA_USFX_2PProjectile)


#define GALAGA_USFX_2P_Source_GALAGA_USFX_2P_GALAGA_USFX_2PProjectile_h_15_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__ProjectileMesh() { return STRUCT_OFFSET(AGALAGA_USFX_2PProjectile, ProjectileMesh); } \
	FORCEINLINE static uint32 __PPO__ProjectileMovement() { return STRUCT_OFFSET(AGALAGA_USFX_2PProjectile, ProjectileMovement); }


#define GALAGA_USFX_2P_Source_GALAGA_USFX_2P_GALAGA_USFX_2PProjectile_h_12_PROLOG
#define GALAGA_USFX_2P_Source_GALAGA_USFX_2P_GALAGA_USFX_2PProjectile_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GALAGA_USFX_2P_Source_GALAGA_USFX_2P_GALAGA_USFX_2PProjectile_h_15_PRIVATE_PROPERTY_OFFSET \
	GALAGA_USFX_2P_Source_GALAGA_USFX_2P_GALAGA_USFX_2PProjectile_h_15_SPARSE_DATA \
	GALAGA_USFX_2P_Source_GALAGA_USFX_2P_GALAGA_USFX_2PProjectile_h_15_RPC_WRAPPERS \
	GALAGA_USFX_2P_Source_GALAGA_USFX_2P_GALAGA_USFX_2PProjectile_h_15_INCLASS \
	GALAGA_USFX_2P_Source_GALAGA_USFX_2P_GALAGA_USFX_2PProjectile_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define GALAGA_USFX_2P_Source_GALAGA_USFX_2P_GALAGA_USFX_2PProjectile_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GALAGA_USFX_2P_Source_GALAGA_USFX_2P_GALAGA_USFX_2PProjectile_h_15_PRIVATE_PROPERTY_OFFSET \
	GALAGA_USFX_2P_Source_GALAGA_USFX_2P_GALAGA_USFX_2PProjectile_h_15_SPARSE_DATA \
	GALAGA_USFX_2P_Source_GALAGA_USFX_2P_GALAGA_USFX_2PProjectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	GALAGA_USFX_2P_Source_GALAGA_USFX_2P_GALAGA_USFX_2PProjectile_h_15_INCLASS_NO_PURE_DECLS \
	GALAGA_USFX_2P_Source_GALAGA_USFX_2P_GALAGA_USFX_2PProjectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GALAGA_USFX_2P_API UClass* StaticClass<class AGALAGA_USFX_2PProjectile>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID GALAGA_USFX_2P_Source_GALAGA_USFX_2P_GALAGA_USFX_2PProjectile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
