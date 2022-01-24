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
#include "../../../../include/libmrhevdata/libmrhevdata/Version/1/MRH_EvSay_V1.h"


//*************************************************************************************
// Convert
//*************************************************************************************

int MRH_EVD_S_ToEvent_V1(MRH_Event* p_Event, MRH_Uint32 u32_Type, const void* p_Data)
{
    if (p_Event == NULL || p_Data == NULL)
    {
        return -1;
    }
    
    // Get the required data size
    MRH_Uint32 u32_DataSize;
    
    switch (u32_Type)
    {
        case MRH_EVENT_SAY_AVAIL_S:
            u32_DataSize = 13; // 3 * Uint32 + 1 * Uint8
            break;
            
        case MRH_EVENT_SAY_GET_METHOD_S:
            u32_DataSize = 2; // 2 * Uint8
            break;
            
        case MRH_EVENT_SAY_STRING_U:
            u32_DataSize = 9; // 2 * Uint32 + 1 * Uint8
            u32_DataSize += strnlen((((MRH_EvD_S_String_U*)p_Data)->p_String), MRH_EVD_S_STRING_BUFFER_MAX);
            break;
        case MRH_EVENT_SAY_STRING_S:
            u32_DataSize = 4; // 1 * Uint32
            break;
              
        case MRH_EVENT_SAY_CUSTOM_COMMAND_U:
        case MRH_EVENT_SAY_CUSTOM_COMMAND_S:
            if ((u32_DataSize = ((struct MRH_EvD_Base_CustomCommand_t*)p_Data)->u32_DataSize) > MRH_EVENT_DATA_SIZE_MAX)
            {
                return -1;
            }
            break;
            
        case MRH_EVENT_SAY_AVAIL_U:
        case MRH_EVENT_SAY_GET_METHOD_U:
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
            case MRH_EVENT_SAY_AVAIL_S:
                memcpy(&(p_Event->p_Data[0]), &(((MRH_EvD_S_ServiceAvail_S*)p_Data)->u8_Available), 1);
                memcpy(&(p_Event->p_Data[1]), &(((MRH_EvD_S_ServiceAvail_S*)p_Data)->u32_SupplierID), 4);
                memcpy(&(p_Event->p_Data[5]), &(((MRH_EvD_S_ServiceAvail_S*)p_Data)->u32_BinaryID), 4);
                memcpy(&(p_Event->p_Data[9]), &(((MRH_EvD_S_ServiceAvail_S*)p_Data)->u32_Version), 4);
                break;
                
            case MRH_EVENT_SAY_GET_METHOD_S:
                memcpy(&(p_Event->p_Data[0]), &(((MRH_EvD_S_GetMethod_S*)p_Data)->u8_Result), 1);
                memcpy(&(p_Event->p_Data[1]), &(((MRH_EvD_S_GetMethod_S*)p_Data)->u8_Method), 1);
                break;
                
            case MRH_EVENT_SAY_STRING_U:
                memcpy(&(p_Event->p_Data[0]), &(((MRH_EvD_S_String_U*)p_Data)->u8_Type), 1);
                memcpy(&(p_Event->p_Data[1]), &(((MRH_EvD_S_String_U*)p_Data)->u32_ID), 4);
                memcpy(&(p_Event->p_Data[5]), &(((MRH_EvD_S_String_U*)p_Data)->u32_Part), 4);
                
                if (u32_DataSize > 9)
                {
                    memcpy(&(p_Event->p_Data[9]), (((MRH_EvD_S_String_U*)p_Data)->p_String), u32_DataSize - 9);
                }
                break;
            case MRH_EVENT_SAY_STRING_S:
                memcpy(&(p_Event->p_Data[0]), &(((MRH_EvD_S_String_S*)p_Data)->u32_ID), 4);
                break;
               
            case MRH_EVENT_SAY_CUSTOM_COMMAND_U:
            case MRH_EVENT_SAY_CUSTOM_COMMAND_S:
                memcpy((p_Event->p_Data), (((struct MRH_EvD_Base_CustomCommand_t*)p_Data)->p_Buffer), u32_DataSize);
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

int MRH_EVD_S_ToData_V1(void* p_Data, MRH_Uint32 u32_Type, const MRH_Event* p_Event)
{
    if (p_Data == NULL)
    {
        return -1;
    }
    
    // Check data size
    switch (u32_Type)
    {
        case MRH_EVENT_SAY_AVAIL_S:
            if (p_Event->u32_DataSize != 13)
            {
                return -1;
            }
            break;
            
        case MRH_EVENT_SAY_GET_METHOD_S:
            if (p_Event->u32_DataSize != 2)
            {
                return -1;
            }
            break;
            
        case MRH_EVENT_SAY_STRING_U:
            if (p_Event->u32_DataSize < 9)
            {
                return -1;
            }
            break;
        case MRH_EVENT_SAY_STRING_S:
            if (p_Event->u32_DataSize != 4)
            {
                return -1;
            }
            break;
            
        case MRH_EVENT_SAY_CUSTOM_COMMAND_U:
        case MRH_EVENT_SAY_CUSTOM_COMMAND_S:
            break;
            
        default:
            return -1;
    }
    
    // Copy data
    switch (u32_Type)
    {
        case MRH_EVENT_SAY_AVAIL_S:
            memcpy(&(((MRH_EvD_S_ServiceAvail_S*)p_Data)->u8_Available), &(p_Event->p_Data[0]), 1);
            memcpy(&(((MRH_EvD_S_ServiceAvail_S*)p_Data)->u32_SupplierID), &(p_Event->p_Data[1]), 4);
            memcpy(&(((MRH_EvD_S_ServiceAvail_S*)p_Data)->u32_BinaryID), &(p_Event->p_Data[5]), 4);
            memcpy(&(((MRH_EvD_S_ServiceAvail_S*)p_Data)->u32_Version), &(p_Event->p_Data[9]), 4);
            return 0;
            
        case MRH_EVENT_SAY_GET_METHOD_S:
            memcpy(&(((MRH_EvD_S_GetMethod_S*)p_Data)->u8_Result), &(p_Event->p_Data[0]), 1);
            memcpy(&(((MRH_EvD_S_GetMethod_S*)p_Data)->u8_Method), &(p_Event->p_Data[1]), 1);
            return -1;
            
        case MRH_EVENT_SAY_STRING_U:
            memcpy(&(((MRH_EvD_S_String_U*)p_Data)->u8_Type), &(p_Event->p_Data[0]), 1);
            memcpy(&(((MRH_EvD_S_String_U*)p_Data)->u32_ID), &(p_Event->p_Data[1]), 4);
            memcpy(&(((MRH_EvD_S_String_U*)p_Data)->u32_Part), &(p_Event->p_Data[5]), 4);
            memset((((MRH_EvD_S_String_U*)p_Data)->p_String), '\0', MRH_EVD_S_STRING_BUFFER_MAX_TERMINATED);
            
            if (p_Event->u32_DataSize > 9)
            {
                memcpy((((MRH_EvD_S_String_U*)p_Data)->p_String), &(p_Event->p_Data[9]), p_Event->u32_DataSize - 9);
            }
            return 0;
        case MRH_EVENT_SAY_STRING_S:
            memcpy(&(((MRH_EvD_S_String_U*)p_Data)->u32_ID), &(p_Event->p_Data[0]), 4);
            return 0;
            
        case MRH_EVENT_SAY_CUSTOM_COMMAND_U:
        case MRH_EVENT_SAY_CUSTOM_COMMAND_S:
            memset((((struct MRH_EvD_Base_CustomCommand_t*)p_Data)->p_Buffer), '\0', MRH_EVENT_DATA_SIZE_MAX);
            
            if (((struct MRH_EvD_Base_CustomCommand_t*)p_Data)->u32_DataSize > 0)
            {
                memcpy((((struct MRH_EvD_Base_CustomCommand_t*)p_Data)->p_Buffer), p_Event->p_Data, p_Event->u32_DataSize);
            }
            
            ((struct MRH_EvD_Base_CustomCommand_t*)p_Data)->u32_DataSize = p_Event->u32_DataSize;
            return 0;
            
        default:
            return -1;
    }
}
