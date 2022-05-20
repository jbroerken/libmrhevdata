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

#ifndef MRH_EvListen_V1_h
#define MRH_EvListen_V1_h

// C

// External

// Project
#include "../MRH_EvBase.h"

// Pre-defined
#define MRH_EVD_L_STRING_BUFFER_MAX (MRH_EVENT_DATA_SIZE_MAX - 4)  // 1 * Uint32
#define MRH_EVD_L_STRING_BUFFER_MAX_TERMINATED (MRH_EVD_L_STRING_BUFFER_MAX + 1)


#ifdef __cplusplus
extern "C"
{
#endif
    
    //*************************************************************************************
    // Types
    //*************************************************************************************

    /**
     *  Event Values
     */
    
    typedef enum
    {
        MRH_EVD_L_SPEECH_AUDIO = 0,
        MRH_EVD_L_SPEECH_TEXT_STRING = 1,
        
        MRH_EVD_L_SPEECH_METHOD_MAX = MRH_EVD_L_SPEECH_TEXT_STRING,
        
        MRH_EVD_L_SPEECH_METHOD_COUNT = MRH_EVD_L_SPEECH_METHOD_MAX + 1
        
    }MRH_EvD_L_SpeechMethod;
    
    /**
     *  Event Data
     */
    
    struct MRH_EvD_L_String_S_t
    {
        MRH_Uint32 u32_ID;
        char p_String[MRH_EVD_L_STRING_BUFFER_MAX_TERMINATED];
    };
    
    struct MRH_EvD_L_GetMethod_S_t
    {
        MRH_Uint8 u8_Result;
        MRH_Uint8 u8_Method;
    };
    
    /**
     *  Events
     */
    
    // User
    typedef struct MRH_EvD_Base_CustomCommand_t MRH_EvD_L_CustomCommand_U;
    
    // Service
    typedef struct MRH_EvD_Base_ServiceAvail_S_t MRH_EvD_L_ServiceAvail_S;
    typedef struct MRH_EvD_L_String_S_t MRH_EvD_L_String_S;
    typedef struct MRH_EvD_L_GetMethod_S_t MRH_EvD_L_GetMethod_S;
    typedef struct MRH_EvD_Base_CustomCommand_t MRH_EvD_L_CustomCommand_S;
    
    //*************************************************************************************
    // Convert
    //*************************************************************************************
    
    /**
     *  Write a listen version 1 event with given listen event data.
     *
     *  \param p_Event The event to write to. The event data will be overwritten.
     *  \param u32_Type The type of listen event to write.
     *  \param p_Data The listen event data.
     *
     *  \return 0 on success, -1 on failure.
     */

    extern int MRH_EVD_L_ToEvent_V1(MRH_Event* p_Event, MRH_Uint32 u32_Type, const void* p_Data);

    /**
     *  Read listen event data from a listen version 1 event.
     *
     *  \param p_Data The listen event data to write.
     *  \param u32_Type The type of listen event to read.
     *  \param p_Event The event to read from.
     *
     *  \return 0 on success, -1 on failure.
     */

    extern int MRH_EVD_L_ToData_V1(void* p_Data, MRH_Uint32 u32_Type, const MRH_Event* p_Event);

#ifdef __cplusplus
}
#endif


#endif /* MRH_EvListen_V1_h */
