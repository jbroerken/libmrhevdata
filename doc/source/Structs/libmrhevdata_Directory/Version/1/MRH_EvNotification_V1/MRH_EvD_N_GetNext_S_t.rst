MRH_EvD_N_GetNext_S_t
=====================
The MRH_EvD_N_GetNext_S_t struct represents the data for a 
event containing the next requested available notification.

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
    * - u8_Result
      - If a notification was revieced or not.
    * - p_String
      - The notification message string.
      

Remarks
-------
* The password string buffer is allocated statically.
* The static string buffer size is defined by :doc:`../../../../../../Macros/libmrhevdata_Directory/Version/1/MRH_EvNotification_V1/MRH_EVD_N_STRING_GET_BUFFER_MAX_TERMINATED`.
* The result is defined by :doc:`../../../../../../Enumerations/libmrhevdata_Directory/Version/MRH_EvBase/MRH_EvD_Base_Result`.