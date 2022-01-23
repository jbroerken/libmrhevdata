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

// C
#include <stdlib.h>
#include <string.h>

// External

// Project
#include "../../include/libmrhevdata/libmrhevdata/MRH_EvDataEvent.h"


//*************************************************************************************
// Create
//*************************************************************************************

MRH_Event* MRH_EVD_CreateEvent(MRH_Uint32 u32_Type, const MRH_Uint8* p_Data, MRH_Uint32 u32_DataSize)
{
    if (u32_Type > MRH_EVENT_TYPE_MAX || (p_Data == NULL && u32_DataSize > 0))
    {
        return NULL;
    }
    
    MRH_Event* p_Event = (MRH_Event*)malloc(sizeof(MRH_Event));
    
    if (p_Event == NULL)
    {
        return NULL;
    }
    
    p_Event->u32_Type = u32_Type;
    p_Event->u32_GroupID = 0;
    
    if (p_Data == NULL || u32_DataSize == 0)
    {
        p_Event->p_Data = NULL;
        p_Event->u32_DataSize = 0;
        
        return p_Event;
    }
    
    p_Event->p_Data = (MRH_Uint8*)malloc(u32_DataSize);
    
    if (p_Event->p_Data == NULL)
    {
        free(p_Event);
        return NULL;
    }
    
    memcpy(p_Event->p_Data, p_Data, u32_DataSize);
    p_Event->u32_DataSize = u32_DataSize;
    
    return p_Event;
}

//*************************************************************************************
// Copy
//*************************************************************************************

MRH_Event* MRH_EVD_CopyEvent(const MRH_Event* p_Event)
{
    MRH_Event* p_Result = MRH_EVD_CreateEvent(p_Event->u32_Type, p_Event->p_Data, p_Event->u32_DataSize);
    
    if (p_Result == NULL)
    {
        return NULL;
    }
    
    p_Result->u32_GroupID = p_Event->u32_GroupID;
    
    return p_Result;
}

//*************************************************************************************
// Destroy
//*************************************************************************************

MRH_Event* MRH_EVD_DestroyEvent(MRH_Event* p_Event)
{
    if (p_Event == NULL)
    {
        return NULL;
    }
    
    if (p_Event->p_Data != NULL)
    {
        free(p_Event->p_Data);
    }
    
    free(p_Event);
    
    return NULL;
}
