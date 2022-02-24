MRH_EvD_P_String_U_t
====================
The MRH_EvD_P_String_U_t struct represents the data for a 
password string event.

Header
------
The struct definition can be found in the following file:

.. code-block:: c

    #include <libmrhevdata/Version/1/MRH_EvPassword_V1.h>


Variables
---------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_String
      - The password string characters.
      

Remarks
-------
* The password string buffer is allocated statically.
* The static string buffer size is defined by :doc:`../../../../../../Macros/libmrhevdata_Directory/Version/1/MRH_EvPassword_V1/MRH_EVD_P_STRING_BUFFER_MAX_TERMINATED`.