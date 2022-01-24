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

// External

// Project
#include "../include/libmrhevdata/libmrhevdata.h"


//*************************************************************************************
// Create Event
//*************************************************************************************

MRH_Event* MRH_EVD_CreateSetEvent(MRH_Uint32 u32_Type, const void* p_Data)
{
    MRH_Event* p_Event = MRH_EVD_CreateEvent(u32_Type, NULL, 0);
    
    if (p_Event == NULL)
    {
        return NULL;
    }
    else if (MRH_EVD_SetEvent(p_Event, u32_Type, p_Data) < 0)
    {
        return MRH_EVD_DestroyEvent(p_Event);
    }
    
    return p_Event;
}

//*************************************************************************************
// Set Event
//*************************************************************************************

int MRH_EVD_SetEvent(MRH_Event* p_Event, MRH_Uint32 u32_Type, const void* p_Data)
{
    switch (u32_Type)
    {
        /**
         *  Event Version 1
         */
            
        // System
        case MRH_EVENT_UNK:
        case MRH_EVENT_PERMISSION_DENIED:
        case MRH_EVENT_PASSWORD_REQUIRED:
        case MRH_EVENT_NOT_IMPLEMENTED_S:
        case MRH_EVENT_PS_RESET_REQUEST_U:
        case MRH_EVENT_PS_RESET_ACKNOLEDGED_U:
            return MRH_EVD_SYS_ToEvent_V1(p_Event, u32_Type, p_Data);
            
        // Custom
        case MRH_EVENT_CUSTOM_AVAIL_U:
        case MRH_EVENT_CUSTOM_CUSTOM_COMMAND_U:
        case MRH_EVENT_CUSTOM_AVAIL_S:
        case MRH_EVENT_CUSTOM_CUSTOM_COMMAND_S:
            return MRH_EVD_C_ToEvent_V1(p_Event, u32_Type, p_Data);
            
        // Voice - Listen
        case MRH_EVENT_LISTEN_AVAIL_U:
        case MRH_EVENT_LISTEN_GET_METHOD_U:
        case MRH_EVENT_LISTEN_CUSTOM_COMMAND_U:
        case MRH_EVENT_LISTEN_AVAIL_S:
        case MRH_EVENT_LISTEN_STRING_S:
        case MRH_EVENT_LISTEN_GET_METHOD_S:
        case MRH_EVENT_LISTEN_CUSTOM_COMMAND_S:
            return MRH_EVD_L_ToEvent_V1(p_Event, u32_Type, p_Data);
            
        // Voice - Say
        case MRH_EVENT_SAY_AVAIL_U:
        case MRH_EVENT_SAY_STRING_U:
        case MRH_EVENT_SAY_GET_METHOD_U:
        case MRH_EVENT_SAY_CUSTOM_COMMAND_U:
        case MRH_EVENT_SAY_AVAIL_S:
        case MRH_EVENT_SAY_STRING_S:
        case MRH_EVENT_SAY_GET_METHOD_S:
        case MRH_EVENT_SAY_CUSTOM_COMMAND_S:
            return MRH_EVD_S_ToEvent_V1(p_Event, u32_Type, p_Data);
            
        // Password
        case MRH_EVENT_PASSWORD_AVAIL_U:
        case MRH_EVENT_PASSWORD_CHECK_U:
        case MRH_EVENT_PASSWORD_SET_U:
        case MRH_EVENT_PASSWORD_CUSTOM_COMMAND_U:
        case MRH_EVENT_PASSWORD_AVAIL_S:
        case MRH_EVENT_PASSWORD_CHECK_S:
        case MRH_EVENT_PASSWORD_SET_S:
        case MRH_EVENT_PASSWORD_CUSTOM_COMMAND_S:
            return MRH_EVD_P_ToEvent_V1(p_Event, u32_Type, p_Data);
            
        // User
        case MRH_EVENT_USER_AVAIL_U:
        case MRH_EVENT_USER_ACCESS_DOCUMENTS_U:
        case MRH_EVENT_USER_ACCESS_PICTURES_U:
        case MRH_EVENT_USER_ACCESS_MUSIC_U:
        case MRH_EVENT_USER_ACCESS_VIDEOS_U:
        case MRH_EVENT_USER_ACCESS_DOWNLOADS_U:
        case MRH_EVENT_USER_ACCESS_CLIPBOARD_U:
        case MRH_EVENT_USER_ACCESS_INFO_PERSON_U:
        case MRH_EVENT_USER_ACCESS_INFO_RESIDENCE_U:
        case MRH_EVENT_USER_ACCESS_CLEAR_U:
        case MRH_EVENT_USER_GET_LOCATION_U:
        case MRH_EVENT_USER_CUSTOM_COMMAND_U:
        case MRH_EVENT_USER_AVAIL_S:
        case MRH_EVENT_USER_ACCESS_DOCUMENTS_S:
        case MRH_EVENT_USER_ACCESS_PICTURES_S:
        case MRH_EVENT_USER_ACCESS_MUSIC_S:
        case MRH_EVENT_USER_ACCESS_VIDEOS_S:
        case MRH_EVENT_USER_ACCESS_DOWNLOADS_S:
        case MRH_EVENT_USER_ACCESS_CLIPBOARD_S:
        case MRH_EVENT_USER_ACCESS_INFO_PERSON_S:
        case MRH_EVENT_USER_ACCESS_INFO_RESIDENCE_S:
        case MRH_EVENT_USER_ACCESS_CLEAR_S:
        case MRH_EVENT_USER_GET_LOCATION_S:
        case MRH_EVENT_USER_CUSTOM_COMMAND_S:
            return MRH_EVD_U_ToEvent_V1(p_Event, u32_Type, p_Data);
            
        // Application
        case MRH_EVENT_APP_AVAIL_U:
        case MRH_EVENT_APP_LAUNCH_SOA_U:
        case MRH_EVENT_APP_LAUNCH_SOA_TIMER_U:
        case MRH_EVENT_APP_LAUNCH_SOA_CLEAR_U:
        case MRH_EVENT_APP_LAUNCH_SOA_CLEAR_TIMER_U:
        case MRH_EVENT_APP_CUSTOM_COMMAND_U:
        case MRH_EVENT_APP_AVAIL_S:
        case MRH_EVENT_APP_LAUNCH_SOA_S:
        case MRH_EVENT_APP_LAUNCH_SOA_TIMER_S:
        case MRH_EVENT_APP_LAUNCH_SOA_TIMER_REMINDER_S:
        case MRH_EVENT_APP_LAUNCH_SOA_CLEAR_S:
        case MRH_EVENT_APP_LAUNCH_SOA_CLEAR_TIMER_S:
        case MRH_EVENT_APP_CUSTOM_COMMAND_S:
            return MRH_EVD_A_ToEvent_V1(p_Event, u32_Type, p_Data);
            
        // Notifications
        case MRH_EVENT_NOTIFICATION_AVAIL_U:
        case MRH_EVENT_NOTIFICATION_CREATE_APP_U:
        case MRH_EVENT_NOTIFICATION_CREATE_SERVICE_U:
        case MRH_EVENT_NOTIFICATION_DESTROY_APP_U:
        case MRH_EVENT_NOTIFICATION_GET_WAITING_U:
        case MRH_EVENT_NOTIFICATION_GET_NEXT_U:
        case MRH_EVENT_NOTIFICATION_CUSTOM_COMMAND_U:
        case MRH_EVENT_NOTIFICATION_AVAIL_S:
        case MRH_EVENT_NOTIFICATION_CREATE_APP_S:
        case MRH_EVENT_NOTIFICATION_DESTROY_APP_S:
        case MRH_EVENT_NOTIFICATION_GET_WAITING_S:
        case MRH_EVENT_NOTIFICATION_GET_NEXT_S:
        case MRH_EVENT_NOTIFICATION_CUSTOM_COMMAND_S:
            return MRH_EVD_N_ToEvent_V1(p_Event, u32_Type, p_Data);
        /**
         *  Unk
         */
            
        default:
            return -1;
    }
}

//*************************************************************************************
// Read Event
//*************************************************************************************

int MRH_EVD_ReadEvent(void* p_Data, MRH_Uint32 u32_Type, const MRH_Event* p_Event)
{
    switch (u32_Type)
    {
        /**
         *  Event Version 1
         */
            
        // System
        case MRH_EVENT_UNK:
        case MRH_EVENT_PERMISSION_DENIED:
        case MRH_EVENT_PASSWORD_REQUIRED:
        case MRH_EVENT_NOT_IMPLEMENTED_S:
        case MRH_EVENT_PS_RESET_REQUEST_U:
        case MRH_EVENT_PS_RESET_ACKNOLEDGED_U:
            return MRH_EVD_SYS_ToData_V1(p_Data, u32_Type, p_Event);
            
        // Custom
        case MRH_EVENT_CUSTOM_AVAIL_U:
        case MRH_EVENT_CUSTOM_CUSTOM_COMMAND_U:
        case MRH_EVENT_CUSTOM_AVAIL_S:
        case MRH_EVENT_CUSTOM_CUSTOM_COMMAND_S:
            return MRH_EVD_C_ToData_V1(p_Data, u32_Type, p_Event);
            
        // Voice - Listen
        case MRH_EVENT_LISTEN_AVAIL_U:
        case MRH_EVENT_LISTEN_GET_METHOD_U:
        case MRH_EVENT_LISTEN_CUSTOM_COMMAND_U:
        case MRH_EVENT_LISTEN_AVAIL_S:
        case MRH_EVENT_LISTEN_STRING_S:
        case MRH_EVENT_LISTEN_GET_METHOD_S:
        case MRH_EVENT_LISTEN_CUSTOM_COMMAND_S:
            return MRH_EVD_L_ToData_V1(p_Data, u32_Type, p_Event);
            
        // Voice - Say
        case MRH_EVENT_SAY_AVAIL_U:
        case MRH_EVENT_SAY_STRING_U:
        case MRH_EVENT_SAY_GET_METHOD_U:
        case MRH_EVENT_SAY_CUSTOM_COMMAND_U:
        case MRH_EVENT_SAY_AVAIL_S:
        case MRH_EVENT_SAY_STRING_S:
        case MRH_EVENT_SAY_GET_METHOD_S:
        case MRH_EVENT_SAY_CUSTOM_COMMAND_S:
            return MRH_EVD_S_ToData_V1(p_Data, u32_Type, p_Event);
            
        // Password
        case MRH_EVENT_PASSWORD_AVAIL_U:
        case MRH_EVENT_PASSWORD_CHECK_U:
        case MRH_EVENT_PASSWORD_SET_U:
        case MRH_EVENT_PASSWORD_CUSTOM_COMMAND_U:
        case MRH_EVENT_PASSWORD_AVAIL_S:
        case MRH_EVENT_PASSWORD_CHECK_S:
        case MRH_EVENT_PASSWORD_SET_S:
        case MRH_EVENT_PASSWORD_CUSTOM_COMMAND_S:
            return MRH_EVD_P_ToData_V1(p_Data, u32_Type, p_Event);
            
        // User
        case MRH_EVENT_USER_AVAIL_U:
        case MRH_EVENT_USER_ACCESS_DOCUMENTS_U:
        case MRH_EVENT_USER_ACCESS_PICTURES_U:
        case MRH_EVENT_USER_ACCESS_MUSIC_U:
        case MRH_EVENT_USER_ACCESS_VIDEOS_U:
        case MRH_EVENT_USER_ACCESS_DOWNLOADS_U:
        case MRH_EVENT_USER_ACCESS_CLIPBOARD_U:
        case MRH_EVENT_USER_ACCESS_INFO_PERSON_U:
        case MRH_EVENT_USER_ACCESS_INFO_RESIDENCE_U:
        case MRH_EVENT_USER_ACCESS_CLEAR_U:
        case MRH_EVENT_USER_GET_LOCATION_U:
        case MRH_EVENT_USER_CUSTOM_COMMAND_U:
        case MRH_EVENT_USER_AVAIL_S:
        case MRH_EVENT_USER_ACCESS_DOCUMENTS_S:
        case MRH_EVENT_USER_ACCESS_PICTURES_S:
        case MRH_EVENT_USER_ACCESS_MUSIC_S:
        case MRH_EVENT_USER_ACCESS_VIDEOS_S:
        case MRH_EVENT_USER_ACCESS_DOWNLOADS_S:
        case MRH_EVENT_USER_ACCESS_CLIPBOARD_S:
        case MRH_EVENT_USER_ACCESS_INFO_PERSON_S:
        case MRH_EVENT_USER_ACCESS_INFO_RESIDENCE_S:
        case MRH_EVENT_USER_ACCESS_CLEAR_S:
        case MRH_EVENT_USER_GET_LOCATION_S:
        case MRH_EVENT_USER_CUSTOM_COMMAND_S:
            return MRH_EVD_U_ToData_V1(p_Data, u32_Type, p_Event);
            
        // Application
        case MRH_EVENT_APP_AVAIL_U:
        case MRH_EVENT_APP_LAUNCH_SOA_U:
        case MRH_EVENT_APP_LAUNCH_SOA_TIMER_U:
        case MRH_EVENT_APP_LAUNCH_SOA_CLEAR_U:
        case MRH_EVENT_APP_LAUNCH_SOA_CLEAR_TIMER_U:
        case MRH_EVENT_APP_CUSTOM_COMMAND_U:
        case MRH_EVENT_APP_AVAIL_S:
        case MRH_EVENT_APP_LAUNCH_SOA_S:
        case MRH_EVENT_APP_LAUNCH_SOA_TIMER_S:
        case MRH_EVENT_APP_LAUNCH_SOA_TIMER_REMINDER_S:
        case MRH_EVENT_APP_LAUNCH_SOA_CLEAR_S:
        case MRH_EVENT_APP_LAUNCH_SOA_CLEAR_TIMER_S:
        case MRH_EVENT_APP_CUSTOM_COMMAND_S:
            return MRH_EVD_A_ToData_V1(p_Data, u32_Type, p_Event);
            
        // Notifications
        case MRH_EVENT_NOTIFICATION_AVAIL_U:
        case MRH_EVENT_NOTIFICATION_CREATE_APP_U:
        case MRH_EVENT_NOTIFICATION_CREATE_SERVICE_U:
        case MRH_EVENT_NOTIFICATION_DESTROY_APP_U:
        case MRH_EVENT_NOTIFICATION_GET_WAITING_U:
        case MRH_EVENT_NOTIFICATION_GET_NEXT_U:
        case MRH_EVENT_NOTIFICATION_CUSTOM_COMMAND_U:
        case MRH_EVENT_NOTIFICATION_AVAIL_S:
        case MRH_EVENT_NOTIFICATION_CREATE_APP_S:
        case MRH_EVENT_NOTIFICATION_DESTROY_APP_S:
        case MRH_EVENT_NOTIFICATION_GET_WAITING_S:
        case MRH_EVENT_NOTIFICATION_GET_NEXT_S:
        case MRH_EVENT_NOTIFICATION_CUSTOM_COMMAND_S:
            return MRH_EVD_N_ToData_V1(p_Data, u32_Type, p_Event);
        /**
         *  Unk
         */
            
        default:
            return -1;
    }
}
