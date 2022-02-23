MRH_EvD_L_SpeechMethod
======================
The MRH_EvD_L_SpeechMethod enumeration lists all possible 
speech input methods.

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
	    MRH_EVD_L_SPEECH_LOCAL = 0,
	    MRH_EVD_L_SPEECH_REMOTE = 1,
        
	    MRH_EVD_L_SPEECH_METHOD_MAX = MRH_EVD_L_SPEECH_REMOTE,
        
	    MRH_EVD_L_SPEECH_METHOD_COUNT = MRH_EVD_L_SPEECH_METHOD_MAX + 1
        
	}MRH_EvD_L_SpeechMethod;


Values
------
The meaning behind the enumeration values is as follows:

.. list-table::
    :header-rows: 1

    * - Enumeration
      - Description
    * - MRH_EVD_L_SPEECH_LOCAL
      - The speech input comes from a local source.
    * - MRH_EVD_L_SPEECH_REMOTE
      - The speech input comes from a remote source.
    * - MRH_EVD_L_SPEECH_METHOD_MAX
      - The highest value in this enumeration.
    * - MRH_EVD_L_SPEECH_METHOD_COUNT
      - The amount of values in this enumeration.