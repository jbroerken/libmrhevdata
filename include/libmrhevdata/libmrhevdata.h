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

#ifndef libmrhevdata_h
#define libmrhevdata_h

// C

// External

// Project
#include "./libmrhevdata/MRH_EvSystem.h"
#include "./libmrhevdata/MRH_EvCustom.h"
#include "./libmrhevdata/MRH_EvListen.h"
#include "./libmrhevdata/MRH_EvSay.h"
#include "./libmrhevdata/MRH_EvPassword.h"
#include "./libmrhevdata/MRH_EvUser.h"
#include "./libmrhevdata/MRH_EvApplication.h"
#include "./libmrhevdata/MRH_EvNotification.h"
#include "./libmrhevdata/MRH_EvDataEvent.h"
#include "./libmrhevdata/MRH_EvDataRevision.h"


#ifdef __cplusplus
extern "C"
{
#endif
    
    //*************************************************************************************
    // Create Event
    //*************************************************************************************

    /**
     *  Create and set an event with event data.
     *
     *  \param u32_Type The event type.
     *  \param p_Data The event data to set with.
     *
     *  \return A MRH_Event on success, NULL on failure.
     */
    
    extern MRH_Event* MRH_EVD_CreateSetEvent(MRH_Uint32 u32_Type, const void* p_Data);
    
    //*************************************************************************************
    // Set Event
    //*************************************************************************************

    /**
     *  Set a event with event data.
     *
     *  \param p_Event The event to set.
     *  \param u32_Type The event type.
     *  \param p_Data The event data to set with.
     *
     *  \return 0 on success, -1 on failure.
     */

    extern int MRH_EVD_SetEvent(MRH_Event* p_Event, MRH_Uint32 u32_Type, const void* p_Data);
    
    //*************************************************************************************
    // Read Event
    //*************************************************************************************
    
    /**
     *  Read event data from a given event.
     *
     *  \param p_Data The data to initialize.
     *  \param u32_Type The event type.
     *  \param p_Event The event to read from.
     *
     *  \return 0 on success, -1 on failure.
     */

    extern int MRH_EVD_ReadEvent(void* p_Data, MRH_Uint32 u32_Type, const MRH_Event* p_Event);

#ifdef __cplusplus
}
#endif


#endif /* libmrhevdata_h */
