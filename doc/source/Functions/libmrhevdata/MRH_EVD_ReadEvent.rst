MRH_EVD_ReadEvent
=================
The MRH_EVD_ReadEvent function is used to read event data from 
a given event.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhevdata.h>


Syntax
------
.. code-block:: c

    int MRH_EVD_ReadEvent(void* p_Data, 
                          MRH_Uint32 u32_Type, 
                          const MRH_Event* p_Event);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_Data
      - The event data to write.
    * - u32_Type
      - The type of event to read.
    * - p_Event
      - The event to read from.
      

Return Value
------------
0 on success, -1 on failure.

Remarks
-------
None.

Code Examples
-------------
.. code-block:: c

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