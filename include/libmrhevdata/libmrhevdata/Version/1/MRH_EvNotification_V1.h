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

#ifndef MRH_EvNotification_V1_h
#define MRH_EvNotification_V1_h

// C

// External

// Project
#include "../MRH_EvBase.h"

// Pre-defined
#define MRH_EVD_N_STRING_CREATE_BUFFER_MAX MRH_EVENT_DATA_SIZE_MAX - 8 // - Uint64
#define MRH_EVD_N_STRING_CREATE_BUFFER_MAX_TERMINATED (MRH_EVD_N_STRING_CREATE_BUFFER_MAX + 1)

#define MRH_EVD_N_STRING_GET_BUFFER_MAX MRH_EVENT_DATA_SIZE_MAX - 1 // - Uint8
#define MRH_EVD_N_STRING_GET_BUFFER_MAX_TERMINATED MRH_EVD_N_STRING_GET_BUFFER_MAX + 1



#ifdef __cplusplus
extern "C"
{
#endif
    
    //*************************************************************************************
    // Types
    //*************************************************************************************

    /**
     *  Event Data
     */
    
    struct MRH_EvD_N_Create_U_t
    {
        MRH_Uint64 u64_TriggerTimepointS;
        char p_String[MRH_EVD_N_STRING_CREATE_BUFFER_MAX_TERMINATED];
    };
    
    struct MRH_EvD_N_Destroy_U_t
    {
        MRH_Uint32 u32_Key;
    };
    
    struct MRH_EvD_N_Create_S_t
    {
        MRH_Uint8 u8_Result;
        MRH_Uint32 u32_Key;
    };
    
    struct MRH_EvD_N_Destroy_S_t
    {
        MRH_Uint8 u8_Result;
        MRH_Uint32 u32_Key;
    };
    
    struct MRH_EvD_N_GetNext_S_t
    {
        MRH_Uint8 u8_Result;
        char p_String[MRH_EVD_N_STRING_GET_BUFFER_MAX_TERMINATED];
    };
    
    /**
     *  Events
     */
    
    // User
    typedef struct MRH_EvD_N_Create_U_t MRH_EvD_N_CreateApp_U;
    typedef struct MRH_EvD_N_Create_U_t MRH_EvD_N_CreateService_U;
    typedef struct MRH_EvD_N_Destroy_U_t MRH_EvD_N_DestroyApp_U;
    typedef struct MRH_EvD_Base_CustomCommand_t MRH_EvD_N_CustomCommand_U;
    
    // Service
    typedef struct MRH_EvD_Base_ServiceAvail_S_t MRH_EvD_N_ServiceAvail_S;
    typedef struct MRH_EvD_N_Create_S_t MRH_EvD_N_CreateApp_S;
    typedef struct MRH_EvD_N_Destroy_S_t MRH_EvD_N_DestroyApp_S;
    typedef struct MRH_EvD_Base_Result_t MRH_EvD_N_GetWaiting_S;
    typedef struct MRH_EvD_N_GetNext_S_t MRH_EvD_N_GetNext_S;
    typedef struct MRH_EvD_Base_CustomCommand_t MRH_EvD_N_CustomCommand_S;
    
    //*************************************************************************************
    // Convert
    //*************************************************************************************
    
    /**
     *  Write a notification version 1 event with given notification event data.
     *
     *  \param p_Event The event to write to. The data buffer will be overwritten.
     *  \param u32_Type The type of notification event to write.
     *  \param p_Data The notification data.
     *
     *  \return 0 on success, -1 on failure.
     */

    extern int MRH_EVD_N_ToEvent_V1(MRH_Event* p_Event, MRH_Uint32 u32_Type, const void* p_Data);

    /**
     *  Read notification event data from a notification version 1 event.
     *
     *  \param p_Data The notification event data to write.
     *  \param u32_Type The type of notification event to read.
     *  \param p_Event The event to read from.
     *
     *  \return 0 on success, -1 on failure.
     */

    extern int MRH_EVD_N_ToData_V1(void* p_Data, MRH_Uint32 u32_Type, const MRH_Event* p_Event);

#ifdef __cplusplus
}
#endif


#endif /* MRH_EvNotification_V1_h */
