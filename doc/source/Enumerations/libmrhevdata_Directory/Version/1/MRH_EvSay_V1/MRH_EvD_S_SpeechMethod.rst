MRH_EvD_S_SpeechMethod
======================
The MRH_EvD_S_SpeechMethod enumeration lists all possible 
speech output methods.

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
	    MRH_EVD_S_SPEECH_AUDIO = 0,
	    MRH_EVD_S_SPEECH_TEXT_STRING = 1,
        
	    MRH_EVD_S_SPEECH_METHOD_MAX = MRH_EVD_S_SPEECH_TEXT_STRING,
        
	    MRH_EVD_S_SPEECH_METHOD_COUNT = MRH_EVD_S_SPEECH_METHOD_MAX + 1
        
	}MRH_EvD_S_SpeechMethod;


Values
------
The meaning behind the enumeration values is as follows:

.. list-table::
    :header-rows: 1

    * - Enumeration
      - Description
    * - MRH_EVD_S_SPEECH_AUDIO
      - The speech output is performed as a audio buffer.
    * - MRH_EVD_S_SPEECH_TEXT_STRING
      - The speech output is performed as a text string.
    * - MRH_EVD_S_SPEECH_METHOD_MAX
      - The highest value in this enumeration.
    * - MRH_EVD_S_SPEECH_METHOD_COUNT
      - The amount of values in this enumeration.