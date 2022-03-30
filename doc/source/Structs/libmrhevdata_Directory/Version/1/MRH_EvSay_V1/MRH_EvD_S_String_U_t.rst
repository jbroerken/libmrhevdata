MRH_EvD_S_String_U_t
====================
The MRH_EvD_S_String_U_t struct represents the data for a 
say string event representing output to perform.

Header
------
The struct definition can be found in the following file:

.. code-block:: c

    #include <libmrhevdata/Version/1/MRH_EvSay_V1.h>


Variables
---------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - u32_ID
      - The string id for identification.
    * - p_String
      - The string characters.
      

Remarks
-------
* The string buffer is allocated statically.
* The static string buffer size is defined by :doc:`../../../../../../Macros/libmrhevdata_Directory/Version/1/MRH_EvSay_V1/MRH_EVD_S_STRING_BUFFER_MAX_TERMINATED`.