/* ======================================================================================== */
/* LowpEngine - Scripting Engine C/C++ header file.											*/
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once
#include <EngineCommons/EngineCommons.h>


#include <mono/metadata/debug-helpers.h>
#include <mono/jit/jit.h>
#include <mono/metadata/assembly.h>
#include <mono/metadata/mono-config.h>


class ScriptingUtils
{
public:
	static MonoClass* GetClass(std::string class_id, MonoImage* image);
	static MonoMethod* GetMethod(std::string, MonoClass*);
	static void InvokeMethod(MonoMethod*, MonoObject*);
	static MonoAssembly* LoadAssembly(std::string assemblyPath, MonoDomain* domain, std::vector<MonoAssembly*> loaded_assemblies);
	static void LoadAllAssembliesFromDirectory(std::string directoryPath, MonoDomain* domain, std::vector<MonoAssembly*> loaded_assemblies);
	static bool IsSubclassOf(MonoClass* test_class, MonoClass* parent);
};

#define mono_find_on_rows(image, base_class, x, z) \
const MonoTableInfo* typeTable = mono_image_get_table_info(image, MONO_TABLE_TYPEDEF); \
int rows = mono_table_info_get_rows(typeTable); \
for (int i = 1; i <= rows; i++) { \
    uint32_t cols[MONO_TYPEDEF_SIZE]; \
    mono_metadata_decode_row(typeTable, i - 1, cols, MONO_TYPEDEF_SIZE); \
    const char* name = mono_metadata_string_heap(image, cols[MONO_TYPEDEF_NAME]); \
    const char* nameSpace = mono_metadata_string_heap(image, cols[MONO_TYPEDEF_NAMESPACE]); \
    MonoClass* klasss = mono_class_from_name(image, nameSpace, name); \
 \
    if (ScriptingUtils::IsSubclassOf(klasss, base_class) z) { \
        x \
    } \
}