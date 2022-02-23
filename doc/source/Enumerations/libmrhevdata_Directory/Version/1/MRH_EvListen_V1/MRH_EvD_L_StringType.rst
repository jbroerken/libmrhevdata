MRH_EvD_L_StringType
====================
The MRH_EvD_L_StringType enumeration lists all possible types of 
string given by a listen string event.

Header
------
The enumeration definition can be found in the following file:

.. code-block:: c

    #include <libmrhevData/Version/1/MRH_EvListen_V1.h>


Definition
----------
The defined enumeration values are as follows:

.. code-block:: c

	typedef enum
	{
	    MRH_EVD_L_STRING_UNFINISHED = 0,
	    MRH_EVD_L_STRING_END = 1,
        
	    MRH_EVD_L_STRING_TYPE_MAX = MRH_EVD_L_STRING_END,
        
	    MRH_EVD_L_STRING_TYPE_COUNT = MRH_EVD_L_STRING_TYPE_MAX + 1
        
	}MRH_EvD_L_StringType;


Values
------
The meaning behind the enumeration values is as follows:

.. list-table::
    :header-rows: 1

    * - Enumeration
      - Description
    * - MRH_EVD_L_STRING_UNFINISHED
      - The string part is not the end.
    * - MRH_EVD_L_STRING_END
      - This part represents the end of the full string.
    * - MRH_EVD_L_STRING_TYPE_MAX
      - The highest value in this enumeration.
    * - MRH_EVD_L_STRING_TYPE_COUNT
      - The amount of values in this enumeration.