MRH_EvD_S_Notification_U_t
==========================
The MRH_EvD_S_Notification_U_t struct represents the data for a 
say notification event representing a notification to send.

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
    * - u8_Type
      - The notification type.
    * - p_String
      - The notification string characters.
      

Remarks
-------
* The notification type is dependent on the service 
  which handles the event.
* The string buffer is allocated statically.
* The static string buffer size is defined by :doc:`../../../../../../Macros/libmrhevdata_Directory/Version/1/MRH_EvSay_V1/MRH_EVD_S_NOTIFICATION_BUFFER_MAX_TERMINATED`.