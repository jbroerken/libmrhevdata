/**
 *  libmrhevdata
 *  Copyright (C) 2021 - 2022 Jens Brörken
 *
 *  This software is provided 'as-is', without any express or implied
 *  warranty.  In no event will the authors be held liable for any damages
 *  arising from the use of this software.
 *
 *  Permission is granted to anyone to use this software for any purpose,
 *  including commercial applications, and to alter it and redistribute it
 *  freely, subject to the following restrictions:
 *
 *  1. The origin of this software must not be misrepresented; you must not
 *     claim that you wrote the original software. If you use this software
 *     in a product, an acknowledgment in the product documentation would be
 *     appreciated but is not required.
 *
 *  2. Altered source versions must be plainly marked as such, and must not be
 *     misrepresented as being the original software.
 *
 *  3. This notice may not be removed or altered from any source distribution.
 */

#ifndef MRH_EvBase_h
#define MRH_EvBase_h

// C

// External
#include <MRH_Event.h>

// Project


#ifdef __cplusplus
extern "C"
{
#endif
    
    //*************************************************************************************
    // Types
    //*************************************************************************************

    // Service Available
    struct MRH_EvD_Base_ServiceAvail_S_t
    {
        MRH_Uint8 u8_Available;
        MRH_Uint32 u32_SupplierID;
        MRH_Uint32 u32_BinaryID;
        MRH_Uint32 u32_Version;
    };
    
    // Custom Command
    struct MRH_EvD_Base_CustomCommand_t
    {
        MRH_Uint8 p_Buffer[MRH_EVENT_DATA_SIZE_MAX];
        MRH_Uint32 u32_DataSize;
    };
    
    // Result Event
    struct MRH_EvD_Base_Result_t
    {
        MRH_Uint8 u8_Result;
    };
    
    // String Event
    struct MRH_EvD_Base_String_t
    {
        char p_String[MRH_EVENT_DATA_SIZE_MAX];
    };

#ifdef __cplusplus
}
#endif


#endif /* MRH_EvBase_h */
