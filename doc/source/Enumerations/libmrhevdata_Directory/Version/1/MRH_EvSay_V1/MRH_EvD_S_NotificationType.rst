MRH_EvD_S_NotificationType
==========================
The MRH_EvD_S_NotificationType enumeration lists all possible 
speech output notification types.

Header
------
The enumeration definition can be found in the following file:

.. code-block:: c

    #include <libmrhevData/Version/1/MRH_EvSay_V1.h>


Definition
----------
The defined enumeration values are as follows:

.. code-block:: c

	typedef enum
	{
	    MRH_EVD_S_NOTIFICATION_DEFAULT = 0,
        
	    MRH_EVD_S_NOTIFICATION_TYPE_MAX = MRH_EVD_S_NOTIFICATION_DEFAULT,
        
	    MRH_EVD_S_NOTIFICATION_TYPE_COUNT = MRH_EVD_S_NOTIFICATION_TYPE_MAX + 1
        
	}MRH_EvD_S_NotificationType;


Values
------
The meaning behind the enumeration values is as follows:

.. list-table::
    :header-rows: 1

    * - Enumeration
      - Description
    * - MRH_EVD_S_NOTIFICATION_DEFAULT
      - A default notification with standard text.
    * - MRH_EVD_S_NOTIFICATION_TYPE_MAX
      - The highest value in this enumeration.
    * - MRH_EVD_S_NOTIFICATION_TYPE_COUNT
      - The amount of values in this enumeration.