MRH_EvD_Base_Result
===================
The MRH_EvD_Base_Result enumeration is describes the default 
results used by events.

Header
------
The enumeration definition can be found in the following file:

.. code-block:: c

    #include <libmrhevData/Version/MRH_EvBase.h>


Definition
----------
The defined enumeration values are as follows:

.. code-block:: c

	typedef enum
	{
	    MRH_EVD_BASE_RESULT_SUCCESS = 0,
	    MRH_EVD_BASE_RESULT_FAILED = 1,
        
	    MRH_EVD_BASE_RESULT_MAX = MRH_EVD_BASE_RESULT_FAILED,
        
	    MRH_EVD_BASE_RESULT_COUNT = MRH_EVD_BASE_RESULT_MAX + 1
        
	}MRH_EvD_Base_Result;


Values
------
The meaning behind the enumeration values is as follows:

.. list-table::
    :header-rows: 1

    * - Enumeration
      - Description
    * - MRH_EVD_BASE_RESULT_SUCCESS
      - Success result.
    * - MRH_EVD_BASE_RESULT_FAILED
      - Failed or invalid result.
    * - MRH_EVD_BASE_RESULT_MAX
      - The highest value in this enumeration.
    * - MRH_EVD_BASE_RESULT_COUNT
      - The amount of values in this enumeration.