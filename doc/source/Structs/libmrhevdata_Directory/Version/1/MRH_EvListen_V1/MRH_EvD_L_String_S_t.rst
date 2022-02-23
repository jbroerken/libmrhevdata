MRH_EvD_L_String_S_t
====================
The MRH_EvD_L_String_S_t struct represents the data for a 
listen string event representing part of recieved input.

Header
------
The struct definition can be found in the following file:

.. code-block:: c

    #include <libmrhevdata/Version/1/MRH_EvListen_V1.h>


Variables
---------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - u8_Type
      - The type of string part recieved.
    * - u32_ID
      - The string id to group parts.
    * - u32_Part
      - The part number for the string part.
    * - p_String
      - The actual string characters.
      

Remarks
-------
* Part numbers are sequential.
* The string buffer is allocated statically.
* The static string buffer size is defined by :doc:`../../../../../../Macros/libmrhevdata_Directory/Version/1/MRH_EvListen_V1/MRH_EVD_L_STRING_BUFFER_MAX_TERMINATED`.
* The type is defined by :doc:`../../../../../../Enumerations/libmrhevdata_Directory/Version/1/MRH_EvListen_V1/MRH_EvD_L_StringType`.