MRH_EVD_P_ToEvent_V1
====================
The MRH_EVD_P_ToEvent_V1 function is used to write a password 
version 1 event with given password event data.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhevdata/Version/1/MRH_EvPassword_V1.h>


Syntax
------
.. code-block:: c

    int MRH_EVD_P_ToEvent_V1(MRH_Event* p_Event, 
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
      - The type of password event to write.
    * - p_Data
      - The password event data.
      

Return Value
------------
0 on success, -1 on failure.

Remarks
-------
None.

Code Examples
-------------
None.