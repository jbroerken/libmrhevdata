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
#include "../../../../include/libmrhevdata/libmrhevdata/Version/1/MRH_EvSystem_V1.h"


//*************************************************************************************
// Convert
//*************************************************************************************

int MRH_EVD_SYS_ToEvent_V1(MRH_Event* p_Event, MRH_Uint32 u32_Type, const void* p_Data)
{
    if (p_Event == NULL || p_Data == NULL)
    {
        return -1;
    }
    
    // Get the required data size
    MRH_Uint32 u32_DataSize;
    
    switch (u32_Type)
    {
        case MRH_EVENT_PERMISSION_DENIED:
        case MRH_EVENT_PASSWORD_REQUIRED:
        case MRH_EVENT_NOT_IMPLEMENTED_S:
            u32_DataSize = 4; // 1 * Uint32
            break;
            
        case MRH_EVENT_PS_RESET_REQUEST_U:
            u32_DataSize = strnlen((((MRH_EvD_Sys_ResetRequest_U*)p_Data)->p_PackagePath), MRH_EVD_SYS_STRING_BUFFER_MAX );
            break;
            
        case MRH_EVENT_UNK:
            u32_DataSize = 0;
            break;
                
        default:
            return -1;
    }
    
    // Create, modify or remove the buffer
    if (p_Event->p_Data != NULL && u32_DataSize == 0)
    {
        free(p_Event->p_Data);
        p_Event->p_Data = NULL;
    }
    else
    {
        if (p_Event->p_Data == NULL)
        {
            if ((p_Event->p_Data = (MRH_Uint8*)malloc(u32_DataSize)) == NULL)
            {
                return -1;
            }
        }
        else if (p_Event->u32_DataSize != u32_DataSize)
        {
            MRH_Uint8* p_Buffer = (MRH_Uint8*)realloc((p_Event->p_Data), u32_DataSize);
            
            if (p_Buffer == NULL)
            {
                return -1;
            }
            
            p_Event->p_Data = p_Buffer;
        }
    }
    
    // Create event data
    if (u32_DataSize > 0)
    {
        switch (u32_Type)
        {
            case MRH_EVENT_PERMISSION_DENIED:
            case MRH_EVENT_PASSWORD_REQUIRED:
            case MRH_EVENT_NOT_IMPLEMENTED_S:
                memcpy(&(p_Event->p_Data[0]), &(((struct MRH_EvD_Sys_EventID_t*)p_Data)->u32_Type), 4);
                break;
                
            case MRH_EVENT_PS_RESET_REQUEST_U:
                memcpy(&(p_Event->p_Data[0]), &(((MRH_EvD_Sys_ResetRequest_U*)p_Data)->p_PackagePath), u32_DataSize);
                break;
                
            default:
                return -1;
        }
    }
    
    // Reset type and group
    p_Event->u32_Type = u32_Type;
    p_Event->u32_GroupID = 0;
    p_Event->u32_DataSize = u32_DataSize;
    
    return 0;
}

int MRH_EVD_SYS_ToData_V1(void* p_Data, MRH_Uint32 u32_Type, const MRH_Event* p_Event)
{
    if (p_Data == NULL)
    {
        return -1;
    }
    
    // Check data size
    switch (u32_Type)
    {
        case MRH_EVENT_PERMISSION_DENIED:
        case MRH_EVENT_PASSWORD_REQUIRED:
        case MRH_EVENT_NOT_IMPLEMENTED_S:
            if (p_Event->u32_DataSize != 4)
            {
                return -1;
            }
            break;
            
        default:
            return -1;
    }
    
    // Copy data
    switch (u32_Type)
    {
        case MRH_EVENT_PERMISSION_DENIED:
        case MRH_EVENT_PASSWORD_REQUIRED:
        case MRH_EVENT_NOT_IMPLEMENTED_S:
            memcpy(&(((struct MRH_EvD_Sys_EventID_t*)p_Data)->u32_Type), &(p_Event->p_Data[0]), 4);
            return 0;
            
        default:
            return -1;
    }
}
