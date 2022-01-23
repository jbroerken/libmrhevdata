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

#ifndef MRH_EvDataEvent_h
#define MRH_EvDataEvent_h

// C

// External
#include <MRH_Event.h>

// Project


#ifdef __cplusplus
extern "C"
{
#endif

    //*************************************************************************************
    // Create
    //*************************************************************************************

    /**
     *  Create a new event.
     *
     *  \param u32_Type The event type.
     *  \param p_Data The event data.
     *  \param u32_DataSize The size of the event data.
     *
     *  \return The created event on success, NULL on failure.
     */

    extern MRH_Event* MRH_EVD_CreateEvent(MRH_Uint32 u32_Type, const MRH_Uint8* p_Data, MRH_Uint32 u32_DataSize);
    
    //*************************************************************************************
    // Copy
    //*************************************************************************************

    /**
     *  Copy a given event.
     *
     *  \param p_Event The event to copy.
     *
     *  \return The copied event on success, NULL on failure.
     */

    extern MRH_Event* MRH_EVD_CopyEvent(const MRH_Event* p_Event);
    
    //*************************************************************************************
    // Destroy
    //*************************************************************************************

    /**
     *  Destroy a given event.
     *
     *  \param p_Event The event to destroy.
     *
     *  \return Always NULL.
     */

    extern MRH_Event* MRH_EVD_DestroyEvent(MRH_Event* p_Event);

#ifdef __cplusplus
}
#endif


#endif /* MRH_EvDataEvent_h */
