*****
Usage
*****
libmrhevdata is used to easily convert events to a matching event 
struct and a struct to a matching event. Using the library provided 
event structs allows an application, application service or platform 
service to make the processing of events a lot easier.

.. note::

    The library does only provide data structures for standard events. 
    Custom events will always be handled by using a buffer.


Only the main library header has to be included to use the event writing and 
creation functions as well as all event data structs known to the library.

.. code-block:: c

    #include <libmrhevdata.h>


Writing Events to Structs
-------------------------
Received or otherwise stored events which are known to the library can 
be used to write their data to a matching event struct. The writing happens 
with the :doc:`../Functions/libmrhevdata/MRH_EVD_ReadEvent` function.

The function takes a matching event data struct as well as the event type for 
struct identification and the event itself as parameters.

.. code-block:: c

    // Received events
    MRH_Event* p_Event = ...
    
    // Create destroy response data
    MRH_EvD_N_DestroyApp_S c_Result;
    
    // Fill with recieved event
    int i_Result = MRH_EVD_ReadEvent(&c_Result,
                                     p_Event->u32_Type,
                                     p_Event);
                                                 
    if (i_Result < 0)
    {
        // Error
    }
    else
    {
        // c_Result is now set
    }


Creating Events from Structs
----------------------------
New events can be created from struct data by using the 
:doc:`../Functions/libmrhevdata/MRH_EVD_CreateSetEvent` function. 
This function will allocate a new event with matching sizes for 
the given event data struct.

The function takes the event type for struct identification and 
the actual event data struct as parameters.

.. note:: 

    An existing event can be overwritten by using the 
    :doc:`../Functions/libmrhevdata/MRH_EVD_SetEvent` 
    function.


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
