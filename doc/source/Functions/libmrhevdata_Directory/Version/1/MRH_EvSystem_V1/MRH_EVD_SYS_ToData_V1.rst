MRH_EVD_SYS_ToData_V1
=====================
The MRH_EVD_SYS_ToData_V1 function is used to read system event 
data from a system version 1 event.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhevdata/Version/1/MRH_EvSystem_V1.h>


Syntax
------
.. code-block:: c

    int MRH_EVD_SYS_ToData_V1(void* p_Data, 
                              MRH_Uint32 u32_Type, 
                              const MRH_Event* p_Event);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_Data
      - The system event data to write.
    * - u32_Type
      - The type of system event to read.
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
None.