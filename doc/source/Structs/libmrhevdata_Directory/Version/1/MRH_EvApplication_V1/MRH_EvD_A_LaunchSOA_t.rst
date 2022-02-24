MRH_EvD_A_LaunchSOA_t
=====================
The MRH_EvD_A_LaunchSOA_t struct represents the data for a 
sent and recieved launch event.

Header
------
The struct definition can be found in the following file:

.. code-block:: c

    #include <libmrhevdata/Version/1/MRH_EvApplication_V1.h>


Variables
---------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_PackagePath
      - The full launch package path.
    * - p_LaunchInput
      - The full used launch input.
    * - s32_LaunchCommandID
      - The used launch command id.
      

Remarks
-------
* The string buffers are allocated statically.
* The static string buffer size is defined by :doc:`../../../../../../Macros/libmrhevdata_Directory/Version/1/MRH_EvApplication_V1/MRH_EVD_A_STRING_LAUNCH_BUFFER_MAX_TERMINATED`.
* The combined string sizes are greater than the total event size. Both strings 
  combined have to match the event size limit.