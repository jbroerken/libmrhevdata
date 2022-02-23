MRH_EvD_Base_CustomCommand_t
============================
The MRH_EvD_Base_CustomCommand_t struct represents the data 
for a custom command event.

Header
------
The struct definition can be found in the following file:

.. code-block:: c

    #include <libmrhevdata/Version/MRH_EvBase.h>


Variables
---------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_Buffer
      - The data buffer for the custom command.
    * - u32_DataSize
      - The actual size of the data buffer.
      

Remarks
-------
* The data buffer is static in size.