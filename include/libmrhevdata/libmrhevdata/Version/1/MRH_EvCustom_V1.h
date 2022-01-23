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

#ifndef MRH_EvCustom_V1_h
#define MRH_EvCustom_V1_h

// C

// External

// Project
#include "../MRH_EvBase.h"


#ifdef __cplusplus
extern "C"
{
#endif
    
    //*************************************************************************************
    // Types
    //*************************************************************************************

    typedef struct MRH_EvD_Base_CustomCommand_t MRH_EvD_C_CustomCommand_U;
    
    typedef struct MRH_EvD_Base_ServiceAvail_S_t MRH_EvD_C_ServiceAvail_S;
    typedef struct MRH_EvD_Base_CustomCommand_t MRH_EvD_C_CustomCommand_S;
    
    //*************************************************************************************
    // Convert
    //*************************************************************************************
    
    /**
     *  Write a custom version 1 event with given custom event data.
     *
     *  \param p_Event The event to write to. The data buffer will be overwritten.
     *  \param u32_Type The type of custom event to write.
     *  \param p_Data The custom event data.
     *
     *  \return 0 on success, -1 on failure.
     */

    extern int MRH_EVD_C_ToEvent_V1(MRH_Event* p_Event, MRH_Uint32 u32_Type, const void* p_Data);

    /**
     *  Read custom event data from a custom version 1 event.
     *
     *  \param p_Data The custom event data to write.
     *  \param u32_Type The type of custom event to read.
     *  \param p_Event The event to read from.
     *
     *  \return 0 on success, -1 on failure.
     */

    extern int MRH_EVD_C_ToData_V1(void* p_Data, MRH_Uint32 u32_Type, const MRH_Event* p_Event);

#ifdef __cplusplus
}
#endif


#endif /* MRH_EvCustom_V1_h */
