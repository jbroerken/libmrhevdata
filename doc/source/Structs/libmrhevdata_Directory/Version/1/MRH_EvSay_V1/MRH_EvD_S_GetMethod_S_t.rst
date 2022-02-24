MRH_EvD_S_GetMethod_S_t
=======================
The MRH_EvD_S_GetMethod_S_t struct represents the data 
for a ouput source event from platform services.

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
    * - u8_Result
      - If the output method was able to be recieved.
    * - u8_Method
      - The speech method in use.


Remarks
-------
* The result is defined by :doc:`../../../../../../Enumerations/libmrhevdata_Directory/Version/MRH_EvBase/MRH_EvD_Base_Result`.
* The method is defined by :doc:`../../../../../../Enumerations/libmrhevdata_Directory/Version/1/MRH_EvSay_V1/MRH_EvD_S_SpeechMethod`.
