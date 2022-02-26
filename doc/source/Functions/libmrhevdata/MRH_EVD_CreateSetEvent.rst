MRH_EVD_CreateSetEvent
======================
The MRH_EVD_CreateSetEvent function is used to create a new 
event with a given type and event data.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhevdata.h>


Syntax
------
.. code-block:: c

    MRH_Event* MRH_EVD_CreateSetEvent(MRH_Uint32 u32_Type, 
                                      const void* p_Data);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - u32_Type
      - The type of event to create.
    * - p_Data
      - The event data.
      

Return Value
------------
A MRH_Event on success, NULL on failure.

Remarks
-------
* NULL should be used to create an event without data.

Code Examples
-------------
.. code-block:: c

    // Create destroy request data
    MRH_EvD_N_DestroyApp_U c_Destroy;
    c_Destroy.u32_Key = 1;
    
    // Build event by type and data
    MRH_Event* p_Result = MRH_EVD_CreateSetEvent(MRH_EVENT_NOTIFICATION_DESTROY_APP_U,
                                                 &c_Destroy);
                                                 
    if (p_Result == NULL)
    {
        // Error
    }
    else
    {
        // Created event is initialized and usable
    }