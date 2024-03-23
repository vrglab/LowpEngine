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

/**
 * @brief A class containing helpful functions to be used through out the Scripting engine
 */
class ScriptingUtils
{
public:
    /**
     * @brief Finds a class type based on its name
     * @param class_name The class to find
     * @param image the mono image containing the class definitions
     * @return the found Class type
     */
	static MonoClass* GetClass(std::string class_name, MonoImage* image);

    /**
     * @brief Finds a method inside a class using it's name
     * @param name The method name
     * @param klass The class type containing the method
     * @return The found method
     */
	static MonoMethod* GetMethod(std::string name, MonoClass* klass);

    /**
     * @brief Invokes a C# method within a specific object 
     * @param method The method to invoke
     * @param instance The C# instance to invoke the method for
     */
	static void InvokeMethod(MonoMethod* method, MonoObject* instance);

    /**
     * @brief Loads a C# Assembly from the os disk
     * @param assemblyPath The path to the assembly
     * @param domain The current mono domain
     * @param loaded_assemblies a list containing the currently loaded assemblies
     * @return The loaded assembly
     */
	static MonoAssembly* LoadAssembly(std::string assemblyPath, MonoDomain* domain, std::vector<MonoAssembly*> loaded_assemblies);

    /**
     * @brief Loads all of the C# assemblies contained in a directory 
     * @param directoryPath The directory to search inside for the C# assemblies
     * @param domain The current mono domain
     * @param loaded_assemblies A list containing the currently loaded assemblies
     */
	static void LoadAllAssembliesFromDirectory(std::string directoryPath, MonoDomain* domain, std::vector<MonoAssembly*> loaded_assemblies);

    /**
     * @brief Checks if one given C# class is a child of another
     * @param test_class The class to check if is a child
     * @param parent The parent class
     * @return True if the test_class is the child class of the parent, false otherwise
     */
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