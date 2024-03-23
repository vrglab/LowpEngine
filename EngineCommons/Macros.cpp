#include "pch.h"
#include "Macros.h"

template<typename ...Args>
inline void AppendToEM(std::string& err_msg, Args ...args)
{
    (err_msg.append(args), ...);
}