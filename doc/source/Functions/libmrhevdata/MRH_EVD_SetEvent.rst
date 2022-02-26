MRH_EVD_SetEvent
================
The MRH_EVD_SetEvent function is used to set a known event 
of a type with given event data.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhevdata.h>


Syntax
------
.. code-block:: c

    int MRH_EVD_SetEvent(MRH_Event* p_Event, 
                         MRH_Uint32 u32_Type, 
                         const void* p_Data);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_Event
      - The event to write to. The event data will be 
        overwritten.
    * - u32_Type
      - The type of event to set.
    * - p_Data
      - The event data to use.
      

Return Value
------------
0 on success, -1 on failure.

Remarks
-------
None.

Code Examples
-------------
.. code-block:: c

    // Create event
    MRH_Event* p_Event = ... // Creation
    
    // Create destroy request data
    MRH_EvD_N_DestroyApp_U c_Destroy;
    c_Destroy.u32_Key = 1;
    
    // Set with created event
    int i_Result = MRH_EVD_SetEvent(p_Event,
                                    MRH_EVENT_NOTIFICATION_DESTROY_APP_U,
                                    &c_Destroy);
                                                 
    if (i_Result < 0)
    {
        // Error
    }
    else
    {
        // Event is now set
    }