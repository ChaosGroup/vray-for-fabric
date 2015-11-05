#ifndef V4F_EXCEPTIONS_H_
#define V4F_EXCEPTIONS_H_

#include <FabricEDK.h>

#define V4F_EXCEPTIONS

#ifdef V4F_EXCEPTIONS
    #ifdef __GNUC__ 
        #define _func_ __PRETTY_FUNCTION__
    #elif  _MSC_VER
        #define _func_ __FUNCSIG__
    #endif

    #define V4F_TRY                                 \
        try {                                   

    #define V4F_CATCH(...)                          \
        } catch (...) {                             \
            Fabric::EDK::throwException(_func_);    \
            return __VA_ARGS__;                     \
        }                                       
#else
    #define V4F_TRY
    #define V4F_CATCH
#endif

#endif
