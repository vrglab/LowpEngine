/* ======================================================================================== */
/* LowpEngine - Engine Commons C/C++ header file.											*/
/*                                                                                          */
/*                 Copyright (c) 2023-Present Arad Bozorgmehr (Vrglab)                      */
/*                                                                                          */
/* The assert implementation is based on the assert implementation from Hazel by Cherno     */
/* Authors: Arad Bozorgmehr(Vrglab)                                                         */
/* ======================================================================================== */
#pragma once

#include "Macros.h"
#include <filesystem>

#ifdef LP_ENABLE_ASSERTS

// Alteratively we could use the same "default" message for both "WITH_MSG" and "NO_MSG" and
// provide support for custom formatting by concatenating the formatting string instead of having the format inside the default message
#define LP_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { LP##type##ERROR(msg, __VA_ARGS__); LP_BREAK(); } }
#define LP_INTERNAL_ASSERT_WITH_MSG(type, check, ...) LP_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
#define LP_INTERNAL_ASSERT_NO_MSG(type, check) LP_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", LP_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

#define LP_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
#define LP_INTERNAL_ASSERT_GET_MACRO(...) LP_EXPAND_MACRO( LP_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, LP_INTERNAL_ASSERT_WITH_MSG, LP_INTERNAL_ASSERT_NO_MSG) )

// Currently accepts at least the condition and one additional parameter (the message) being optional
#define LP_ASSERT(...) LP_EXPAND_MACRO( LP_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
#define LP_CORE_ASSERT(...) LP_EXPAND_MACRO( LP_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )
#else
#define LP_ASSERT(...)
#define LP_CORE_ASSERT(...)
#endif