MRH_EVD_L_ToData_V1
===================
The MRH_EVD_L_ToData_V1 function is used to read listen event 
data from a listen version 1 event.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhevdata/Version/1/MRH_EvListen_V1.h>


Syntax
------
.. code-block:: c

    int MRH_EVD_L_ToData_V1(void* p_Data, 
                            MRH_Uint32 u32_Type, 
                            const MRH_Event* p_Event);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_Data
      - The listen event data to write.
    * - u32_Type
      - The type of listen event to read.
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