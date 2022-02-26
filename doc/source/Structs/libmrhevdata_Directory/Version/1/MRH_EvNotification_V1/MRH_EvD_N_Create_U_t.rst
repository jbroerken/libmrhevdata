MRH_EvD_N_Create_U_t
====================
The MRH_EvD_N_Create_U_t struct represents the data for a 
event containing a notification create request.

Header
------
The struct definition can be found in the following file:

.. code-block:: c

    #include <libmrhevdata/Version/1/MRH_EvNotification_V1.h>


Variables
---------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - u64_TriggerTimepointS
      - The time point in seconds when the notification becomes 
        available.
    * - p_String
      - The notification message string.
      

Remarks
-------
* The password string buffer is allocated statically.
* The static string buffer size is defined by :doc:`../../../../../../Macros/libmrhevdata_Directory/Version/1/MRH_EvNotification_V1/MRH_EVD_N_STRING_CREATE_BUFFER_MAX_TERMINATED`.